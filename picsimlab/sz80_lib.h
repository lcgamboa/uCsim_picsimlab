/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sz80_lib.h
 * Author: gamboa
 *
 * Created on 29 de Julho de 2020, 20:35
 */

#ifndef SZ80_LIB_H
#define SZ80_LIB_H

#include "globals.h"

#ifdef __cplusplus
extern "C" {
#endif
cl_sim * sz80_init(cl_app * app );
void sz80_init_hw(cl_sim * sim);
void sz80_set_pin(unsigned char port, unsigned char pin, unsigned char value);
unsigned char sz80_get_pin(unsigned char port, unsigned char pin);   
unsigned char sz80_get_port(unsigned char port);  
#ifdef __cplusplus
}
#endif

#endif /* SZ80_LIB_H */

