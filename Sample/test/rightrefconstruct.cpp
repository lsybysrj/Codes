#include <iostream>
#include <string>
class myclass
{
  public:
    myclass(){std::cout<<"from myclass"<<std::endl;}
    myclass(myclass &mc){std::cout<<"from myclass&"<<std::endl;}   
    myclass(myclass&& mc){std::cout<<"from myclass&& "<<std::endl;}
};
std::string mystr()
{
  std::string str;
  str.append("hello world");
  std::cout<<"from mystr,c_str() is "<<std::hex<<(uint64_t)str.c_str()<<std::endl;
  return str;
}
myclass myclassret()
{
  myclass ret;
  return std::move(ret);
}
int main()
{
  myclass mc=myclassret();
  std::string str=mystr();
  std::cout<<"from main,c_str() is "<<std::hex<<(uint64_t)str.c_str()<<std::endl;
  std::cout<<"str is : "<<str<<std::endl;
  return 0;
}
