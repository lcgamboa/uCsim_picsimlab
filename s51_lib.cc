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

// prj
#include "globals.h"

// sim.src
//#include "appcl.h"

// local
#include "sim51cl.h"

#include "s51.src/portcl.h"

#include "s51_lib.h"

/*
 * Main function of the Simulator of MCS51. Everything starts here.
 */


static class cl_sim *sim;

static cl_port * p[4];


int
s51_init(const char * fname)
{
 int retval;
 int i;
 int argc =7;
 
char **argv  = new char *[8];
 
argv[0] = new char[20]; 
argv[1] = new char[200]; 
argv[2] = new char[20]; 
argv[3] = new char[20]; 
argv[4] = new char[20]; 
argv[5] = new char[20]; 
argv[6] = new char[20]; 

 strcpy(argv[0],"./s51"); 
 strcpy(argv[1],fname);
 strcpy(argv[2],"-s"); 
 strcpy(argv[3],"/dev/tnt2"); 
 strcpy(argv[4],"-X8M"); 
 strcpy(argv[5],"-g"); 
 strcpy(argv[6],"-P");
  
 cpus = cpus_51;
 application = new cl_app ();
 application->set_name ("s51");
 application->init (argc, argv);
 sim = new cl_sim51 (application);
 if (sim->init ())
  sim->state |= SIM_QUIT;
 application->set_simulator (sim);

 sim->state|= SIM_QUIT; //fake out
 retval = application->run ();
 sim->state &= ~SIM_QUIT;
 
 for(i=0; i < argc; i++)
  {
   delete argv[i];
  }
 delete argv;
 int idx=0;
 p[0]= (cl_port*) sim->uc->get_hw(HW_PORT, &idx); // last param is the port number
 idx++;
 p[1]= (cl_port*) sim->uc->get_hw(HW_PORT, &idx);
 idx++;
 p[2]= (cl_port*) sim->uc->get_hw(HW_PORT, &idx); 
 idx++;
 p[3]= (cl_port*) sim->uc->get_hw(HW_PORT, &idx); 


 
 return retval;
}

 static double input_last_checked = 0;
 static unsigned int cyc = 0;

void
s51_step(void)
  {
   //serial stuff
   if (cyc - input_last_checked > 10000)
    {
     input_last_checked = cyc;
     if (sim->uc)
      sim->uc->touch ();
     if (application->commander->input_avail ())
      application->commander->proc_input ();
    }
   
   sim->step ();
      
   ++cyc;
  }

void
s51_set_port(unsigned char port, unsigned char value)
{
 // p[port]->set_pin (value);
  
 switch(port)
  {
     case 0: return sim->uc->write_mem("port_0_cfg", 1,value);break;
     case 1: return sim->uc->write_mem("port_1_cfg", 1,value);break;
     case 2: return sim->uc->write_mem("port_2_cfg", 1,value);break;
     case 3: return sim->uc->write_mem("port_3_cfg", 1,value);break;
  }  
     //sim->uc->write_mem("port_0_cfg", 1, 0x5a);
}

unsigned char
s51_get_port(unsigned char port)
{   
 //return p[port]->cell_p->read ();
 
 switch(port)
  {
     case 0: return sim->uc->read_mem("port_0_cfg", 2);break;
     case 1: return sim->uc->read_mem("port_1_cfg", 2);break;
     case 2: return sim->uc->read_mem("port_2_cfg", 2);break;
     case 3: return sim->uc->read_mem("port_3_cfg", 2);break;
  }  
 return 0;
}


/*
 application->done ();
 delete application;

 return (retval);
}
*/
/* End of s51.src/s51.cc */
