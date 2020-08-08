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


#include "ucsimlib.h"
#include "s51_lib.h"
#include "sz80_lib.h"
#include "sstm8_lib.h"

/*
 * Main function of the Simulator of MCS51. Everything starts here.
 */


static class cl_sim *sim;


typedef enum {SNONE=0,S51,SSTM8,SZ80} sim_type;    


static sim_type Type;

#define NARGS 7

static int write_hex(unsigned char * mem, int size, const char * fname);

int
ucsim_init(const char * cpu, const char * freq, const char * fname, const char * serial, unsigned short dport)
{
 int retval;
 int i;
 int argc = NARGS;

 Type = SNONE;

 int c[3] = {0, 0, 0};

 do
  {

   if (cpus_z80[c[0]].type_str != NULL)
    {
     if (!strcmp (cpus_z80[c[0]].type_str, cpu))
      {
       Type = SZ80;
       break;
      }
     c[0]++;
    }
   if (cpus_stm8[c[1]].type_str != NULL)
    {
     if (!strcmp (cpus_stm8[c[1]].type_str, cpu))
      {
       Type = SSTM8;
       break;
      }
     c[1]++;
    }
   if (cpus_51[c[2]].type_str != NULL)
    {
     if (!strcmp (cpus_51[c[2]].type_str, cpu))
      {
       Type = S51;
       break;
      }
     c[2]++;
    }

   if ((cpus_z80[c[0]].type_str == NULL)&&(cpus_stm8[c[1]].type_str == NULL)&&(cpus_51[c[2]].type_str == NULL))
    {
     printf ("Unknown processor!\n");
     return -1;
    }
  }
 while (!Type);


  char **argv = new char *[NARGS + 1];

 for (i = 0; i < NARGS; i++)
  {
   argv[i] = new char[200];
  }

 strcpy (argv[0], "./s51");
 sprintf (argv[1], "-t%s", cpu);
 sprintf (argv[2], "-s%s", serial);
 sprintf (argv[3], "-X%s", freq);
 strcpy (argv[4], "-g");
 sprintf (argv[5], "-Z%i",dport);
 strcpy (argv[6], fname);
 
 
 optind = 1;

 switch (Type)
  {
  case SZ80:
   cpus = cpus_z80;
   break;
  case SSTM8:
   cpus = cpus_stm8;
   break;
  case S51:
   cpus = cpus_51;
   break;
  }
 application = new cl_app ();
 application->set_name ("picsimlab");
 application->init (argc, argv);

 switch (Type)
  {
  case SZ80:
   sim = sz80_init (application);
   break;
  case SSTM8:
   sim = sstm8_init (application);
   break;
  case S51:
   sim = s51_init (application);
   break;
  }

 if (sim->init ())
  sim->state |= SIM_QUIT;
 application->set_simulator (sim);

 sim->state |= SIM_QUIT; //fake out
 retval = application->run ();
 sim->state &= ~SIM_QUIT;

 for (i = 0; i < argc; i++)
  {
    delete[] argv[i];
  }
 delete[] argv;


 switch (Type)
  {

  case SZ80:
   sz80_init_hw (sim);
   break;
  case SSTM8:
   sstm8_init_hw (sim);
   break;
  case S51:
   s51_init_hw (sim);
   break;
  }
 return retval;
}

void
ucsim_set_pin(unsigned char port, unsigned char pin, unsigned char value)
{
 switch (Type)
  {

  case SZ80:
   sz80_set_pin (port, pin, value);
   break;
  case SSTM8:
   sstm8_set_pin (port, pin, value);
   break;
  case S51:
   s51_set_pin (port, pin, value);
   break;
  }
}

unsigned char
ucsim_get_pin(unsigned char port, unsigned char pin)
{
 switch (Type)
  {

  case SZ80:
   return sz80_get_pin (port, pin);
   break;
  case SSTM8:
   return sstm8_get_pin (port, pin);
   break;
  case S51:
   return s51_get_pin (port, pin);
   break;
  }
 return 0;
}

unsigned char
ucsim_get_port(unsigned char port)
{
 switch (Type)
  {

  case SZ80:
   return sz80_get_port (port);
   break;
  case SSTM8:
   return sstm8_get_port (port);
   break;
  case S51:
   return s51_get_port (port);
   break;
  }
 return 0;
}

void
ucsim_end(void)
{

 application->done ();
 delete application;
}

static double input_last_checked = 0;
static unsigned int cyc = 0;

void
ucsim_step(void)
{
 /*
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
  */

 ++cyc;

 if (sim->state & SIM_GO)
  {
   if (cyc - input_last_checked > 10000)
    {
     input_last_checked = cyc;
     if (sim->uc)
      sim->uc->touch ();
     if (application->commander->input_avail ())
      application->commander->proc_input ();
    }
   sim->step ();
   if (jaj && application->commander->frozen_console)
    {
     sim->uc->print_regs (application->commander->frozen_console),
         application->commander->frozen_console->dd_printf ("\n");
    }
  }
 else
  {
   if (application->commander->input_avail ())
    application->commander->proc_input ();
   //else
   // loop_delay ();

   if (sim->uc)
    sim->uc->touch ();
  }

 application->commander->check ();
}

void
ucsim_reset(void)
{

 sim->uc->reset ();
}

int
ucsim_dump(const char * fname)
{
 unsigned int size = sim->uc->rom->get_size ();
 unsigned char * rom;

 rom = new unsigned char[size];


 for (int i = 0; i < size; i++)
  {

   rom[i] = sim->uc->rom->read (i);
  }

 int ret = write_hex (rom, size, fname);

 delete[] rom;

 return ret;
}

static int
write_hex(unsigned char * mem, int size, const char * fname)
{

 FILE * fout;
 unsigned char sum;
 unsigned char nb;
 unsigned int iaddr = 0;
 unsigned int i;
 char values[100];
 char tmp[200];

 fout = fopen (fname, "w");

 if (fout)
  {
   //program memory  
   nb = 0;
   sum = 0;
   for (i = 0; i < size; i++)
    {
     if (i == 0x10000)fprintf (fout, ":020000040001F9\n");
     if (i == 0x20000)fprintf (fout, ":020000040002F8\n");
     if (i == 0x30000)fprintf (fout, ":020000040003F7\n");

     if (nb == 0)
      {
       iaddr = i & 0xFFFF;
       snprintf (values, 99, "%02X", mem[i]);
      }
     else
      {
       snprintf (tmp, 199, "%s%02X", values, mem[i]);
       strcpy (values, tmp);
      }

     nb++;
     sum += mem[i];

     if (nb == 16)
      {
       sum += nb;
       sum += (iaddr & 0x00FF);
       sum += ((iaddr & 0xFF00) >> 8);
       //printf("sum=%02X %02X %02X\n",sum,~sum,(~sum)+1);
       sum = (~sum) + 1;
       fprintf (fout, ":%02X%04X00%s%02X\n", nb, iaddr, values, sum);
       nb = 0;
       sum = 0;
      }
    }
   if (nb)
    {
     sum += nb;
     sum += (iaddr & 0x00FF);
     sum += ((iaddr & 0xFF00) >> 8);
     sum = (~sum) + 1;
     fprintf (fout, ":%02X%04X00%s%02X\n", nb, iaddr, values, sum);
    }
   //end
   fprintf (fout, ":00000001FF\n");
   fclose (fout);
   return 0; //no error
  }
 else
  {
   printf ("ERRO: File not found!(%s)\n", fname);
   return -1;
  }
 return 0; //no error
}
