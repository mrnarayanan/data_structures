// Your code here
#include "potd.h"

using namespace std;

string getFortune(const string &s)
{
  int num_fort = 5;
  int len = s.length();
  string out;
  switch (len % num_fort)
  {
    case 0:
      out = "You will attain wealth beyond your wildest dreams.";
      break;
    case 1:
      out = "You will realize that there are four lights.";
      break;
    case 2:
      out = "Fulfill your destiny.";
      break;
    case 3:
      out = "Fortune favors fools, children, and ships named Enterprise.";
      break;
    case 4:
      out = "You will get an A in all of your classes.";
      break;
    default:
      out = "Empty fortune.";
  }
  return out;
}
