
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
  #include "vector.hpp"
  #include "map.hpp"
#endif

template <class Key, class T>
void	print(ft::map<Key, T>& lst)
{
	for (typename ft::map<Key, T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
  ft::map<char,int> mymap;
  ft::map<char,int>::iterator it;

  // insert some values:
  mymap['a']=10;
  mymap['b']=20;
  mymap['c']=30;
  mymap['d']=40;
  mymap['e']=50;
  mymap['f']=60;
  mymap.print_tab();
  it=mymap.find('b');

  std::cout << "found b\n" << it->second << std::endl;
  mymap.erase (it);   
 // mymap.print_tab(); 
     std::cout << "found SSS\n" << it->second << std::endl;
  return 0;           
   // erasing by iterator
  std::cout << "erase iterator to b\n";
  mymap.erase ('c');                  // erasing by key
  std::cout << "erase by key 'c'\n";
  it=mymap.find ('e');
  std::cout << "erase by range 'e' to end\n";
  mymap.erase ( it, mymap.end() );    // erasing by range

  std::cout << " display :\n";
  // show content:
  for (it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
