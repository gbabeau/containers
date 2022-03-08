#include "vector.hpp"
#include <vector>

int main()
{
   // int n[] = {10,20,30,40,50,60,70,80,90,100,110};
   // ft::vector<int> l(n , n+10);
        ft::vector<int>  d(10, 12);
   //   std::vector<int>  a(10, 12);

     d.insert(d.begin(), 100);
   //  a.insert(a.begin(),100);
     ///std::vector<int>::iterator t = a.begin();
     ft::vector<int>::iterator e = d.begin();
   //  a.insert( t + 5,100);
      d.insert( e + 5,100);
//    for (size_t i = 0; i < a.size(); i++)
  //   {
      //   std::cout << i << "  " << a[i] << std::endl;
    // }
     std::cout << std::endl;
         for (size_t i = 0; i < d.size(); i++)
     {
         std::cout << i << "  " << d[i] << std::endl;
     }
    return 0;
    /* 
    d = l;




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
