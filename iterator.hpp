#ifndef ITERATOR_HPP
#define ITERATOR_HPP



#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include <iterator>
#include "reverse_iterator.hpp"

namespace ft
{

    template <class Category, class T, class Distance = std::ptrdiff_t,
    class Pointer = T*, class Reference = T&>
    struct iterator {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category iterator_category;
        };
}

namespace ft
{

template< class T >
    class Iterator : public ft::iterator<std::random_access_iterator_tag, T>
    {
        public:
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type                      value_type;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type                 difference_type;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer                         pointer;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference                       reference;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category               iterator_category;
    public:
    Iterator() : p(NULL) {}
   explicit Iterator(pointer x) : p(x) {}
    template<class U>
    Iterator(const Iterator<U>& mit) : p(mit.base()) {}

    template<class U>
    Iterator& operator=(const Iterator<U>& mit){ p = mit.base(); return *this;}
    pointer operator->() const {return &(operator*());}
   reference operator*() const {return *p;}
    reference operator[](difference_type n){return p[n];}
    Iterator& operator+=(difference_type n){ p += n; return *this;}
    Iterator& operator-=(difference_type n){ p -= n; return *this;}
    Iterator& operator++() {++p; return *this;}
    Iterator operator++(int) {Iterator tmp(*this); operator++(); return tmp;}
    Iterator& operator--() {--p; return *this;}
    Iterator operator--(int) {Iterator tmp(*this); operator--(); return tmp;}
    Iterator operator-(difference_type n) const { return Iterator(p - n);}
    Iterator operator+(difference_type n) const { return Iterator(p + n);}
    pointer base() const {return p;}
    private:
        T* p;
    };
    template< class T >
    Iterator<T> operator+(typename Iterator<T>::difference_type n, const Iterator<T> & rhs)  { return ft::Iterator<T>(&(*rhs) + n);}
    template< class TL, class TR  >
    typename ft::Iterator<TL>::difference_type operator-(const ft::Iterator<TL> & lhs, const ft::Iterator<TR> & rhs)  { return ((lhs.base()) - (rhs.base()));}
    template< class TL, class TR >
    bool operator==(const Iterator<TL>& lhs, const Iterator<TR>& rhs) {return (lhs.base() == rhs.base());}
    template< class TL, class TR >
    bool operator!=(const Iterator<TL>& lhs, const Iterator<TR>& rhs)  {return (&(*lhs) != &(*rhs));}
    template< class TL, class TR >
    bool operator>(const Iterator<TL>& lhs, const Iterator<TR>& rhs)   {return (&(*lhs) > &(*rhs));}
    template< class TL, class TR >
    bool operator<(const Iterator<TL>& lhs, const Iterator<TR>& rhs)   {return (&(*lhs) < &(*rhs));}
    template< class TL, class TR >
    bool operator>=(const Iterator<TL>& lhs, const Iterator<TR>& rhs)   {return (&(*lhs) >= &(*rhs));}
    template< class TL, class TR >
    bool operator<=(const Iterator<TL>& lhs, const Iterator<TR>& rhs)   {return (&(*lhs) <= &(*rhs));}
}
# endif
