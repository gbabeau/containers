#include "map.hpp"
#include <map>
int main()
{
  ft::map<int , int> a;
  std::map<int , int> b;
  std::pair<const int, int> e(10, 100);

  a.insert(ft::pair<const int, int>(10, 100));
  a.insert(ft::pair<const int, int>(5, 1000));
  a.insert(ft::pair<const int, int>(20, 1000));
      a.insert(ft::pair<const int, int>(3, 1000));
      a.insert(ft::pair<const int, int>(7, 1000));
    a.insert(ft::pair<const int, int>(25, 1000));
      a.insert(ft::pair<const int, int>(30, 1000));
      a.insert(ft::pair<const int, int>(35, 1000));
           a.insert(ft::pair<const int, int>(40, 1000));
                a.insert(ft::pair<const int, int>(45, 1000));
                     a.insert(ft::pair<const int, int>(50, 1000));
                          a.insert(ft::pair<const int, int>(55, 1000));
                               a.insert(ft::pair<const int, int>(60, 1000));
                                    a.insert(ft::pair<const int, int>(65, 1000));
                                          a.insert(ft::pair<const int, int>(35, 1000));
           a.insert(ft::pair<const int, int>(36, 1000));
                a.insert(ft::pair<const int, int>(15, 1000));
                     a.insert(ft::pair<const int, int>(20, 1000));
                          a.insert(ft::pair<const int, int>(5, 1000));
                               a.insert(ft::pair<const int, int>(10, 1000));
                                    a.insert(ft::pair<const int, int>(15, 1000));
              //    std::map<int , int>::iterator v(b.begin());
                //     std::cout << "first = " <<  v->first << " seconde = " << std::endl; 
                     ft::map<int , int>::iterator u(a.begin());
          std::cout << "first = " <<  u->first << " seconde = " << u->seconde << std::endl; 
 // b.insert(e);
/*

 
  if (b.begin() == b.end())
    ;
    do
    {
      std::cout << "first = " <<  v->first << " seconde = " << std::endl; 
    } 
    while (++v != b.end());

     std::pair<const int, int> aaa(*v);


    std::cout << aaa.first << std::endl;
  
          */
 // v++;
 // u++;
 // u = e;




  return (0);
}


/*
int main()
{
    int n[] = {10,20,30,40,50,60,70,80,90,100,110};
       ft::vector<int> l(n , n+10);
        std::vector<int> a(n , n+10);
        std::vector<int>::iterator ls(a.begin());
       std::cout << ls.base() << std::endl;
        l.insert(l.begin(), 4 , 3);
      //  a.insert(0, n+1, n+5);
       // a.insert(a.begin(), n+1, n+5);
     //   std::cout << l[0] << "  " << l[9] << std::endl;
       // std::cout << a[0] << "  " << a[9] << std::endl;
             //int n[] = {10,20,30,40,50,60,70,80,90,100,110};
   //   ft::vector<int> l(n , n+10);
      ft::vector<int>  d(10, 12);
      std::vector<int>  a(10, 12);
            ft::vector<int>  dd(10, 12);
      std::vector<int>  dd(10, 12);
  //   d.insert(d.begin(), 112);
  //   a.insert(a.begin(), 112);
     d.insert(d.begin(), 5, 100);
     a.insert(a.begin(), 5 ,  100);
    std::vector<int>::iterator t = a.begin();
      ft::vector<int>::iterator e = d.begin();
     d.insert(e+15, 4, -6);
     a.insert(t+15, 4 ,  -6);

//     std::cout << "t "<<*t << std::endl;
  //   std::cout << "e "<< *e << std::endl;

      a.erase(t + 2);
      d.erase(e + 2);
      d.erase(e+3, e+5);
      a.erase(t+3, t+5);
     std::cout << std::endl;
        for (size_t i = 0; i < d.size(); i++)
        {
            std::cout << "d "<< i << "  " << d[i] << std::endl;
            std::cout << "a "<<i << "  " << a[i] << std::endl << std::endl;
        }
    std::cout <<  "d " << d.capacity() << " " << d.size() << std::endl;
    std::cout <<  "a " << a.capacity() << " " << a.size() << std::endl;
    dd.swap(d);
    aa.swap(a);
    return (0);
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
  

    return 0;
}
*/