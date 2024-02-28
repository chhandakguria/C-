#include<iostream>
//#include<vector>


using namespace std;



class Mystring {

char *str;


public:
Mystring();
Mystring(int a);
Mystring(const Mystring& );
Mystring& operator =(const Mystring& );
int length();


} ;

Mystring::Mystring(){
  str = new char[1];
  str[0] ='\0';

}

Mystring::Mystring(char* s){
   cout<<"normal\n";
   str = new char[strlen(s)+1];
   strcpy(str,s);
   display();

}
Mystring::Mystring(const Mystring& s){
   cout<<"copy\n";
   str = new char[s.length()+1];
   strcpy(str,s.str);
   display();

}
Mystring& Mystring::operator = (const Mystring& s){
   cout<<"assignment\n";
   delete []str;
   str = new char[s.length()+1];
   strcpy(str,s.str);
   display();

}

int Mystring::length()
{
   return (strlen(str));
}

void Mystring::display()
{
  cout<< str <<"\n";
}
~Mystring::Mystring()
{
   cout<<"destructor\n";
   delete []str;
}


int main()
{
 Mystring s1;
 char *s = "Hello";
 s1(s);
 Mystring s2(s1);
 Mystring s3;
 s3 = s1;

return 0;
}
