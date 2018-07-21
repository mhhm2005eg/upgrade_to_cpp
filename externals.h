/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   containers.h
 * Author: mhussain
 *
 * Created on 20. Juli 2018, 11:32
 */

#ifndef CONTAINERS_H
#define CONTAINERS_H
#include <boost/chrono.hpp>


boost::chrono::high_resolution_clock::time_point t1 ;
boost::chrono::high_resolution_clock::time_point t2 ;

#define Take_T1() t1=boost::chrono::high_resolution_clock::now()
#define Take_T2() do{\
t2 = boost::chrono::high_resolution_clock::now();\
boost::chrono::nanoseconds sumGlobal;\
sumGlobal += (boost::chrono::duration_cast<boost::chrono::nanoseconds>(t2-t1));\
std::cout << sumGlobal << "\n";}while(0)


namespace containers{
    
    int main();
}
namespace functions{
    int main();
}
namespace buffer{
    void main();
}
namespace dynamic_allocation{
    
    void main();
}

namespace classes_test{
    
    void main();
}
#endif /* CONTAINERS_H */

