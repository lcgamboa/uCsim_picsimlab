/*
 * Simulator of microcontrollers (s51.cc)
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
#include "../stm8.src/simstm8cl.h"


#include "sstm8_lib.h"

#include "../stm8.src/portcl.h"

static cl_port * p[6];

cl_sim * 
sstm8_init(cl_app * app )
{
   return new cl_simstm8 (app);
}


 void sstm8_init_hw(cl_sim * sim)
 {
 int idx = 0;
 p[0] = (cl_port*) sim->uc->get_hw (HW_PORT, &idx); // last param is the port number
 idx++;
 p[1] = (cl_port*) sim->uc->get_hw (HW_PORT, &idx);
 idx++;
 p[2] = (cl_port*) sim->uc->get_hw (HW_PORT, &idx);
 idx++;
 p[3] = (cl_port*) sim->uc->get_hw (HW_PORT, &idx);
 idx++;
 p[4] = (cl_port*) sim->uc->get_hw (HW_PORT, &idx);
 idx++;
 p[5] = (cl_port*) sim->uc->get_hw (HW_PORT, &idx);
}

void
sstm8_set_pin(unsigned char port, unsigned char pin, unsigned char value)
{

 unsigned char val = p[port]->cell_p->read ();

 if (value)
  {
   val |= (1 << pin);
  }
 else
  {
   val &= ~(1 << pin);
  }

 p[port]->cell_p->write (val); //TODO verify

}

unsigned char
sstm8_get_pin(unsigned char port, unsigned char pin)
{
 return  ((p[port]->cell_p->read () & (1 << pin)) > 0);
}

unsigned char
sstm8_get_port(unsigned char port)
{
 return p[port]->cell_p->read ();
}
