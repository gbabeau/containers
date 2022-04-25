#ifndef ITERATOR_MAP_HPP
# define ITERATOR_MAP_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include <iterator>
#include "node.hpp"


namespace ft {
template< class T>
    class Iterator_map : public ft::iterator<std::bidirectional_iterator_tag, T>
    {
        public:
        typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::value_type                      value_type;
        typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::difference_type                 difference_type;
        typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::pointer                         pointer;
        typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::reference                       reference;
        typedef typename ft::iterator<std::bidirectional_iterator_tag, T>::iterator_category               iterator_category;
    public:
    Iterator_map() : p(NULL) {}
   explicit Iterator_map(ft::node<T>* x) : p(x) {}
    template<class V>
    Iterator_map(const Iterator_map<V>& mit) : p(mit.base()) {}
    

    template<class V>
    Iterator_map& operator=(const Iterator_map<V>& mit){ p = mit.base(); return *this;}
     T* operator->() const {return &(operator*());}
     T& operator*() const {return p->type;}
   // reference operator[](difference_type n){return p[n];}
   // Iterator_map& operator+=(difference_type n){ p += n; return *this;}
   // Iterator_map& operator-=(difference_type n){ p -= n; return *this;}
    Iterator_map& operator++() 
    {
       p = ++(*p);

        return *this;
/*
        if (p->rigth != NULL)
            {
                p = p->rigth;
                while (p->left)
                    p = p->left;
                return *this;
            }
            while (p->parents != NULL && p->parents->rigth == p)
                p = p->parents;
            p = p->parents;
            return *this;
            */
    }

    Iterator_map operator++(int) 
    {
         Iterator_map tmp = Iterator_map(*this);
         p = ++(*p);
        return tmp;
    }
    Iterator_map& operator--() 
    {
       p = --(*p);
        return *this;
    }

    Iterator_map operator--(int) 
    {
         Iterator_map tmp =  Iterator_map(*this);
         p = --(*p);
        return tmp;

    }
    //Iterator operator-(difference_type n) const { return Iterator_map(p - n);}
    //Iterator operator+(difference_type n) const { return Iterator_map(p + n);}
    pointer pair() const {return &(p->type);}
    ft::node<T> * base() const { return  p;}
    private:
        ft::node<T> * p;
    };
        template< class TL, class TR >
     bool operator!=(const Iterator_map<TL >& lhs,
 const Iterator_map<TR >& rhs)  {return (lhs.base() != rhs.base());}
         template< class TL, class TR >
     bool operator==(const Iterator_map<TL>& lhs,
 const Iterator_map<TR>& rhs)  {return (lhs.base() == rhs.base());}
    /*
    template< class T >
    Iterator_map<T> operator+(typename Iterator_map<T>::difference_type n, const Iterator_map<T> & rhs)  { return ft::Iterator_map<T>(&(*rhs) + n);}
    template< class TL, class TR  >
    typename ft::Iterator_map<TL>::difference_type operator-(const ft::Iterator_map<TL> & lhs, const ft::Iterator_map<TR> & rhs)  { return ((lhs.base()) - (rhs.base()));}
    template< class TL, class TR >
    bool operator==(const Iterator_map<TL>& lhs, const Iterator_map<TR>& rhs) {return (lhs.base() == rhs.base());}
    template< class TL, class TR >
    bool operator>(const Iterator_map<TL>& lhs, const Iterator_map<TR>& rhs)   {return (&(*lhs) > &(*rhs));}
    template< class TL, class TR >
    bool operator<(const Iterator_map<TL>& lhs, const Iterator_map<TR>& rhs)   {return (&(*lhs) < &(*rhs));}
    template< class TL, class TR >
    bool operator>=(const Iterator_map<TL>& lhs, const Iterator_map<TR>& rhs)   {return (&(*lhs) >= &(*rhs));}
    template< class TL, class TR >
    bool operator<=(const Iterator_map<TL>& lhs, const Iterator_map<TR>& rhs)   {return (&(*lhs) <= &(*rhs));}
*/
}
#endif
