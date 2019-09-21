/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "../../../inc/MarlinConfig.h"

#if ENABLED(CANCEL_OBJECTS)

#include "../../gcode.h"
#include "../../../feature/cancelobject.h"

/**
 * O1: Add an object to a list of cancelable objects, by index
 */
void GcodeSuite::O1() {
  uint16_t obj = parser.intval('I');
  add_new_object(obj);
}

/**
 * O2: Set/unset current printing object index
 */
void GcodeSuite::O2() {
  uint16_t obj = parser.intval('I');
  uint16_t setflag = parser.intval('S');

  if (setflag >= 1) set_active_object(obj);
  if (setflag == 0) reset_active_object(obj);
}

/**
 * O3: List assigned object indexes
 */
void GcodeSuite::O3() {
  list_objects();
}

/**
 * O4: Reset object list
 */
void GcodeSuite::O4() {
  clear_objects();
}

/**
 * O5: Cancel object, by index
 */
void GcodeSuite::O5() {
  uint16_t obj = parser.intval('I');
  cancel_object(obj);
}

#endif // CANCEL_OBJECTS
