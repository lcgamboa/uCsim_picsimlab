/*
 * Simulator of microcontrollers (sz80.cc)
 *
 * Copyright (C) 1999,99 Drotos Daniel, Talker Bt.
 * 
 * To contact author send email to drdani@mazsola.iit.uni-miskolc.hu
 *
 */

/* This file is part of microcontroller simulator: ucsim.

UCSIM is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

UCSIM is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with UCSIM; see the file COPYING.  If not, write to the Free
Software Foundation, 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA. */
/*@1@*/

//#include "ddconfig.h"

#include <getopt.h>

// prj
#include "globals.h"

// local
#include "../z80.src/simz80cl.h"

#include "sz80_lib.h"
#include "z80.src/z80cl.h"

void sz80_set_port(unsigned char port, unsigned char value);

static cl_simz80 * sim;
static class cl_address_space *inputs;
static class cl_address_space *outputs;

class PIO_8255
{
public:
 unsigned int base_addr;
 unsigned char control;
 unsigned char control_latch;

 PIO_8255(unsigned int base_addr_)
 {
  base_addr = base_addr_;
 }

 void
 Reset()
 {
  for (int i = 0; i < 4; i++)
   {
    inputs->write (base_addr + i, 0);
    outputs->write (base_addr + i, 0);
   }
  control = 0;
  control_latch = 0;
 }

 void
 Write(unsigned char port, unsigned char value)
 {
  port &= 0x03;
  switch (port)
   {
   case 0:
    if (control & 0x10)
     {
      inputs->write (base_addr, value);
     }
    break;
   case 1:
    if (control & 0x02)
     {
      inputs->write (base_addr + 1, value);
     }
    break;
   case 2:
    switch (control)
     {
     case 0x01: //low input
      //inputs->write(base_addr+1,value);
      break;
     case 0x08://high input
      //inputs->write(base_addr+1,value);
      break;
     case 0x09://all input
      inputs->write (base_addr + 2, value);
      break;
     }
    break;
   }
 }

 unsigned short
 Read(unsigned char port)
 {
  port &= 0x03;

  switch (port)
   {
   case 0:
    if (control & 0x10)
     {
      return 0xFF00 | inputs->read (base_addr);
     }
    else
     {
     return outputs->read (base_addr);
     }
    break;
   case 1:
    if (control & 0x02)
     {
      return 0xFF00 |inputs->read (base_addr + 1);
     }
    else
     {
     return outputs->read (base_addr + 1);
     }
    break;
   case 2:
    switch (control & 0x09)
     {
     case 0x00://all output
      return outputs->read (base_addr + 2);
      break;
     case 0x01: //low input
       return 0x0F00 |(outputs->read (base_addr + 2) & 0xF0) | (inputs->read (base_addr + 2) & 0x0F);
      break;
     case 0x08://high input
       return 0xF000 |(outputs->read (base_addr + 2) & 0x0F) | (inputs->read (base_addr + 2) & 0xF0);
      break;
     case 0x09://all input
      return 0xFF00 |inputs->read (base_addr + 2);
      break;
     }
    break;
   }
  return 0;
 }

 void
 Update_Control(void)
 {
  if (outputs->read (base_addr + 3) != control_latch)
   {
    control_latch = outputs->read (base_addr + 3);
    if (control_latch & 0x80)
     {
      control = control_latch;
     }
    else //PSR mode
     {
      unsigned char bit = (0xE & control_latch) >> 1;

      unsigned char val = outputs->read (base_addr + 2);
      if (control_latch & 0x01)
       {
        val |= (1 << bit);
       }
      else
       {
        val &= ~(1 << bit);
       }
      outputs->write (base_addr + 2, val);
     }
   }
 }

};


PIO_8255 PIO1(0x00);
PIO_8255 PIO2(0x04);

cl_sim *
sz80_init(cl_app * app)
{
 sim =new cl_simz80 (app);
 return sim;
}

void
sz80_reset (void)
{
 ((cl_z80 *)sim->uc)->reset ();
 PIO1.Reset ();
 PIO2.Reset ();
}

void
sz80_init_hw(void)
{

 cl_z80 *z80 = (cl_z80 *) sim->uc;

 inputs = z80->inputs;
 outputs = z80->outputs;

 PIO1.Reset ();
 PIO2.Reset ();
}

void
sz80_updated_hw(void)
{
 PIO1.Update_Control ();
 PIO2.Update_Control ();
}

void
sz80_set_pin(unsigned char port, unsigned char pin, unsigned char value)
{
 unsigned char val = sz80_get_port (port);

 if (value)
  {
   val |= (1 << pin);
  }
 else
  {
   val &= ~(1 << pin);
  }
 sz80_set_port (port, val);
}

unsigned char
sz80_get_pin(unsigned char port, unsigned char pin)
{
 return ((sz80_get_port (port) & (1 << pin)) > 0);
}

unsigned short
sz80_get_port(unsigned char port)
{
 switch (port)
  {
  case 0:
   return PIO1.Read (0);
   break;
  case 1:
   return PIO1.Read (1);
   break;
  case 2:
   return PIO1.Read (2);
   break;
  case 3:
   return PIO2.Read (0);
   break;
  case 4:
   return PIO2.Read (1);
   break;
  case 5:
   return PIO2.Read (2);
   break;
  }
 return 0;
}

void
sz80_set_port(unsigned char port, unsigned char value)
{
 switch (port)
  {
  case 0:
   return PIO1.Write (0, value);
   break;
  case 1:
   return PIO1.Write (1, value);
   break;
  case 2:
   return PIO1.Write (2, value);
   break;
  case 3:
   return PIO2.Write (0, value);
   break;
  case 4:
   return PIO2.Write (1, value);
   break;
  case 5:
   return PIO2.Write (2, value);
   break;
  }
}
