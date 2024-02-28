#include<iostream>
#include<vector>


using namespace std;

class Base {

public:
virtual void fun() = 0;

};

class Deriverd1: public Base
{
int somedata;
public:
Deriverd1 ()
{
somedata =5;
}

void fun() {
cout<<"Deriverd1 "<<somedata;
}

};

class Deriverd2: public Base
{
int somedata;
public:
Deriverd2 ()
{
somedata =25;
}

void fun() {
cout<<"Deriverd2 "<<somedata;
}

};


int main(){

Base *b = new Deriverd1;
Deriverd1 *d1 = dynamic_cast<Deriverd1*>(b);
if(d1){
   cout<<"Hi";
d1->fun();
}


return 0;
}