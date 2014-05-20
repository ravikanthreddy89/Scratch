#include <iostream>
#include "stack.h"

using namespace std;
using namespace stack;
int main() {
   Stack<char, 10> s; // 10 chars
   char ch;
   while ((ch = cin.get()) != '\n')
      if (!s.full()) s.push(ch);
   while (!s.empty())
      cout << s.pop();
   cout << endl;
   Stack<double, 4> ds; // 4 doubles
   double d[] =
      {1.0, 3.0, 5.0, 7.0, 9.0, 0.0};
   int i = 0;
   while (d[i] != 0.0 && !ds.full())
      if (!ds.full()) ds.push(d[i++]);
   while (!ds.empty())
      cout << ds.pop() << "  ";
   cout << endl;
   return 0;
}
