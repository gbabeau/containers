#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include <iterator>

/*
namespace ft
{

    template <class Category, class T, class Distance = std::ptrdiff_t,
    class Pointer = T*, class Reference = T&>
    struct iterator {
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef std::  iterator_category;
        };
};
*/

namespace ft
{

template<class Iterator> struct iterator_traits {
typedef typename Iterator::difference_type difference_type;
typedef typename Iterator::value_type value_type;
typedef typename Iterator::pointer pointer;
typedef typename Iterator::reference reference;
typedef typename Iterator::iterator_category iterator_category;
};

template< typename T >
    class Iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
        public:
        typedef T                               value_type;
        typedef std::ptrdiff_t                  difference_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::random_access_iterator_tag iterator_category;
    public:
    Iterator() : p(NULL) {}
    Iterator(T* x) : p(x) {}
    Iterator(const Iterator& mit) : p(mit.p) {}
    Iterator<T>& operator=(const Iterator& mit){ p = mit.p; return *this;}
    pointer operator->() const {return &(operator*());}

    reference operator*() const {return *p;}
    reference operator[](difference_type n){return p[n];}
    Iterator& operator+=(difference_type n){ p += n; return *p;}
    reference operator-=(difference_type n){ p -= n; return *p;}
    Iterator& operator++() {++p; return *this;}
    Iterator operator++(T) {Iterator tmp(*this); operator++(); return tmp;}
    Iterator& operator--() {--p; return *this;}
    Iterator operator--(T) {Iterator tmp(*this); operator--(); return tmp;}
    Iterator operator-(difference_type n) const { return Iterator(p - n);}
    Iterator operator+(difference_type n) const { return Iterator(p + n);}
    private:
        T* p;
    };
    template< typename T >
    Iterator<T> operator+(typename Iterator<T>::difference_type n, const Iterator<T> & rhs)  { return ft::Iterator<T>(&(*rhs) + n);}
    template< typename T >
    typename Iterator<T>::difference_type operator-(Iterator<T> & lhs, const Iterator<T> & rhs)  { return (&(*lhs) - &(*rhs));}
    template< typename T >
    bool operator==(const Iterator<T>& lhs, const Iterator<T>& rhs) {return (&(*lhs) == &(*rhs));}
    template< typename T >
    bool operator!=(const Iterator<T>& lhs, const Iterator<T>& rhs)  {return (&(*lhs) != &(*rhs));}
    template< typename T >
    bool operator>(const Iterator<T>& lhs, const Iterator<T>& rhs)  {return (&(*lhs) > &(*rhs));}
    template< typename T >
    bool operator<(const Iterator<T>& lhs, const Iterator<T>& rhs)  {return (&(*lhs) < &(*rhs));}
    template< typename T >
    bool operator>=(const Iterator<T>& lhs, const Iterator<T>& rhs)  {return (&(*lhs) >= &(*rhs));}
    template< typename T >
    bool operator<=(const Iterator<T>& lhs, const Iterator<T>& rhs)  {return (&(*lhs) <= &(*rhs));}

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
    reverse_iterator() : p(NULL) {}
    explicit reverse_iterator(Iterator x)  {}
    template <class U> reverse_iterator(const reverse_iterator<U>& u) {};
    reverse_iterator<T>& operator=(const reverse_iterator& mit){ p = mit.p; return *this;}
    pointer operator->() const {return &(operator*());}

    reference operator*() const {return *p;}
    reference operator[](difference_type n){return p[n];}
    reverse_iterator& operator+=(difference_type n){ p += n; return *p;}
    reference operator-=(difference_type n){ p -= n; return *p;}
    reverse_iterator& operator++() {++p; return *this;}
    reverse_iterator operator++(T) {reverse_iterator tmp(*this); operator++(); return tmp;}
    reverse_iterator& operator--() {--p; return *this;}
    reverse_iterator operator--(T) {reverse_iterator tmp(*this); operator--(); return tmp;}
    reverse_iterator operator-(difference_type n) const { return reverse_iterator(p - n);}
    Iterator operator+(difference_type n) const { return reverse_iterator(p + n);}
    private:
        T* p;
    };
    /*
    template< typename T >
    Iterator<T> operator+(typename Iterator<T>::difference_type n, const Iterator<T> & rhs)  { return ft::Iterator<T>(&(*rhs) + n);}
    template< typename T >
    typename Iterator<T>::difference_type operator-(Iterator<T> & lhs, const Iterator<T> & rhs)  { return (&(*lhs) - &(*rhs));}
    template< typename T >
    bool operator==(const Iterator<T>& lhs, const Iterator<T>& rhs) {return (&(*lhs) == &(*rhs));}
    template< typename T >
    bool operator!=(const Iterator<T>& lhs, const Iterator<T>& rhs)  {return (&(*lhs) != &(*rhs));}
    template< typename T >
    bool operator>(const Iterator<T>& lhs, const Iterator<T>& rhs)  {return (&(*lhs) > &(*rhs));}
    template< typename T >
    bool operator<(const Iterator<T>& lhs, const Iterator<T>& rhs)  {return (&(*lhs) < &(*rhs));}
    template< typename T >
    bool operator>=(const Iterator<T>& lhs, const Iterator<T>& rhs)  {return (&(*lhs) >= &(*rhs));}
    template< typename T >
    bool operator<=(const Iterator<T>& lhs, const Iterator<T>& rhs)  {return (&(*lhs) <= &(*rhs));}
    */
};


/*
    template <class Iterator>
    class iterator_traits {
        typedef  Iterator              value_type;
        typedef std::ptrdiff_t  difference_type;
        typedef *Iterator      pointer;
        typedef &Iterator      reference;
        typedef Category        iterator_category;
        };

    template <class T>
    class iterator_traits<T*> {
        typedef  T*             value_type;
        typedef std::ptrdiff_t  difference_type;
        typedef T               pointer;
        typedef &T*             reference;
        typedef Category  iterator_category;
        };

    template <class T>
    class iterator_traits<const T*> {
        typedef  T*         value_type;
        typedef std::ptrdiff_t  difference_type;
        typedef T   pointer;
        typedef & T* reference;
        typedef Category  iterator_category;
        };

template <class Iterator>
    class reverse_iterator
    {
        public:
        typedef iterator_traits<Iterator>::value_type           value_type;
        typedef iterator_traits<Iterator>::difference_type      difference_type;
        typedef iterator_traits<Iterator>::pointer              pointer;
        typedef iiterator_traits<Iterator>::reference           reference;
        typedef iterator_traits<Iterator>::iterator_category    iterator_category;
        reverse_iterator() {}
        explicit reverse_iterator (iterator_type it) {}
        template <class Iter>
        reverse_iterator (const reverse_iterator<Iter>& rev_it)
        {}
        private:
            iterator *value_type; 

    };
*/


