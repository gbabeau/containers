#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

namespace ft
{
template<class Iterator> struct iterator_traits {
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
    typedef typename Iterator::iterator_category iterator_category;
    };
}

namespace ft
{

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
    
} // namespace ft
#endif
