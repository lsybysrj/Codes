#include <iostream>
#include <typeinfo>

void fun2(const int* n)
{

}
void fun(const int* i)
{
  fun2(i);
}
const int* retconst()
{
  const int n=100;
  const int* i=&n;
  return i;
}


int main()
{
  fun(retconst());
  typedef int* intptr;
  typedef const int * type1;
  const int* n;
  std::cout<<"const int * 's 'typename is : "<<typeid(n).name()<<std::endl;
  std::cout<<"type1 's typename is : "<<typeid(type1).name()<<std::endl;
  const intptr m=new int;
  std::cout<<"const intptr 's 'typename is :"<<typeid(m).name()<<std::endl;
  *m=100;
}
