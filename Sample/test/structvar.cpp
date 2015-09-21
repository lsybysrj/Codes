#include <iostream>
class myclass
{
  public:
    myclass(){}
    ~myclass(){std::cout<<"~myclass()";}
};
struct myst
{
  myclass mc; 
};
int main()
{
  myst *mst=new myst;
  delete mst;
  std::cout<<"quit"<<std::endl;
  return 0;
}
