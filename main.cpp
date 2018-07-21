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
#include  <unordered_map>
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

template <typename T> char cFindFirstUnique(string S){
    char ret = (char)0x00;
    std::unordered_map<char, T> umap;
    for (int i=S.length()-1; i>=0; i--){
        //cout<<i<<'\t'<<S[i]<<endl;
        if (!umap.count(toupper(S[i])))umap.insert(make_pair(toupper(S[i]), 1));
        else umap.at(toupper(S[i]))++;
    }
    for (auto Mypair=umap.cbegin(); Mypair != umap.cend(); Mypair++){
        if (Mypair->second == 1){ret = Mypair->first; 
        break;}
    }
    
    return ret;
}

char cFindFirstUnique_1(string S){
    
int count=0;
char ret = (char) 0x00;
    for (int i=0; i<S.length(); i++){
        
        for (int j=0; j<S.length();j++){
            
            if(toupper(S[i])==toupper(S[j]))count++;
        }
        
        if(count == 1){ret=toupper(S[i]);break;}
        else count=0;
    }
      
return ret;
}

int main(int argc, char** argv) {
    
 containers::main();
 functions::main();
 buffer::main();
 Take_T1();
 char c = cFindFirstUnique<int>(string("I am the string agrmhstrnuEKKuL"));
 Take_T2();
 cout<<c<<endl;
 Take_T1();
 c = cFindFirstUnique_1(string("I am the string agrmhstrnuEKKuL"));
 Take_T2();
 cout<<c<<endl;

 
 dynamic_allocation::main();
 classes_test::main();
 
 
 
  return 0;
 
}



