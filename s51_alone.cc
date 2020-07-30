
#include <stdio.h>

#include "s51_lib.h"

int main()
{
  unsigned char val[4];
 
  s51_init("/home/gamboa/microcontroladores/8051/in_out.ihx");
  while(1)
  {
      s51_set_port(0,1);
      s51_set_port(1,2);
	  s51_set_port(2,3);
      s51_set_port(3,4);
	  
	  s51_step();
      
      val[0]=s51_get_port(0);
      val[1]=s51_get_port(1);
      val[2]=s51_get_port(2);
      val[3]=s51_get_port(3);
      
      printf("0x%02X 0x%02X 0x%02X 0x%02X\n",val[0],val[1],val[2],val[3]);
  }
}
