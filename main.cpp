/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: mhussain
 *
 * Created on 18. Juli 2018, 12:28
 */

#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include "externals.h"

typedef unsigned char uint8;
typedef unsigned short uint16;
#define u8Size 10


using namespace std;

/*
 * 
 */
class ctemp{
public:
    int val;
    ctemp():val(0){cout<<"I am cstr 0"<<endl;};
    ctemp(int t):val(t){cout<<"I am cstr 1 "<<t<<endl;};
    ~ctemp(){cout<<"I am dstr "<<val<<endl;};
    
};
int main(int argc, char** argv) {
    
 containers::main();
 functions::main();
 buffer::main();
 return 0;
}



