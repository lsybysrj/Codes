#include <iostream>
template<typename T>
class TemplateClass
{
  public:
    template<typename FT>
    void Output(FT var,T var2)
    {
      std::cout<<"var is : "<<var<<" , var2 is : "<<var<<std::endl;
    }
};


int main()
{
  TemplateClass<int> tc;
  tc.Output(100,15);
  tc.Output("hello","haha");
  return 0;
}

