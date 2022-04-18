
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

int main(int argv, char **argc)
{
  argv  = atoi(argc[1]);
 // std::cout <<  argv;
  ft::map<int , int> a;
        int cc = 1;
   int v[100] = {65,78,5,23,85,66,1,63,94,14,97,53,70,19,84,35,42,83,31,92,62,55,89,54,50,79,29,93,61,96,47,39,76,99,69,60,6,48,52,91,11,49,73,4,90,22,88,75,95,51,67,87,21,34,86,77,17,9,71,27,25,82,100,18,98,41,59,40,36,7,37,44,64,57,58,74,8,2,30,45,80,20,15,43,13,3,46,12,56,72,28,38,16,24,33,32,10,26,81,68};
    int i = 1;
  srand(time(NULL));
    while (argv != i)
    {
      cc = rand() % 1000000000;
       a.insert(ft::pair<const int, int>(v[i], 100));
        i++;
  //     a.print_tab();
    //q     std::cin >> cc;
    }
          std::cout << "AVANT ERASE" << std::endl;
          a.print_tab();
          std::cout << "AVANT ERASE" << std::endl;
          a.erase(63);
                    std::cout << "APRES ERASE" << std::endl;
          a.print_tab();
                    std::cout << "APRES ERASE" << std::endl;
           return 0;
    ft::map<int,int>::iterator b = a.begin();
   
    
    while (b != a.end())
    {
   // std::cout << b->first << std::endl;
    b++;
   // sleep(1);
    }
  return 0;

}
