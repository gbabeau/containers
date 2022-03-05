#include "contenair.hpp"
#include <vector>
int main()
{
    int n[] = {10,20,30,40,50,60,70,80,90,100,110};
    std::vector<int> a(n , n+10);
    ft::vector<int> l(n , n+10);
    std::cout << *l.begin() << std::endl;
        std::cout << *a.begin() << std::endl;
            std::cout << *l.rbegin() << std::endl;
        std::cout << *a.rbegin() << std::endl;
    return 0;
}
