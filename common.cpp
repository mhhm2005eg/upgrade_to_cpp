/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <string>
#include <iostream>
#include "common.h"

using namespace std;



void DispalyLine(unsigned char L){
    cout<< std::string(L, '-')<<endl;
}
void DispalySection(std::string S ){
    
    DispalyLine();
    unsigned char  l1 = (LINE_LENGTH - S.length())/2;
    unsigned char  l2 = (LINE_LENGTH - S.length() -l1);
    cout<< std::string(l1, '*') + S +std::string(l2, '*')<<endl;
    
    DispalyLine();
}

