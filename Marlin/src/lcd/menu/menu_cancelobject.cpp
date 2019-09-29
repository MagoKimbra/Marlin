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
// Cancel Object Menu
//

#include "../../inc/MarlinConfigPre.h"

#if HAS_LCD_MENU && ENABLED(CANCEL_OBJECTS)

#include "menu.h"

#include "../../feature/cancelobject.h"

inline void _lcd_cancel_cb() { 
  if (lcd_cancel > -1) {
     cancel_object(uint16_t(lcd_cancel));
     lcd_cancel = -1;
  }
}

void menu_cancelobject() {
  
  START_MENU();
  MENU_MULTIPLIER_ITEM_EDIT_CALLBACK(int3, MSG_OBJECT_CANCEL, &lcd_cancel, -1, MAXOBJECTS, _lcd_cancel_cb);
  MENU_BACK(MSG_MAIN);

  END_MENU();
}

#endif // HAS_LCD_MENU && CANCEL_OBJECTS