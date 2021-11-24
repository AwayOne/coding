#include "test.h"
void pt()
{
  printf("this is test\n");
  printf("this is test1\n");
}

void test::StartKey()
{
  key = new test2();
  printf("keythredstart\n");
  while (1)
  {
    /* code */
    Sleep(20);
    key->SetKey();
    // printf("key->GetKey() = %c\n", key->GetKey());
    pthread_mutex_lock (&mutex);
    if(key->GetKey() == '1')
    {
      // printf("hello = 1\n");
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
    Sleep(5000);
    pthread_mutex_unlock (&mutex);
    // printf("key\n");
  }
}

test::test(/* args */)
{
  hello = 0;
  hi = 0;
  how = 0;
  areyou = 0;
  thbreak = 0;
  pthread_mutex_init (&mutex,NULL);
}

test::~test()
{
}

void test::SayHello()
{
  printf("Hellothredstart\n");
  while (1)
  {
    /* code */
    Sleep(1000);
    printf("Hellotest\n");
    if (hello)
    {
      printf("Hello\n");
      hello = 0;
    } 
    if (thbreak)
    {
      printf("Helloout\n");
      break;
    }
      
  }
}

void test::SayHi()
{
  printf("Hithredstart\n");
  while (1)
  {
    /* code */
    Sleep(40);
    if (hi)
    {
      printf("Hi\n");
      hi = 0;
    }
    if (thbreak)
    {
      printf("Hiout\n");
      break;
    }
  }
}

void test::SayHow()
{
  printf("Howthredstart\n");
  while (1)
  {
    /* code */
    Sleep(40);
    if (how)
    {
      printf("How\n");
      how = 0;
    }
    if (thbreak)
    {
      printf("Howout\n");
      break;
    }
  }
}

void test::SayAreYou()
{
  printf("HowAreYouthredstart\n");
  while (1)
  {
    /* code */
    Sleep(40);
    if (areyou)
    {
      printf("AreYou\n");
      areyou = 0;
    }
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
  // if (0 != m_thread_key)
	// {	
	// 	pthread_join(m_thread_key, NULL);
	// 	m_thread_key = 0;
	// }
  // if (0 != m_thread_1)
	// {	
	// 	pthread_join(m_thread_1, NULL);
	// 	m_thread_1 = 0;
	// }
  // if (0 != m_thread_2)
	// {	
	// 	pthread_join(m_thread_2, NULL);
	// 	m_thread_2 = 0;
	// }
  // if (0 != m_thread_3)
	// {	
	// 	pthread_join(m_thread_3, NULL);
	// 	m_thread_3 = 0;
	// }
  // if (0 != m_thread_4)
	// {	
	// 	pthread_join(m_thread_4, NULL);
	// 	m_thread_4 = 0;
	// }
  // printf("hello1\n");
}