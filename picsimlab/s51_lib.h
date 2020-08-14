/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   s51_lib.h
 * Author: gamboa
 *
 * Created on 29 de Julho de 2020, 20:35
 */

#ifndef S51_LIB_H
#define S51_LIB_H

#include "globals.h"

#ifdef __cplusplus
extern "C" {
#endif
cl_sim * s51_init(cl_app * app );
void s51_reset (void);
void s51_init_hw(void);
void s51_set_pin(unsigned char port, unsigned char pin, unsigned char value);
unsigned char s51_get_pin(unsigned char port, unsigned char pin);   
unsigned short s51_get_port(unsigned char port);//return port dir and value  
#ifdef __cplusplus
}
#endif

#endif /* S51_LIB_H */

