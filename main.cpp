#include "vector.hpp"
#include <vector>

int main()
{
   // int n[] = {10,20,30,40,50,60,70,80,90,100,110};
   // ft::vector<int> l(n , n+10);
       ft::vector<int> d(10, 12);
    //std::vector<int> a(10, 12);
   // a.push_back(12);
    d.push_back(12);
    return 0;
    /* 
    d = l;

     for (size_t i = 0; i < d.size(); i++)
     {
         std::cout << d[i] << std::endl;
     }


    d.reserve(23);

    for (size_t i = 0; i < d.size();  i++)
    {
       std::cout << "d["  << i << "] = " << d[i] << " ";
    }
    std::cout << std::endl;
    //    l.push_back(23);
   // for (size_t i = 0; i < l.size();  i++)
   // {
    //    std::cout << "l["  << i << "] = " << l[i] << " ";
    //}
    */
    return 0;
}
