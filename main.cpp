#include "contenair.hpp"
#include <vector>
int main()
{
    int n[] = {10,20,30,40,50,60,70,80,90,100};
    std::vector<int>::iterator a(n);
    std::vector<int>::iterator b(n);
    ft::Iterator<int> d(n);
    ft::Iterator<int> c(n);
        if (c == d)
        std::cout << "c'est bon" << std::endl;
        if (a == b)
        std::cout << "c'est bon" << std::endl;
        if (c != d)
        std::cout << "c'est bon" << std::endl;
        if (a != b)
        std::cout << "c'est bon" << std::endl;

        std::cout << a[0] << std::endl;
        std::cout << d[0] << std::endl;
        int i =0;
 /*       while(i != 10)
        {
        std::cout << "a " << a[0] << std::endl;
        std::cout << "d " << d[0] << std::endl;
            a++;
            d++;
            i++;
            a -= 3;
            d -= 3;
        }*/
        i = 0;
/*
        while(i != 10)
        {
            std::cout << "a " << a[0] << std::endl;
            std::cout << "d " << d[0] << std::endl;
            a++;
            d++;
            i++;
            a = a - 3;
            d = d - 3;
        }
        */
  /*             while(i != 10)
        {
            std::cout << "a " << a[0] << std::endl;
            std::cout << "d " << d[0] << std::endl;
            a++;
            d++;
            i++;
            a = a + 3;
            d = d + 3;
        }
        */
       /*
                       while(i != 9)
        {
            std::cout << "a " << a[0] << std::endl;
            std::cout << "d " << d[0] << std::endl;
            a++;
            d++;
            i++;
             std::cout << (a - b) << std::endl;
            std::cout << (d - c) << std::endl;
        }
        */
        while(i != 9)
        {
            std::cout << "a " << a[0] << std::endl;
            std::cout << "d " << d[0] << std::endl;
        //    a++;
          //  d++;
            i++;
                a = 1 + a;
                d = 1 + d;
        }
    return 0;
}
