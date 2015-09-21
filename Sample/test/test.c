#include <stdio.h>
int main()
{
  int mul[81]={0};
  for(int count=1,times=1;count<10;count++)
  {
    for(times=count;times<10;times++)
    {
      mul[count*times-1]=count*times;
    }
  }
  for(int count=1;count<10;count++)
  {
    for(int times=1;times<count+1;times++)
    {
      printf("%-*d  ",3,mul[count*times-1]);
    }
    printf("\n");
  }
  return 0;
}
