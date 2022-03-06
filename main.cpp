#include "vector.hpp"
#include <vector>
int main()
{
    int n[] = {10,20,30,40,50,60,70,80,90,100,110};
    std::vector<int> a(n , n+10);
    ft::vector<int> l(n , n+10);
    std::vector<int> aa(n , n+5);
    ft::vector<int> ll(n , n+5);
    std::vector<int> c;
    ft::vector<int> d;

    d = l;
    c = a;
   // c.push_back(11);
   // std::cout << "d | size : " <<d.size() << " capacity : " << d.capacity() << std::endl; 
   // std::cout << "c | size : " <<c.size() <<  " capacity : " << c.capacity() << std::endl << std::endl;

  //  d = ll;
 //   c = aa;
  //  c.push_back(11);
   // std::cout << "d | size : " <<d.size() << " capacity : " << d.capacity() << std::endl; 
 //   std::cout << "c | size : " <<c.size() <<  " capacity : " << c.capacity() << std::endl << std::endl;
//    c.resize(11);
    l.resize(11);
     //   std::cout << "c | size : " <<d.size() <<  " capacity : " << d.capacity() << std::endl << std::endl;
        std::cout << "d | size : " <<l.size() <<  " capacity : " << l.capacity() << " " << &l[0]<< std::endl << std::endl;
    c.resize(1);
    l.resize(1);
   //     std::cout << "c | size : " <<c.size() <<  " capacity : " << c.capacity() << " " << c[3]<< std::endl << std::endl;
        std::cout << "d | size : " <<l.size() <<  " capacity : " << l.capacity() << " " << &l[0]<< std::endl;
    return 0;
}
