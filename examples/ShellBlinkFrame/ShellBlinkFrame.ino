/**
 * @file ShellBlinkFrame.ino
 * @version 1.0
 *
 * @section License
 * Copyright (C) 2016, Mikael Patel
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * @section Description
 * This Arduino sketch shows how to use the Shell library to
 * implement the classical blink sketch as a script using parameter
 * frame and element access.
 */

#include <Shell.h>

Shell<16,16> shell(Serial);

void setup()
{
  Serial.begin(57600);
  while (!Serial);
  Serial.println(F("ShellBlinkFrame: started"));
  shell.trace(true);

  // : blink ( ms pin -- )
  //   pin output
  //   {
  //      pin high ms delay
  //      pin low ms delay
  //      true
  //   } while ;
  shell.set(F("blink"), F("2\\2$@O{2$@H1$@D2$@L1$@DT}w"));

  // 1000 13 blink
  shell.execute(F("1000,13`blink"));
}

void loop()
{
}
