

#include<iostream>
#include<thread>
#include<vector>

using namespace std;

class Singleton {

public:
       static Singleton* instance;
	   
	   static Singleton* GetInstance()
	   {
	      if(!instance)
		  {
		     instance = new Singleton;
		  }
		  return instance;
	   }
private:
    Singleton() {
	
	   cout<< "Instance is created"<<endl;
	}
	
	Singleton(const Singleton& other ) {
	
	   cout<< "Copy constructor Instance is created"<<endl;
	}
	
	const Singleton& operator= (const Singleton& other ) {
	
	   cout<< "Operator assignment Instance is created"<<endl;
	   return *this;
	}

};
Singleton* Singleton::instance = NULL;

int main(){

 // Singleton* p1= Singleton::GetInstance();
  //Singleton* p2= Singleton::GetInstance();

  vector<thread> threadObj;
 
  for(int i=0; i<10; i++){
     threadObj.emplace_back([](){Singleton::GetInstance();});     

  }

  for(auto &i : threadObj){
	if(i.joinable()){
		i.join();
	}
  }

  return 0;

}