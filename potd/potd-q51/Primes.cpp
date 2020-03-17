#include <vector>
#include "Primes.h"

using namespace std;

vector<int> *genPrimes(int M)
{
    vector<int> *v = new vector<int>();
    if (M<2)
      return v;
    // vector<int> track;
    // track.resize(M+1); // to be able to 1-index
    int track[M+1];
    for (int i = 0; i < M+1; i++)
      track[i] = -1;
    track[0] = 0;
    track[1] = 0;
    int iter = 2;
    int mult;
    while (iter <= M)
    {
      track[iter] = 1;
      for (mult = iter + iter; mult <= M; mult += iter)
        track[mult] = 0;
      while(track[iter] != -1 && iter <= M)
        iter++;
    }
    for (int i = 0; i < M+1; i++)
    {
      if (track[i] == 1)
        v->push_back(i);
    }

    return v;
}
