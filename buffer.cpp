/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   buffer.cpp
 * Author: mhussain
 * 
 * Created on 20. Juli 2018, 12:35
 */
//#include <boost>
#include <array>

#include "buffer.h"
#include "common.h"

namespace buffer{
buffer::buffer (unsigned int u32Size) {
    this->reserve(u32Size);
}

buffer::buffer(const buffer& orig) {
}

buffer::~buffer() {
}
uint8* buffer::GetFreeArray(vector::size_type i_Size){
    this->at(this->size());
            
}

void buffer::PushPlainArray(uint8* pu8, vector::size_type i_Size){
    //this->at(this->size());
    for (std::size_t i=0; i<i_Size; i++) this->push_back(pu8[i]);      
}

template<std::size_t SIZE>
void buffer::PushArray(std::array<uint8, SIZE> Array){
    //cout<<Array.size()<<std::endl;
    for (std::size_t i=0; i<Array.size(); i++){
        this->push_back(Array.at(i)); 
        //cout<<this->at(i)<<"\t";
    }
    cout<<endl;
}
void buffer::PushVector(std::vector<uint8> Vector){
        for (std::size_t i=0; i<Vector.size(); i++){
        this->push_back(Vector.at(i)); 
        //cout<<this->at(i)<<"\t";
    }
}
#if __cplusplus > 201103L 
void buffer::PushAuto(auto Vector)
#else
template <typename T> void buffer::PushAuto(T Vector)

#endif
{
        for (std::size_t i=0; i<Vector.size(); i++){
        this->push_back(Vector.at(i)); 
        //cout<<this->at(i)<<"\t";
    }
}

std::size_t buffer::GetFreeSize(){
    return (this->capacity()-this->size());
}

void buffer::display(){
    for (int i=0; i<this->size();i++ )std::cout<<(int)this->at(i)<<"\t";
    cout<<std::endl;
}
void buffer::dump(std::size_t Max){
    for (int i=0; i<Max;i++ )std::cout<<(int)this->data()[i]<<"\t";
    cout<<std::endl;
}
void main(){
    
    DispalySection("BUFFER");
    
    buffer MyBuff(100);
    array<uint8, 15> Myarray={4,8,6,8,3,79,145,58,55,54,58,88};
    cout<<Myarray.size()<<std::endl;
    MyBuff.PushArray(Myarray);
//#if __cplusplus > 201103L     
    MyBuff.PushAuto(Myarray);
//#endif
    MyBuff.display();
    cout<<MyBuff.GetFreeSize()<<std::endl;
    MyBuff.insert(MyBuff.end(),{11,8,6,8,3,11,145,11,55,11,58,11});
    MyBuff.display();
    cout<<MyBuff.GetFreeSize()<<std::endl;
    MyBuff.clear();
    cout<<MyBuff.GetFreeSize()<<std::endl;
    MyBuff.dump(10);
    
}
}