#include "test2.h"
void pt2()
{
  printf("this is test2\n");
  printf("this is test3\n");
}

test2::test2(/* args */)
{
  m_key = 0;
}

test2::~test2()
{
}

void test2::SetKey()
{
  // printf("please input key\n");
  m_key = getch();
  printf("currentkey = %s", &m_key);
}