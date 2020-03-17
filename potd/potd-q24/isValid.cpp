#include <string>
#include <stack>

using namespace std;

bool isValid(string input) {
    stack<char> s;

    int len = input.length();
    for (int i = 0; i < len; i++)
    {
      if (input[i] == '(')
        s.push('(');
      else if (input[i] == '[')
        s.push('[');
      else if (input[i] == '{')
        s.push('{');
      else if (input[i] == ')')
      {
        if (!s.empty() && s.top() == '(')
          s.pop();
        else
          return false;
      }
      else if (input[i] == ']')
      {
        if (!s.empty() && s.top() == '[')
          s.pop();
        else
          return false;
      }
      else if (input[i] == '}')
      {
        if (!s.empty() && s.top() == '{')
          s.pop();
        else
          return false;
      }
    }

    if (s.empty())
      return true;
    else
      return false;
}
