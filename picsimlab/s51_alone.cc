
#include <stdio.h>
#include <unistd.h>
#include "ucsimlib.h"

int
main()
{
 unsigned char val[4];
 unsigned char v = 0xD1;

 //ucsim_init ("C51", "8M", "/home/gamboa/microcontroladores/sdcc_examples/8051/blink.hex", "/dev/tnt2",1234);
 //ucsim_init ("STM8S103", "8M", "/home/gamboa/microcontroladores/sdcc_examples/STM8/led.hex", "/dev/tnt2",1234);
 //ucsim_init ("Z80", "8M", "/home/gamboa/microcontroladores/sdcc_examples/Z80/led.hex", "/dev/tnt2",1234);
 ucsim_init ("Z80", "8M", "/home/gamboa/microcontroladores/z80_asm/v_scroll.hex", "/dev/tnt2",1234);

 int i; 
 while (1)
  {
   //ucsim_set_pin (0, 0, v);
   //ucsim_set_pin (1, 0, ~v);
   //ucsim_set_pin (2, 0, v);
   //ucsim_set_pin (3, 0, ~v);


   ucsim_step ();

   val[0] = ucsim_get_port (0);
   val[1] = ucsim_get_port (1);
   val[2] = ucsim_get_port (2);
   val[3] = ucsim_get_port (3);

   if(i > 10000)
   {
     i=0; 	   
     printf ("0x%02X 0x%02X 0x%02X 0x%02X\n", val[0], val[1], val[2], val[3]);
   }
   i++; 

   //usleep(1000);
  }

 ucsim_dump ("/tmp/test.hex");

 ucsim_end ();
}
