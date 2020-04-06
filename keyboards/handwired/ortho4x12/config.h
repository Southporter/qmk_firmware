/*
Copyright 2020 Shem Sedrick <ssedrick1@gmail.com>

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

#pragma once

#include "config_common.h"

#define VENDOR_ID 0xFEED
#define PRODUCT_ID 0x0000
#define DEVICE_VER 0x0001
#define MANUFACTURER ssedrick
#define PRODUCT slanck
#define DESCRIPTION A handwired planck keyboard

#define MATRIX_ROWS 4
#define MATRIX_COLS 12
#define MATRIX_ROW_PINS \
    { F7, B6, B5, B4 }
/* #define MATRIX_COL_PINS \ */
    /* { F4, F1, F0, B0, B1, B2, B7, D0, D1, D2, D3, C6 } */
#define MATRIX_COL_PINS \
    { C6, D3, D2, D1, D0, B7, B2, B1, B0, F0, F1, F4 }
#define UNUSED_PINS


#define DIODE_DIRECTION COL2ROW

#define DEBOUNCE 5
