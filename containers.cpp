/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

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
#include <boost/chrono.hpp>
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <map>
#include <stack>
#include <memory>
#include <set>
#include <utility>//pair
#include <queue>
#include "common.h"
typedef unsigned char uint8;
typedef unsigned short uint16;
#define u8Size 10


using namespace std;

/*
 * 
 */
namespace containers{

template <typename T> void vidPrintAll(T TObj);
template <typename T> void vidPrintAll_1(T TObj);
class ctemp{
public:
    int val;
    ctemp():val(0){cout<<"I am cstr 0"<<endl;};
    ctemp(int t):val(t){cout<<"I am cstr 1 "<<t<<endl;};
    ~ctemp(){cout<<"I am dstr "<<val<<endl;};
    
};

boost::chrono::high_resolution_clock::time_point t1 ;
boost::chrono::high_resolution_clock::time_point t2 ;

#define Take_T1() t1=boost::chrono::high_resolution_clock::now()
#define Take_T2() do{\
t2 = boost::chrono::high_resolution_clock::now();\
boost::chrono::nanoseconds sumGlobal;\
sumGlobal += (boost::chrono::duration_cast<boost::chrono::nanoseconds>(t2-t1));\
std::cout << sumGlobal << "\n";}while(0)







int main() {
    
    DispalySection("CONTAINERS");
    cout<<"----------------------------"<<endl;
    cout<<"-----------Plain Array------"<<endl;
    cout<<"----------------------------"<<endl;
    // plain array
    uint16 plain_array[u8Size]={0xBA00, 0xBA01,0xBA02,0xBA03,0xBA04,0xBA05,0xBA06};
    for (int i=0; i<u8Size;i++ )cout<<plain_array[i]<<'\t';
    cout<<endl;
    cout<<sizeof(plain_array)<<endl;
    
    //array cpp
    // Array Automatically initialized to zeros
    // at function will check the range before accessing the memory
    // sizeof>> howmany bytes, size()>> howmany elements
    // aArray.begin(), aArray.end(), return pointers to the first and last elemnets within the array
    // swap to copy contents from other array
    cout<<"----------------------------"<<endl;
    cout<<"-----------ARRAY------------"<<endl;
    cout<<"----------------------------"<<endl;
    array<uint16, u8Size> aArray = {55,5,3};
    for (int i=0; i<u8Size;i++ )cout<<aArray[i]<<':'<<aArray.at(i)<<':'<<aArray.data()[i]<<'\t';
    cout<<endl;
    //aArray.at(u8Size);
    cout<<sizeof(aArray)<<':'<<aArray.size()<<endl;
    cout<<aArray.front()<<" "<<aArray.back()<<endl;
    for(auto pi=aArray.begin(); pi<aArray.end();pi++)
        cout<<*pi<<'\t';
    cout<<endl;
    cout<<aArray.size()<<" "<<aArray.max_size()<<endl;
    
    
    // vector cpp
    // Vector is dynamically allocated and will be automaticllay deallocated
    // Vector will reserve more size than what you asked for, that allows it to 
    // extend the size dynamically if the reserved size is over it will reallocate 
    // a bigger size and copy the data automatically to the new area, that will cause
    // slowdown in the speed
    // vector has a push/pop functions like the stack
    // The size method here means howmany elements pushed to the vector, the capacity
    // is the reserved size
    // note that resize will get size = capacity = new size (if new size > old size))
    // if new size < old size, size will be new size the same and the capcity will remain 
    // Reserve, will reserve the memory location only but the resize will call the constructor as well.
    cout<<"----------------------------"<<endl;
    cout<<"-----------Vector------------"<<endl;
    cout<<"----------------------------"<<endl;    
    vector<uint16> u16Vector(u8Size);
    for (int i=0; i<u16Vector.size();i++ )cout<<u16Vector[i]<<':'<<u16Vector.at(i)<<':'<<u16Vector.data()[i]<<'\t';
    cout<<endl;
    cout<<"----------------------------"<<endl;
    vector<uint16> u16Vector2;
    u16Vector2.reserve(u8Size);
    u16Vector2.push_back(3);
    u16Vector2.push_back(33);
    u16Vector2[5] = 88;
    cout<<"----------------------------"<<endl;
    cout<<u16Vector2.size()<<" "<<u16Vector2.capacity()<<endl;
    cout<<"----------------------------"<<endl;
    for (int i=0; i<u8Size;i++ )cout<<u16Vector2[i]<<'\t';
    cout<<endl;
    cout<<"----------------------------"<<endl;
    
    for (int i=0; i<u16Vector2.size();i++ )cout<<u16Vector2[i]<<'\t';
    cout<<endl;
    cout<<"----------------------------"<<endl;
    u16Vector2.pop_back();
    for (int i=0; i<u16Vector2.size();i++ )cout<<u16Vector2[i]<<'\t';
    cout<<endl;
    cout<<"----------------------------"<<endl;
    u16Vector2.resize(20);
    for (int i=0; i<u16Vector2.size();i++ )cout<<u16Vector2[i]<<'\t';
    cout<<endl;
    cout<<u16Vector2.size()<<" "<<u16Vector2.capacity()<<endl;
    cout<<"----------------------------"<<endl;
    vector<ctemp> u16Vector3;
    u16Vector3.reserve(u8Size);
    // Vector can be initialized by a plain array
    vector<int> u16Vector4(plain_array, plain_array + u8Size);
    cout<<u16Vector4.size()<<" "<<u16Vector4.capacity()<<endl;
    //You may take a pointer of specific element but take care that function like
    // resize and push_back could cause a reallocation therefore the address is not anymore valide
    // itrator is a pointer
    // we have insert and erase methods
    
    
    //list: double linked list, no size determined, dynamically alloated
    //forward_list: normal linked list
    //Each element keeps information on how to locate the next and the previous elements,
    //list is faster than the vector for the sequencial access.
    //size return no of elements inserted or pushed
    cout<<"----------------------------"<<endl;
    cout<<"-----------LIST------------"<<endl;
    cout<<"----------------------------"<<endl;
    list<uint16> uint16_list;
    uint16_list.push_front((uint16)0x7788);
    uint16_list.push_back((uint16)0x7700);
    for(list<uint16>::iterator p=uint16_list.begin(); p!=uint16_list.end(); p++)
        cout<<*p<<'\t';
    cout<<endl;
     DisplayVariable(uint16_list);
    uint16_list.insert(uint16_list.begin(), plain_array[0]);
     DisplayVariable(uint16_list);
    uint16_list.insert(uint16_list.begin(), plain_array, &plain_array[6]);
    DisplayVariable(uint16_list);
    uint16_list.insert(uint16_list.end(), plain_array, &plain_array[6]);
    DisplayVariable(uint16_list);

    
    //smart pointer
    
    //tuble
    
    //map, multimap, unordered_map, unordered_multimap
    cout<<"----------------------------"<<endl;
    cout<<"------------MAP-------------"<<endl;
    cout<<"----------------------------"<<endl;
    map<char, int> dict;
    dict.emplace('a', 5);
    dict.emplace('b' , 8);
    dict.emplace('u' , 9);
    dict.emplace('k' , 9);
    dict.insert(std::make_pair('i', 100));
    dict.at('a')++;
    cout<<"----------------------------"<<endl;
    cout<<dict.size()<<endl;
    cout<<"----------------------------"<<endl;
    for(map<char, int>::iterator p = dict.begin(); p!= dict.end();p++ )
        cout<< p->first << p->second<<'\t';
    cout<<endl;
    for (auto& p: dict)
        cout<< p.first << p.second<<'\t';
    cout<<endl;
    
    cout<< dict.at('a') << dict.at('k')<<endl;
    cout<<"----------------------------"<<endl;
    
    //pair
    cout<<"----------------------------"<<endl;
    cout<<"------------pair------------"<<endl;
    cout<<"----------------------------"<<endl;    
    pair<char, int> inPair;
    inPair.first = '5';
    inPair.second = 5;
    cout<<inPair.first<<":"<<inPair.second<<endl;
    

// Stack
    stack<int,vector<int>> Mystack;
    
    Mystack.push(5);
    Mystack.push(9);
    while(! Mystack.empty()){
        cout<< Mystack.top()<<" "<<Mystack.size()<<'\t';
        Mystack.pop();
        
    }
    cout<<endl;
    
    //smart pointer
    // unique_ptr, resources are pointed by only one unique pointer so if the 
    // pointer got out of scope the reserved area will be automatically released !
    // the pointer instance will disrtoy the reserved area within it's distractor 
    int a = 6;
    int *r;
    unique_ptr<int> uiPtr(new int[4]);
    *uiPtr = 9;
    //uiPtr.release();
    cout<< a<<" : "<<sizeof(r)<<" "<<*uiPtr<<" : "<<sizeof(uiPtr)<<endl;
    
    shared_ptr<int> shPtr(new int[4]);
    cout<<*shPtr<<" : "<<sizeof(shPtr)<<endl;
    cout<<shPtr.get()<<" : "<<*shPtr.get()<<endl;
    *uiPtr = 91;

    //Tuple
    cout<<"----------------------------"<<endl;
    cout<<"------------Tuple-----------"<<endl;
    cout<<"----------------------------"<<endl;
    tuple<char, int, int> inTuple;
    std::get<0>(inTuple) = 'a';
    std::get<1>(inTuple) = 1;
    std::get<2>(inTuple) = 5;
    cout<<std::get<0>(inTuple)<<":"<<std::get<1>(inTuple)<<":"<<std::get<2>(inTuple)<<endl;
    inTuple = make_tuple('b', 55, 66);
    cout<<std::get<0>(inTuple)<<":"<<std::get<1>(inTuple)<<":"<<std::get<2>(inTuple)<<endl;
    cout<<sizeof(inTuple)<<endl;
    cout<<sizeof(tuple<int>)<<endl;
    
    //List Tuple
    cout<<"----------------------------"<<endl;
    cout<<"------------LIST Tuple------"<<endl;
    cout<<"----------------------------"<<endl;    
    list<tuple<char, int, int>> List_Tuple;
    List_Tuple.insert(List_Tuple.begin(), make_tuple('c', 55, 66));
    List_Tuple.push_back(make_tuple('d', 55, 66));
    List_Tuple.push_front(make_tuple('a', 55, 66));
    
    for(auto tuple_i : List_Tuple)
        cout<<std::get<0>(tuple_i)<<":"<<std::get<1>(tuple_i)<<":"<<std::get<2>(tuple_i)<<endl;

    // Queue
    cout<<"----------------------------"<<endl;
    cout<<"------------Queue-----------"<<endl;
    cout<<"----------------------------"<<endl;        
    queue<ctemp> MyQueue;
    ctemp MyTemp(5);
    ctemp MyTemp1(51);
    MyQueue.push(MyTemp);
    MyQueue.push(MyTemp1);
    
    while(! MyQueue.empty())
    {
        cout<<MyQueue.front().val<<endl;
        MyQueue.pop();
    }
    /*for (auto ins_i:MyQueue)
        cout<<ins_i.<<endl;*/

//set
    set<int> Myset;
    Myset.insert(5);Myset.insert(7);Myset.insert(3);
    
    //Template function
    cout<<Myset.find(5)._M_node<<endl;
    vidPrintAll(Myset);
    
    vidPrintAll(u16Vector4);
    vidPrintAll(uint16_list);
    Take_T1();
    vidPrintAll(aArray);
    Take_T2();
    
    Take_T1();
    vidPrintAll_1(aArray);
    Take_T2();
    
    
    return 0;
}

template <typename T> void vidPrintAll(T TObj){
    for(typename T::iterator p=TObj.begin();  p!= TObj.end();p++ )
    cout<<*p<<'\t';
    cout<<endl;
    
}
template <typename T> void vidPrintAll_1(T TObj){
    for(auto& v:TObj)
    cout<<v<<'\t';
    cout<<endl;
    
}
}
