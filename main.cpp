
#include <map>
#include <cstdlib>

#include <iostream>
#include <string>
#include <deque>
#if M_NAMESPACE == 1
    #include <map>
    #include <stack>
    #include <vector>
    namespace ft = std;
#else
     #include "map.hpp"
#endif

int main(int argv, char ** argc)
{
  ft::map<int , int> a;
  if (argv != 2)
     return 0;
    int u = atoi(argc[1]);
    int i;
  srand(time(NULL));
    while (u-- != 0)
    {

      i =  rand() % 2147483647;
       a.insert(ft::pair<const int, int>(i, 100));
        a.print_tab();
    }
  return 0;

}
