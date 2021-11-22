#include "test.h"
void pt()
{
  printf("this is test\n");
  printf("this is test1\n");
}

void test::StartKey()
{
  key = new test2();
  printf("this is test2thred\n");
  while (1)
  {
    /* code */
    Sleep(500);
    hello = 0;
    hi = 0;
    how = 0;
    areyou = 0;
    key->SetKey();
    printf("key->GetKey() = %c\n", key->GetKey());
    if(key->GetKey() == '1')
    {
      printf("hello = 1\n");
      hello = 1;
    }
    if(key->GetKey() == '2')
    {
      hi = 1;
    }
    if(key->GetKey() == '3')
    {
      how = 1;
    }
    if(key->GetKey() == '4')
    {
      areyou = 1;
    }
    if(key->GetKey() == '9')
    {
      thbreak = 1;
    }
    printf("key\n");
  }
}

test::test(/* args */)
{
  hello = 0;
  hi = 0;
  how = 0;
  areyou = 0;
  thbreak = 0;
}

test::~test()
{
}

void test::SayHello()
{
  while (1)
  {
    /* code */
    Sleep(1000);
    if (hello)
      printf("Hello\n");
    if (thbreak)
    {
      printf("Helloout\n");
      break;
    }
      
  }
}

void test::SayHi()
{
  while (1)
  {
    /* code */
    Sleep(1000);
    if (hi)
      printf("Hi\n");
    if (thbreak)
    {
      printf("Hiout\n");
      break;
    }
  }
}

void test::SayHow()
{
  while (1)
  {
    /* code */
    Sleep(1000);
    if (how)
      printf("How\n");
    if (thbreak)
    {
      printf("Howout\n");
      break;
    }
  }
}

void test::SayAreYou()
{
  while (1)
  {
    /* code */
    Sleep(1000);
    if (areyou)
      printf("AreYou\n");
    if (thbreak)
    {
      printf("AreYouout\n");
      break;
    }
  }
}

int test::GetOut()
{
  return thbreak;
}

void* test::StartThreadSayHello(void *param)
{
	test *p = (test *)param;
	p->SayHello();
  return 0;
}

void* test::StartThreadSayHi(void *param)
{
	test *p = (test *)param;
	p->SayHi();
  return 0;
}

void* test::StartThreadSayHow(void *param)
{
	test *p = (test *)param;
	p->SayHow();
  return 0;
}

void* test::StartThreadSayAreYou(void *param)
{
	test *p = (test *)param;
	p->SayAreYou();
  return 0;
}

void* test::StartKeyboardThread(void *param)
{
	test *p = (test *)param;
	p->StartKey();
  return 0;
}

void test::StartAllThred()
{
  pthread_create(&m_thread_key, NULL, StartKeyboardThread, (void *)this);
  pthread_create(&m_thread_1, NULL, StartThreadSayHello, (void *)this);
  pthread_create(&m_thread_2, NULL, StartThreadSayHi, (void *)this);
  pthread_create(&m_thread_3, NULL, StartThreadSayHow, (void *)this);
  pthread_create(&m_thread_4, NULL, StartThreadSayAreYou, (void *)this);
  printf("hello1\n");
}