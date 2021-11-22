#ifndef _TEST_H_
#define _TEST_H_
#include <stdio.h>

void pt();

#include <stdio.h>
#include <pthread.h>
#include "test2.h"

class test
{
private:
  /* data */
  int hello;
  int hi;
  int how;
  int areyou;
  int thbreak;

  test2 *key;
  pthread_t m_thread_key;
  pthread_t m_thread_1;
  pthread_t m_thread_2;
  pthread_t m_thread_3;
  pthread_t m_thread_4;
  pthread_t m_thread_5;
  static void *StartKeyboardThread(void *param);
  static void *StartThreadSayHello(void *param);
  static void *StartThreadSayHi(void *param);
  static void *StartThreadSayHow(void *param);
  static void *StartThreadSayAreYou(void *param);
  void StartKey();
  void SayHello();
  void SayHi();
  void SayHow();
  void SayAreYou();
public:
  test(/* args */);
  ~test();
  void StartAllThred();
  int GetOut();
};

// thred::thred(/* args */)
// {
//   hello = 0;
//   hi = 0;
//   how = 0;
//   areyou = 0;
//   thbreak = 0;
// }

// thred::~thred()
// {
// }
#endif