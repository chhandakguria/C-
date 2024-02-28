

#include<iostream>
#include<thread>
#include<vector>
#include<mutex>


using namespace std;

class GUI {
public: 
  virtual void draw() = 0;
  virtual ~GUI() {}

};

class button : public GUI {

public: 
  void draw() {
    
	cout<<"button\n";
  
  }
  
  ~button()
  {
   cout<<"button destructor\n";
  }


};

class square : public GUI {

public: 
  void draw() {
    
	cout<<"square\n";
  
  }
  
  ~square()
  {
   cout<<"square destructor\n";
  };


};

class factory {
public:
 enum eType{
    ebutton,
	esquare,
 };
 
 GUI* createfactory (int type){
 
     switch(type)
	 {
	  case ebutton :
	    return new button;
		break;
	  case esquare :
	    return new square;
		break;
	  default:
		return nullptr;
		
	 }
	 
 
 }


};

int main(){
   factory f;
   GUI* ibutton = f.createfactory(factory::ebutton); 
   GUI* isquare = f.createfactory(factory::esquare); 
   ibutton->draw();
   isquare->draw();
   delete ibutton;
   delete isquare;
   return 0;
}

























