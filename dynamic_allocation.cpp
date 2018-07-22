/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
//#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include <iostream>

#include "common.h"

typedef unsigned char uint8;

namespace dynamic_allocation{


    
 
void vidTest(){

uint8* pu81, *pu81_1;
uint8* pu82;

pu81 = new uint8[MEMORY_SIZE]();
pu81_1 = new uint8 [MEMORY_SIZE];
pu82 = (uint8*)malloc(MEMORY_SIZE);
vidDump(pu81_1, MEMORY_SIZE);
vidDump(pu81, MEMORY_SIZE);
vidDump(pu82, MEMORY_SIZE);


delete[] pu81, pu81_1;
std::free(pu82);

}

void main(){
    DispalySection("Dynamic ALLOCATION");
    vidTest();
}
}
