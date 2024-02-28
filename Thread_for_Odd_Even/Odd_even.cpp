#include<iostream>

#include<thread>
#include<mutex>

#include<condition_variable>
using namespace std;
mutex mu;
condition_variable cv;

int n =0;

int limit =15;

void print_odd()
{
   while(n<limit)
   {
      unique_lock<mutex> lk(mu);
      cv.wait(lk,[](){return n%2 == 1;});
      cout<<n<<"\n";
      n++;

	  cv.notify_one();
   }


}

void print_even()
{
   while(n<limit)
   {
      unique_lock<mutex> lk(mu);
      cv.wait(lk,[](){ return n%2 == 0;});
	  cout<<n<<"\n";
	  n++;
	  cv.notify_one();
   }


}

int main()
{

   thread t1(print_odd);
   thread t2(print_even);
   
   t1.join();
   t2.join();
   
   return 0;


}



