/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   common.h
 * Author: medhat
 *
 * Created on 22. Juli 2018, 09:11
 */

#ifndef COMMON_H
#define COMMON_H

#ifdef __cplusplus
extern "C" {
#endif

#define LINE_LENGTH 30
void DispalyLine(unsigned char L = LINE_LENGTH);
void DispalySection(std::string S = "Default");


#ifdef __cplusplus
}
#endif

#endif /* COMMON_H */

