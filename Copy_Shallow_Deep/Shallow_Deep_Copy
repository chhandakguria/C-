class Test
{
public:
int size;
int *p;

Test(int a)
{
  size = a;
  p = new int[size];
}

Test(const Test& other)
{
  size = other.size;
  p = other.p;
  cout<<"In shallow copy "<<other.p[0];
}

Test(const Test& other)
{
  size = other.size;
  p = new int[other.size]
  cout<<"In deep copy "<<other.p[0];
}

~Test(const Test& other)
{
   delete []p;
}
};

int main()
{
  Test obj1(10);
  obj1.p[0] =25;
  
  {
    Test obj2(obj1);
  }
  return 0;
}