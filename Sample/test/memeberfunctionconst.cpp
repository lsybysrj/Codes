#include <iostream>
class CTest
{
  public:
    void testStatic()const{
      m_staticInt=100;//static variable is ok
    }
    void testNonStatic()const{
      m_int=100;//error:cannot write nonstatic member variable
    }
  private:
    int m_int;
    static int m_staticInt;
};

int CTest::m_staticInt;

int main()
{
  CTest ct;
  ct.test();
  return 0;
}
