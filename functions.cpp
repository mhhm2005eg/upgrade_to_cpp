/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <typeinfo>
#include "common.h"

using namespace std;

namespace functions{
//Template
template <typename  T>
void Func_Temp(T X){
    cout<<typeid(T).name()<<endl;
    
    
}

//constexpr
#if __cplusplus > 201103L 
constexpr auto max(auto a, auto b){
    auto ret = (a>b)?a:b;
    return ret;
}
#else
template<typename  T>  T max(T a, T b){
    auto ret = (a>b)?a:b;
    return ret;
}
#endif

void vidDefaultArguemnets(int a, int b = 0, int c = 0){
    
    std::cout<<(a+b)+c<<std::endl;
    
    
}

int main(){
    
    DispalySection("FUNCTIONS");
    Func_Temp((char)6);
    auto ret = max(5,6);
    auto ret1 = max((unsigned char)5,(unsigned char)6);
    cout<<sizeof(ret)<<'\t'<<sizeof(ret1)<<endl;
    vidDefaultArguemnets(1);
    vidDefaultArguemnets(1,2);
    vidDefaultArguemnets(1,2, 3);
}
}