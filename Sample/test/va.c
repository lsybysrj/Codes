#include <stdio.h>
#include <stdarg.h>

int va_fun_str(char* str,...)
{
  printf("va_fun_str begin\n");
  va_list ap;
  va_start(ap,str);
  printf("ap is %lld\n",ap);
  int arg1=va_arg(ap,int);
  printf("ap is %lld\n",ap);
  printf("arg1 is %d\n",arg1);
  printf("va_fun_str end\n");
  return 0;
}
int va_fun_int(int n,...)
{
  printf("va_fun_int begin\n");
  va_list ap;
  va_start(ap,n);
  printf("ap is %lld\n",ap);
  int arg1=va_arg(ap,int);
  printf("ap is %lld\n",ap);
  printf("arg1 is %d\n",arg1);
  printf("va_fun_int end\n");
  return 0;
}

int main()
{
  va_fun_str((char*)"hello",1);
  va_fun_int(100,23);
  return 0;
}
