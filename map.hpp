# ifndef MAP_HPP
#define MAP_HPP

#include "iterator_map.hpp"
#include <memory>
#include <stdexcept>
#include <functional>
#include "is_integral.hpp"
#include "enable_if.hpp"
#include "lexicograpfical_copare.hpp"
#include "node.hpp"
#include "pair.hpp"

namespace ft {


template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
class map {
public:
// types:
typedef Key key_type;
typedef T mapped_type;
typedef ft::pair<const Key, T> value_type;
typedef Compare key_compare;
typedef Allocator allocator_type;
typedef typename Allocator::reference reference;
typedef typename Allocator::const_reference const_reference;

        typedef std::size_t size_type;
        typedef ft::Iterator< ft::node<value_type> > iterator;
        typedef ft::Iterator< const ft::node<value_type> > const_iterator;
        typedef std::ptrdiff_t difference_type;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef  ft::reverse_iterator<const_iterator> const_reverse_iterator;

//typedef implementation defined iterator;  See 23.1
//typedef implementation defined const_iterator;  See 23.1
//typedef implementation defined size_type;  See 23.1
//typedef implementation defined difference_type;  See 23.1
typedef typename Allocator::pointer pointer;
typedef typename Allocator::const_pointer const_pointer;
//typedef std::reverse_iterator<iterator> reverse_iterator;
//typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
class value_compare
: public std::binary_function<value_type,value_type,bool> {
friend class map;
protected:
Compare comp;

value_compare(Compare c) : comp(c) {}
public:
bool operator()(const value_type& x, const value_type& y) const {
return comp(x.first, y.first);
}
};
// 23.3.1.1 construct/copy/destroy:
explicit map(const Compare& comp = Compare(),
const Allocator& = Allocator())
{
   _node = NULL;
    (void) comp;
}
template <class InputIterator>
map(InputIterator first, InputIterator last,
const Compare& comp = Compare(), const Allocator& = Allocator());
map(const map<Key,T,Compare,Allocator>& x)
{
    (void)x;
}
~map()
{   
}
map<Key,T,Compare,Allocator>&
operator=(const map<Key,T,Compare,Allocator>& x);
// iterators:
iterator begin()
{
    node<value_type> *tmp = _node;

    while (tmp->left != NULL)
        tmp = tmp->left;
    return (iterator(tmp));
}
const_iterator begin() const;
iterator end();
const_iterator end() const;
reverse_iterator rbegin();
const_reverse_iterator rbegin() const;
reverse_iterator rend();
const_reverse_iterator rend() const;
// capacity:
bool empty() const;
size_type size() const;
size_type max_size() const;
// 23.3.1.2 element access:
T& operator[](const key_type& x)
{
    node<value_type> *tmp = _node;

    while ( (tmp->left != NULL || tmp->rigth != NULL) && tmp->type.first != x)
    {
        if (tmp->type.first > x)
            tmp = tmp->left;
        else
            tmp = tmp->rigth;
    }

    if (tmp->type.first == x)
        return tmp->type.seconde;
    T *a = new T();
    return *a;
}
// modifiers:


   void rotate(ft::node<value_type> *GP, ft::node<value_type> *P, ft::node<value_type> *F)
   {
          //     std::cout << "AAAAAAAAAAAAAAAAS" << std::endl;
       P->parents = GP->parents;
       GP->parents = P;
       if (GP->left == P)
            GP->left = F;
        else
            GP->rigth = F;
        if (F != NULL)
            F->parents = GP;
        if (P->left == F)
            P->left = GP;
        else
            P->rigth = GP;
                 //     std::cout << "AAAAAAAAAAAAAAAAS" << std::endl;
       
                          //   std::cout << "AAAAAAAAAAAAAAAAS" << std::endl;

       //GP->left = P->rigth;
       //GP->left->parents = GP;
   //     std::cout << "AAAAAAAAAAAAAAAAS" << std::endl;
      //  std::cout << "AAAAAAAAAAAAAAAAS" << std::endl;
       //P->rigth = GP;
       //P->rigth->parents = P;

   }
void equilibre(ft::node<value_type> *tmp)
{
   std::cout << "equilibre " << tmp->parents->color << std::endl;

    if (tmp->parents->color == NOIR || tmp->parents->parents == NULL)
        return;
    int col = ROUGE;

    if (tmp->parents->parents->left == NULL || tmp->parents->parents->rigth == NULL || tmp->parents->parents->left->color == NOIR || tmp->parents->parents->rigth->color == NOIR)
        col = NOIR;
    if (col == ROUGE)
    {
        std::cout << "cas 1 equilibre" << std::endl;
        tmp->parents->parents->left->color = NOIR;
        tmp->parents->parents->rigth->color = NOIR;
        tmp->parents->parents->color = ROUGE;
    }
    else
    {
        std::cout << "AAAAAAAAAAAAAAAAS" << std::endl;
        if (tmp->parents->parents->left == tmp->parents)
        {
            
            if (tmp->parents->left != tmp)
            {
                rotate(tmp->parents, tmp,  tmp->left);
                tmp->left->color = ROUGE;
                tmp->rigth->color = ROUGE;
                tmp->color = NOIR;
                equilibre(tmp);
            }
            else
            {
            rotate(tmp->parents->parents, tmp->parents, tmp->parents->rigth);
                std::cout << "AAAAAA" << std::endl;
                tmp->parents->color = NOIR;
                tmp->parents->rigth->color = ROUGE;
                equilibre(tmp->parents);
            }
        }
        else
        {
               if (tmp->parents->rigth != tmp)
               {
                       rotate(tmp->parents, tmp, tmp->rigth);
                    rotate(tmp->parents->parents, tmp->parents,  tmp->parents->left);
                tmp->left->color = ROUGE;
                tmp->rigth->color = ROUGE;
                tmp->color = NOIR;
                equilibre(tmp);
               }
               else
               {
                   std::cout << "AAAAAA" << std::endl;
                rotate(tmp->parents->parents, tmp->parents,  tmp->parents->left);
                std::cout << "AAAAAA" << std::endl;
                tmp->parents->color = NOIR;
                std::cout << "AAAAAA" << std::endl;
                tmp->parents->left->color = ROUGE;
                std::cout << "AAAAAA" << std::endl;
                equilibre(tmp->parents);
               }
        }   
    }
}

ft::node<value_type>* alloc_insert(const value_type& x, ft::node<value_type> *node, ft::node<value_type> *node2)
{
    std::allocator<ft::node<value_type> > _a;
    if (node == NULL)
    {
        std::cout << "insert" << std::endl;
         node = _a.allocate(1);
        _a.construct(node ,ft::node<value_type>(x));
        node->parents = node2;
    }
    return (node);
}

ft::pair<iterator, bool> insert(const value_type& x)
{
        std::allocator<ft::node<value_type> > _a;
    if (_node == NULL)
    {
         std::cout << "racine mise" << std::endl;
        _node = alloc_insert(x, _node, NULL);
        _node->color = NOIR;
            return ft::pair<iterator, bool>();
    }
    else
    {
        node<value_type> *tmp = _node;
        while (tmp != NULL)
        {
            std::cout << "AAAAAAAAAAAa" << std::endl;
            if (tmp->type.first > x.first)
            {
                    if (tmp->left == NULL)
                    {
                    std::cout << "insert" << std::endl;
                        tmp->left = _a.allocate(1);
                        _a.construct(tmp->left ,ft::node<value_type>(x));
                    tmp->left->parents = tmp;
                    tmp = tmp->left;
                    break;
                    }
                    tmp = tmp->left;
                /*
                tmp = alloc_insert(x, tmp->left, tmp);
                std::cout << "left enfant" << std::endl;
                */
            }
            else
            {
                    if (tmp->rigth == NULL)
                    {
                        std::cout << "insert" << std::endl;
                        tmp->rigth = _a.allocate(1);
                        _a.construct(tmp->rigth ,ft::node<value_type>(x));
                        tmp->rigth->parents = tmp;
                        tmp = tmp->rigth;
                        break;
                    }
                    tmp = tmp->rigth;
            }
        } 
        std::cout << "LAAAAA" <<std::endl;
         if (tmp != NULL)
        equilibre(tmp);
    }
    return ft::pair<iterator, bool>();
}
iterator insert(iterator position, const value_type& x);

template <class InputIterator>
void insert(InputIterator first, InputIterator last);
void erase(iterator position);
size_type erase(const key_type& x);
void erase(iterator first, iterator last);
void swap(map<Key,T,Compare,Allocator>&);
void clear();
// observers:
key_compare key_comp() const;
value_compare value_comp() const;


iterator find(const key_type& x);
const_iterator find(const key_type& x) const;
size_type count(const key_type& x) const;
iterator lower_bound(const key_type& x);
const_iterator lower_bound(const key_type& x) const;
iterator upper_bound(const key_type& x);
const_iterator upper_bound(const key_type& x) const;
ft::pair<iterator,iterator>
equal_range(const key_type& x);
ft::pair<const_iterator,const_iterator>
equal_range(const key_type& x) const;
    private:
        node<value_type>    *_node;
        allocator_type      _alloc;

};

template <class Key, class T, class Compare, class Allocator>bool operator==(const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>bool operator< (const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>bool operator!=(const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>bool operator> (const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>bool operator>=(const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y);
template <class Key, class T, class Compare, class Allocator>bool operator<=(const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y);
//specialized algorithms:
template <class Key, class T, class Compare, class Allocator>void swap(map<Key,T,Compare,Allocator>& x,map<Key,T,Compare,Allocator>& y);

}
# endif 