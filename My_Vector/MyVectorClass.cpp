#include<iostream>
//#include<vector>


using namespace std;



class MyVector {

int vsize;
int maxsize;
int *array;

void alloc_new();


public:
MyVector();
MyVector(int a);
MyVector(const MyVector& );
MyVector& operator =(const MyVector& );
void Push_back(int a);
int size();
MyVector& operator+=(int a);
int operator[](int a);


} ;
MyVector::MyVector(){
   vsize =0;
   maxsize =10;
   array = new int[maxsize];

}

MyVector::MyVector(int a){
   vsize =0;
   maxsize =a;
   array = new int[maxsize];

}
MyVector::MyVector(const MyVector& v){

   cout<<"In Copy\n";
   vsize =v.vsize;
   maxsize =v.maxsize;
   array = new int[v.maxsize];
   for (int i=0; i<v.vsize; i++)
   array[i] = v.array[i];
   

}
MyVector& MyVector::operator = (const MyVector& v){

   cout<<"In Assignment\n";
   vsize =v.vsize;
   maxsize =v.maxsize;
   delete []array;
   array = new int[v.maxsize];
   for (int i=0; i<v.vsize; i++)
   array[i] = v.array[i];
   return *this;

}

void MyVector::Push_back(int a)
{
   if(vsize+1>maxsize)
     alloc_new();
	array[vsize] = a;
	vsize++;

}

void MyVector::alloc_new()
{
   maxsize = vsize *2;
   int *temp = new int[maxsize];
   for(int i =0; i<vsize; i++)
     temp[i] = array[i];
	 
   delete []array;
   array = temp;   
   
}

int MyVector::size()
{
   return vsize;
}

int MyVector::operator[](int a)
{
   //cout<<"bracket\n";
   return array[a];
  
}

MyVector& MyVector::operator+=(int i)
{
   this->Push_back(i);
   return *this;
  
}

int main()
{
MyVector vec1;
int temp;
while(1)
{
  cin>>temp;
  if(temp == -1)
  break;
  vec1.Push_back(temp);
  
}

vec1 += 99;
MyVector vec2(vec1);
for(int i=0;i<vec2.size();i++)
 cout<<vec2[i]<<"\n";

MyVector vec3;
vec3 = vec1;
for(int i=0;i<vec3.size();i++)
 cout<<vec3[i]<<"\n";
 
 return 0;


}


