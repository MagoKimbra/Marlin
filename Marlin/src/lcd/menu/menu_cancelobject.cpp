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

//
// Backlash Menu
//

#include "../../inc/MarlinConfigPre.h"

#if HAS_LCD_MENU && ENABLED(CANCEL_OBJECTS)

#include "menu.h"

#include "../../feature/cancelobject.h"
//Just hardcoding these in for now, need to get the list from the feature and only add those that are active.
void menu_cancelobject() {
  START_MENU();
  MENU_BACK(MSG_MAIN);
  PGM_P msg0 = PSTR("Object 0");
  MENU_ITEM_P(gcode, msg0, PSTR("O5 I0"));
  PGM_P msg1 = PSTR("Object 1");
  MENU_ITEM_P(gcode, msg1, PSTR("O5 I1"));
  PGM_P msg2 = PSTR("Object 2");
  MENU_ITEM_P(gcode, msg2, PSTR("O5 I2"));
  PGM_P msg3 = PSTR("Object 3");
  MENU_ITEM_P(gcode, msg3, PSTR("O5 I3"));
  END_MENU();
}

#endif // HAS_LCD_MENU && CANCEL_OBJECTS