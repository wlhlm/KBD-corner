/*
Copyright 2012-2018 Jun Wako, Jack Humbert, Yiancar
Copyright 2019 Evy Dekkers
Copyright 2022 Wilhelm Schuster

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "matrix.h"
#include "gpio.h"

static const pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static const pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

static const pin_t mux_addr_pins[] = MATRIX_COL_MUX_ADDRESS_PINS;
static const pin_t mux_enable_pins[] = MATRIX_COL_MUX_ENABLE_PINS;

/* Cols 0 - 16
 * These columns are connected to two 74HC237D 3 to 8 bit demultiplexers. Both
 * share the address pins PF0, PF1, and PC7. The enable pins PC6 and PB6 allow
 * switching between them. Column 16 is directly connected to PB5.
 *
 * silkscreen id:                U1   U2
 * col / pin:     PC7  PF1  PF0  PC6  PB6  PB5
 * 0:              0 ── 0 ── 0    1 ── 0    0
 * 1:              0 ── 0 ── 1    1 ── 0    0
 * 2:              0 ── 1 ── 0    1 ── 0    0
 * 3:              0 ── 1 ── 1    1 ── 0    0
 * 4:              1 ── 0 ── 0    1 ── 0    0
 * 5:              1 ── 0 ── 1    1 ── 0    0
 * 6:              1 ── 1 ── 0    1 ── 0    0
 * 7:              1 ── 1 ── 1    1 ── 0    0
 * 8:              0 ── 0 ── 0    0 ── 1    0
 * 9:              0 ── 0 ── 1    0 ── 1    0
 *10:              0 ── 1 ── 0    0 ── 1    0
 *11:              0 ── 1 ── 1    0 ── 1    0
 *12:              1 ── 0 ── 0    0 ── 1    0
 *13:              1 ── 0 ── 1    0 ── 1    0
 *14:              1 ── 1 ── 1    0 ── 1    0
 *15:              1 ── 1 ── 0    0 ── 1    0
 *16:              0 ── 0 ── 0    0 ── 0    1
 *
 * And then there is Backspace which lives outside of the physical switch matrix
 * directly connecting PE2 to GND. This is handled in read_rows_on_col().
 */

static void select_col(uint8_t col) {
    if (col < 16) {
        /* This turns the 4th bit of col into either 01 or 10 so that we can
         * easily check using bitwise AND. */
        uint8_t c = col + 8;

        writePin(mux_addr_pins[0],   c & 0b00000001); // A0
        writePin(mux_addr_pins[1],   c & 0b00000010); // A1
        writePin(mux_addr_pins[2],   c & 0b00000100); // A2
        writePin(mux_enable_pins[0], c & 0b00001000); // U1
        writePin(mux_enable_pins[1], c & 0b00010000); // U2
    } else {
        writePinHigh(col_pins[col]);
    }
}

static void unselect_cols(void) {
    // demultiplexer pins
    writePinLow(mux_addr_pins[0]);
    writePinLow(mux_addr_pins[1]);
    writePinLow(mux_addr_pins[2]);

    writePinLow(mux_enable_pins[1]);
    writePinLow(mux_enable_pins[0]);

    writePinLow(col_pins[16]);
}

static void init_pins(void) {
    // demultiplexer pins
    setPinOutput(mux_addr_pins[0]);
    setPinOutput(mux_addr_pins[1]);
    setPinOutput(mux_addr_pins[2]);

    setPinOutput(mux_enable_pins[0]);
    setPinOutput(mux_enable_pins[1]);

    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        setPinInputHigh(row_pins[x]);
    }
    setPinOutput(col_pins[16]);

    setPinInputHigh(BACKSPACE_PIN);

    unselect_cols();
}

static bool read_rows_on_col(matrix_row_t current_matrix[], uint8_t current_col) {
    bool matrix_changed = false;
    bool key_pressed = false;

    select_col(current_col);
    matrix_output_select_delay();

    for (uint8_t row_index = 0; row_index < MATRIX_ROWS; row_index++) {
        // store last value of row prior to reading
        matrix_row_t last_row_value = current_matrix[row_index];

        // check row pin state
        uint8_t read_result;
        // Backspace special case
        if (current_col == BACKSPACE_MATRIX_COL && row_index == BACKSPACE_MATRIX_ROW) {
            read_result = !readPin(BACKSPACE_PIN);
        } else {
            read_result = readPin(row_pins[row_index]);
        }

        if (read_result) {
            // pin HI, set col bit
            current_matrix[row_index] |= (MATRIX_ROW_SHIFTER << current_col);
            key_pressed = true;
        } else {
            // pin LO, clear col bit
            current_matrix[row_index] &= ~(MATRIX_ROW_SHIFTER << current_col);
        }

        // determine if the matrix changed state
        if ((last_row_value != current_matrix[row_index]) && !(matrix_changed)) {
            matrix_changed = true;
        }
    }

    unselect_cols();
    matrix_output_unselect_delay(current_col, key_pressed);

    return matrix_changed;
}

void matrix_init_custom(void) {
    init_pins();
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    bool changed = false;

    for (uint8_t current_col = 0; current_col < MATRIX_COLS; current_col++) {
        changed |= read_rows_on_col(current_matrix, current_col);
    }

    return changed;
}

