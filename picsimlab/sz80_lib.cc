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


static class cl_address_space *inputs;
static class cl_address_space *outputs;


cl_sim * 
sz80_init(cl_app * app )
{
   return new cl_simz80 (app);
}


 void sz80_init_hw(cl_sim * sim)
 {
  
  cl_z80 *z80 = (cl_z80 *)sim->uc;
  
  inputs=z80->inputs;
  outputs=z80->outputs;
}


void
sz80_set_pin(unsigned char port, unsigned char pin, unsigned char value)
{
 unsigned char val = inputs->read (port);

 if (value)
  {
   val |= (1 << pin);
  }
 else
  {
   val &= ~(1 << pin);
  }

 inputs->write (port,val);
}

unsigned char
sz80_get_pin(unsigned char port, unsigned char pin)
{
 return ((outputs->read (port) & (1 << pin)) > 0);
}

unsigned char
sz80_get_port(unsigned char port)
{
 return outputs->read (port);
}
