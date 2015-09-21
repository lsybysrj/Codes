#include <stdio.h>
#include <string.h>
void myfun(int i)
{
  printf("from myfun\n");
  return;
}
void myfun2(int i)
{
  printf("from myfun2\n");
  return;
}
void mymodify()
{
}
int main()
{
  printf("hello world\n");
  putchar(10);
  puts(0);
  myfun(100);
  myfun2(123);
  return 0;
}
