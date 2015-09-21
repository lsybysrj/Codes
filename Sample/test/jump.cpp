#include <stdio.h>
#include <string.h>
#include <stdint.h>
void myfun()
{
  printf("from myfun\n");
}
void myfun2()
{
  printf("from myfun2\n");
}

int main()
{
  myfun();
  unsigned char jmp[12]={0x48,0xb8};
  memcpy(&jmp[2],(void*)&myfun2,8);
  jmp[10]=0xff;
  jmp[11]=0xe0;
  memcpy((void*)myfun,jmp,12);
  myfun();
  return 0;
}
