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

#ifdef __cplusplus
extern "C" {
#endif

int s51_init(const char * fname);
void s51_step(void);
void s51_set_port(unsigned char port, unsigned char value);
unsigned char s51_get_port(unsigned char port);   

#ifdef __cplusplus
}
#endif

#endif /* S51_LIB_H */

