#ifndef ITERATOR_MAP_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include <iterator>


namespace ft
{

template<class Iterator> struct iterator_traits {
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
};

template< class T >
    class Iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
        public:
        typedef typename std::iterator<std::random_access_iterator_tag, T>::value_type                      value_type;
        typedef typename std::iterator<std::random_access_iterator_tag, T>::difference_type                 difference_type;
        typedef typename std::iterator<std::random_access_iterator_tag, T>::pointer                         pointer;
        typedef typename std::iterator<std::random_access_iterator_tag, T>::reference                       reference;
        typedef typename std::iterator<std::random_access_iterator_tag, T>::iterator_category               iterator_category;
    public:
    Iterator() : p(NULL) {}
   explicit Iterator(T* x) : p(x) {}
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

template<class Iterator>
class reverse_iterator : public std::iterator<typename iterator_traits<Iterator>::iterator_category,
typename iterator_traits<Iterator>::value_type,
typename iterator_traits<Iterator>::difference_type,
typename iterator_traits<Iterator>::pointer,
typename iterator_traits<Iterator>::reference>
{
        public:
        typedef Iterator                                                Iterator_type;
         typedef typename iterator_traits<Iterator>::iterator_category    Iterator_category;
         typedef typename iterator_traits<Iterator>::value_type	        value_type;
         typedef typename iterator_traits<Iterator>::difference_type      difference_type;
         typedef typename iterator_traits<Iterator>::pointer              pointer;
         typedef typename iterator_traits<Iterator>::reference            reference;
    public:
    reverse_iterator() : _current() {}
    explicit reverse_iterator(Iterator x)  : _current(x) {}
    template <class U> reverse_iterator(const reverse_iterator<U>& u) : _current(u.base()) {}
//    reverse_iterator& operator=(const reverse_iterator& mit){ p = mit.p; return *this;}
    pointer operator->() const {return &(operator*());}
    Iterator base() const {return _current;}
    reference operator*() const {Iterator tmp = _current; return *(tmp-1);}
    reference operator[](difference_type n){return _current[-n - 1];}
    reverse_iterator& operator+=(typename reverse_iterator<Iterator>::difference_type n){ /*_current -= n*/ _current = _current - n; return *this;}
     reverse_iterator& operator-=(typename reverse_iterator<Iterator>::difference_type n){ /*_current += n;*/_current = _current + n; return *this;}
    reverse_iterator& operator++() {--_current; return *this;}
    reverse_iterator operator++(int) {reverse_iterator tmp(*this); operator++(); return tmp;}
    reverse_iterator& operator--() {++_current; return *this;}
    reverse_iterator operator--(int) {reverse_iterator tmp(*this); operator--(); return tmp;}
    reverse_iterator operator-(difference_type n) const { return reverse_iterator(_current + n);}
    reverse_iterator operator+(difference_type n) const { return reverse_iterator(_current - n);}
    protected:
        Iterator _current;
    };
    
    template< class T >
    reverse_iterator<T> operator+(typename reverse_iterator<T>::difference_type n, const reverse_iterator<T> & rhs)  { return ft::reverse_iterator<T>(rhs.base() - n);}
    template< class TL, class TR >
    typename reverse_iterator<TL>::difference_type operator-(reverse_iterator<TL> & lhs, const reverse_iterator<TR> & rhs)  { return -(lhs.base() - rhs.base());}
    template< class TL, class TR >
    bool operator==(const reverse_iterator<TL>& lhs, const reverse_iterator<TR>& rhs)  {return lhs.base() == rhs.base();}
    template< class TL, class TR >
    bool operator!=(const reverse_iterator<TL>& lhs, const reverse_iterator<TR>& rhs)  {return lhs.base() != rhs.base();}
    template< class TL, class TR >
    bool operator>(const reverse_iterator<TL>& lhs, const reverse_iterator<TR>& rhs)  {return lhs.base() < rhs.base();}
    template< class TL, class TR >
    bool operator<(const reverse_iterator<TL>& lhs, const reverse_iterator<TR>& rhs) {return lhs.base() > rhs.base();}
    template< class TL, class TR >
    bool operator>=(const reverse_iterator<TL>& lhs, const reverse_iterator<TR>& rhs)  {return lhs.base() <= rhs.base();}
    template< class TL, class TR >
    bool operator<=(const reverse_iterator<TL>& lhs, const reverse_iterator<TR>& rhs)  {return lhs.base() >= rhs.base();}
};
#endif
