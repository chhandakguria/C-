

#include<new>
void func()
{
  cout<<"out of memory\n";
}
int main()
{

set_new_handler(func);
int *p;  
while(1)
{
  p = new int [1000];
}


return 0;
}
