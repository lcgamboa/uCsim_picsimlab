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

#ifndef SSTM8_LIB_H
#define SSTM8_LIB_H

#include "globals.h"

#ifdef __cplusplus
extern "C" {
#endif
cl_sim * sstm8_init(cl_app * app );
void sstm8_reset (void);
void sstm8_init_hw(void);
void sstm8_set_pin(unsigned char port, unsigned char pin, unsigned char value);
unsigned char sstm8_get_pin(unsigned char port, unsigned char pin);   
unsigned short sstm8_get_port(unsigned char port); //return port dir and value 
#ifdef __cplusplus
}
#endif

#endif /* SSTM8_LIB_H */

