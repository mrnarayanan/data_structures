/* Your code here! */
#include "epoch.h"
#include <ctime>

using namespace std;

int hours(time_t chron)
{
  int hr; // 1 hour = 3600 sec
  hr = (int) chron / 3600;
  return hr;
}

int days(time_t chron)
{
  int dy; // 1 day = 86400 sec
  dy = (int) chron / 86400;
  return dy;
}

int years(time_t chron)
{
  int yr; // 1 year = 31536000 sec
  yr = (int) chron / 31536000;
  return yr;
}
