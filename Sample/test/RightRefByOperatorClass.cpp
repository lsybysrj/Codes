#include <iostream>

class TClass;
class RefClass
{
  public:
    RefClass(TClass* t){m_OriginClass=t;std::cout<<"t is : "<<t<<std::endl;}
//    RefClass(TClass t){m_OriginClass=t;std::cout<<"t is : "<<t<<std::endl;}
  private:
    TClass *m_OriginClass;
};

class TClass
{
  public:
    TClass(int){std::cout<<"from construct"<<std::endl;std::cout<<"this is : "<<this<<std::endl;}
    operator int(){std::cout<<"from int()"<<std::endl;return 5;}
    operator RefClass(){std::cout<<"from RefClass()"<<std::endl;return RefClass(this);}
};

void testfun(TClass& t)
{
  std::cout<<"from TClass&"<<std::endl;
}
void testfun2(RefClass t)
{
  std::cout<<"from RefClass"<<std::endl;
}

int main()
{
  std::cout<<"-------------"<<std::endl;
  TClass tc=100;
  std::cout<<"-------------"<<std::endl;
  testfun(tc);
  std::cout<<"-------------"<<std::endl;
  testfun2(TClass(1));
  std::cout<<"-------------"<<std::endl;
  return 0;
}
