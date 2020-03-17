#include <vector>
#include <string>

using namespace std;

vector<string> NoProblem(int start, vector<int> created, vector<int> needed)
{
    // your code here
    string success = "No problem! :D";
    string fail = "No problem. :(";
    vector<string> output;
    int sum = start;
    for (unsigned i = 0; i < created.size(); i++)
    {
      if (sum < needed[i])
        output.push_back(fail);
      else
      {
        output.push_back(success);
        sum -= needed[i];
      }
      sum += created[i];
    }
    return output;
}
