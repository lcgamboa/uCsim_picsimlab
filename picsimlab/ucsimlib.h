/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   UCSIM_lib.h
 * Author: gamboa
 *
 * Created on 29 de Julho de 2020, 20:35
 */

#ifndef UCSIM_LIB_H
#define UCSIM_LIB_H

#ifdef __cplusplus
extern "C" {
#endif
    
int ucsim_init(const char * cpu, const char * freq, const char * fname, const char * serial, unsigned short dport);
void ucsim_end(void);
void ucsim_step(void);
void ucsim_set_pin(unsigned char port, unsigned char pin, unsigned char value);
unsigned char ucsim_get_pin(unsigned char port, unsigned char pin);   
unsigned char ucsim_get_port(unsigned char port);  
void ucsim_reset(void);
int  ucsim_dump(const char * fname);
#ifdef __cplusplus
}
#endif

#endif /* UCSIM_LIB_H */

