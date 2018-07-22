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
#include <iostream>
#include <typeinfo>
#ifdef __cplusplus
extern "C" {
#endif
using namespace std;
    
#define LINE_LENGTH 30
#define MEMORY_SIZE 10
    
void DispalyLine(char c='-', unsigned char L = LINE_LENGTH);
void DispalySection(std::string S = "Default");
void vidDump(uint8_t* Array, uint8_t u8Size=MEMORY_SIZE);


#ifdef __cplusplus
}
#endif

template <typename  T>
void DisplayVariable(T X){
    cout<<typeid(T).name()<<endl;
    std::cout<<"Size: "<< X.size()<<std::endl;
    for(typename T::iterator p = X.begin(); p!=X.end(); p++)
        cout<<std::hex<<*p<<'\t';
    
    cout<<endl;
    
}




#endif /* COMMON_H */

