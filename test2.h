#ifndef _TEST2_H_
#define _TEST2_H_
#include <stdio.h>
#include <windows.h> 
#include <pthread.h>
#include "conio.h"

void pt2();
// pthread_mutex_t mutexofkey;

class test2
{
private:
  /* data */
  unsigned char m_key;
  char key[1024];
public:
  test2(/* args */);
  ~test2();
  unsigned char GetKey()
  {
    return m_key;
  };
  void SetKey();
  // void StartKey();
};
#endif
