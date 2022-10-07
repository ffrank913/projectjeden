#pragma once

#include <time.h>

class Time
{
public:  
  static long Now(); 
  static long DeltaTime(); 
  
  static void Update();

private:
  static const long s_TimeInit;
  static long s_TimeTotal;
  static long s_TimeNow;
  static long s_TimeDelta;

};