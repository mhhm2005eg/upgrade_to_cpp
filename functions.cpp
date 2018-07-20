/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <typeinfo>

using namespace std;

namespace functions{
//Template
template <typename  T>
void Func_Temp(T X){
    cout<<typeid(T).name()<<endl;
    
    
}

//constexpr

constexpr auto max(auto a, auto b){
    auto ret = (a>b)?a:b;
    return ret;
}


int main(){
    
    Func_Temp((char)6);
    auto ret = max(5,6);
    auto ret1 = max((unsigned char)5,(unsigned char)6);
    cout<<sizeof(ret)<<'\t'<<sizeof(ret1)<<endl;
    
}
}