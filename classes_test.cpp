/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include "common.h"
using namespace std;

/*
 *Private: Only seen by the class members cannot accessed by the main nor by the childeren
 *Public : seen by the children and by the main 
 *Protected is something inbetween, seen by the childeren but cannot be accessed from the main  
 
 */
namespace classes_test{
class ParentClass{
private:    
    int pvX;

    
protected:
    int ptX;
    
public:
    int pbX;
    
};

class ChildClass:public ParentClass{
private:    
    int pvY;

protected:
    int ptY;
    
public:
    int pbY;
    int getProtected(){return this->pbY;}
    
};

void main(){
    DispalySection("CLASSES");
    ParentClass P;
    ChildClass C;
    cout<<P.pbX<<endl;
    //thraw error
    //cout<<P.ptX<<endl;
    cout<<C.pbY<<'\t'<<C.pbX<<endl;
    cout<<C.getProtected()<<endl;
    
}
}