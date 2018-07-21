/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buffer.h
 * Author: mhussain
 *
 * Created on 20. Juli 2018, 12:35
 */

#ifndef BUFFER_H
#define BUFFER_H

#include <iostream>
#include <vector>
#include <array>

using namespace std;
typedef unsigned char uint8;
namespace buffer{
class buffer: public std::vector <uint8> {
public:
    buffer(unsigned int u32Size);
    buffer(const buffer& orig);
    virtual ~buffer();
    uint8* GetFreeArray(vector::size_type Size);
    template<std::size_t SIZE> void PushArray(std::array<uint8, SIZE> Array);
    void PushPlainArray(uint8* pu8, vector::size_type i_Size);
    void PushVector(std::vector<uint8> Vector);
#if __cplusplus > 201103L    
    void PushAuto(auto Vector);
#else
    template<typename T> void PushAuto(T Vector);   
#endif    
    std::size_t GetFreeSize();
    void display();
    void dump(std::size_t Max);
private:

};


}

#endif /* BUFFER_H */

