#include "clock.h"

#include <iostream>

const long Time::s_TimeInit = time(NULL); 

void Time::Update()
{
  float current = clock();
  std::cout << current << std::endl;
}