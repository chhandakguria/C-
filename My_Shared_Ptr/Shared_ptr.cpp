shared pointer

#include<iostream>

using namespace std;

class Test
{
  int i;
public: 
  Test(int ii):i(ii)
  {
    
  }
  ~Test(){}
};

template <typename T>
class My_Shared
{
   int *cnt;
   T *ptr;
public:
   My_Shared(T *p == null_ptr): ptr(p)
  {
    cnt = new int;
	*cnt = 0;
  } 
  
   My_Shared(const My_Shared<T&> othr)
  {
    cnt = othr.cnt;
	ptr = othr.ptr;
	inc_cnt();
  }  

  My_Shared& My_Shared(const My_Shared<T&> othr)
  {
    cnt = othr.cnt;
	ptr = othr.ptr;
	inc_cnt();
	return *this;
  }
};