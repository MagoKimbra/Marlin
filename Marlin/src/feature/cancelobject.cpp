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
#include "../inc/MarlinConfig.h"

#if ENABLED(CANCEL_OBJECTS)
   #include "cancelobject.h"
   #include "../gcode/parser.h"
   #include "../lcd/ultralcd.h"

   static gcodeobject objectlist[MAXOBJECTS];

   //Just for now, lets set active object to MAXOBJECTS+1
   static uint8_t null_object=MAXOBJECTS+1;
   static uint8_t active_object = null_object;

   void add_new_object(uint16_t obj) {
     objectlist[obj].assigned = true;
   }
   
   void set_active_object(uint16_t obj) {
     char status[20];
     //New object identified that was not previous assigned
     if (!objectlist[obj].assigned) objectlist[obj].assigned=true;
     //reset object if not already done so
     if (active_object < MAXOBJECTS) reset_active_object(active_object);
     objectlist[obj].active = true;
     active_object = obj;
     if (objectlist[obj].cancelled) parser.skipping = true;
     sprintf_P(status, PSTR("Active Object: %i"), int(obj));
     ui.set_status(status);
   }

   void reset_active_object(uint16_t obj) {
     char status[20];
     objectlist[obj].active = false;
     active_object = null_object;
     parser.skipping = false;
     ui.set_status(status);
   }

   void cancel_object(uint16_t obj) {
     objectlist[obj].cancelled = true;
     if (obj == active_object) parser.skipping = true;
   }

   //Call this after print finished/cancelled/killed
   void clear_objects() {
     for(int i=0; i < MAXOBJECTS; i++){
       objectlist[i].assigned = false;
       objectlist[i].active = false;
       objectlist[i].cancelled = false;
     }
     active_object = null_object;
   }

   bool get_object(int16_t obj) {
      if (objectlist[obj].assigned && !objectlist[obj].cancelled) return true;
      else 
        return false;
   }

   void list_objects() {
      SERIAL_ECHO_START();
      SERIAL_ECHOLNPGM("Assigned:");
      for(int i=0; i < MAXOBJECTS; i++){
        if (objectlist[i].assigned) {
          SERIAL_ECHOLN(i);
        }
      }
      SERIAL_ECHOLNPGM("Cancelled:");
      for(int i=0; i < MAXOBJECTS; i++){
        if (objectlist[i].cancelled) {
          SERIAL_ECHOLN(i);
        }
      }
      SERIAL_ECHOLNPGM("Active Object:");
      SERIAL_ECHOLN(active_object);

   }
#endif // CANCEL_OBJECTS
