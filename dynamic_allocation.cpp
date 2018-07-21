/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
typedef unsigned char uint8;

namespace dynamic_allocation{

#define MEMORY_SIZE 10
    
void vidDump(uint8* Array, uint8 u8Size){
    std::cout<<"Address: "<<std::hex<<(long int)Array<<std::endl;
    for(int i=0; i< MEMORY_SIZE; i++)std::cout<<(int)Array[i]<<'\t';
    std::cout<<std::endl;
}    
void vidTest(){

uint8* pu81;
uint8* pu82;

pu81 = new uint8[MEMORY_SIZE];
pu82 = (uint8*)malloc(MEMORY_SIZE);
vidDump(pu81, MEMORY_SIZE);
vidDump(pu82, MEMORY_SIZE);


delete pu81;
std::free(pu82);

}

void main(){
    vidTest();
}
}
