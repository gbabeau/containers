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
ft::node<value_type>* alloc_insert(const value_type& x, ft::node<value_type> *node, ft::node<value_type> *node2)
{
    std::allocator<ft::node<value_type> > _a;
    if (node == NULL)
    {
         node = _a.allocate(1);
        _a.construct(node ,ft::node<value_type>(x));
        node->parents = node2;
    }
    return (node);
}
ft::pair<iterator, bool> insert(const value_type& x)
{
    if (_node == NULL)
    {
        _node = alloc_insert(x, _node, NULL);
        _node->color = NOIR;
    }
    else
    {
        node<value_type> *tmp = _node;
        do
        {
            if (tmp->type.first > x.first)
                tmp = alloc_insert(x, tmp->left, tmp);
            else
                tmp = alloc_insert(x, tmp->rigth, tmp);
        } while (tmp->left != NULL || tmp->rigth != NULL);
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