#include <stdio.h>
#include "test.h"
#include "test2.h"
int main()
{
  pt();
  pt2();
  test th;
  th.StartAllThred();
  while (1)
  {
    Sleep(10000);
    printf("this is while\n");
    if(th.GetOut())
    {
      break;
    }
    /* code */
  }
  
  printf("this is main\n");
}