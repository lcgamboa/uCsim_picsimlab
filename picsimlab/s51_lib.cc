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
#include "../s51.src/sim51cl.h"
#include "../s51.src/portcl.h"



#include "s51_lib.h"

static cl_port * p[4];

cl_sim * 
s51_init(cl_app * app )
{
   return new cl_sim51 (app);
}


 void s51_init_hw(cl_sim * sim)
 {
 int idx = 0;
 p[0] = (cl_port*) sim->uc->get_hw (HW_PORT, &idx); // last param is the port number
 idx++;
 p[1] = (cl_port*) sim->uc->get_hw (HW_PORT, &idx);
 idx++;
 p[2] = (cl_port*) sim->uc->get_hw (HW_PORT, &idx);
 idx++;
 p[3] = (cl_port*) sim->uc->get_hw (HW_PORT, &idx);
}


void
s51_set_pin(unsigned char port, unsigned char pin, unsigned char value)
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

 p[port]->set_pin (val);

}

unsigned char
s51_get_pin(unsigned char port, unsigned char pin)
{
 /*
  unsigned char a[3];

  a[0] = p[port]->cell_p->get (); //Value in SFR register
  a[1] = p[port]->port_pins; //Output of outside circuits
  a[2] = p[port]->cell_p->read (); //Value on the port pins
  */

 return ((p[port]->cell_p->read () & (1 << pin)) > 0);

 /*
 switch(port)
  {
     case 0: return sim->uc->read_mem("port_0_cfg", 2);break;
     case 1: return sim->uc->read_mem("port_1_cfg", 2);break;
     case 2: return sim->uc->read_mem("port_2_cfg", 2);break;
     case 3: return sim->uc->read_mem("port_3_cfg", 2);break;
  }  
 return 0;
  */
}

unsigned char
s51_get_port(unsigned char port)
{
 return p[port]->cell_p->read ();
}
