#ifndef CONST_ITERATOR_MAP_HPP
# define CONST_ITERATOR_MAP_HPP
#include "iterator_map.hpp"

namespace ft {
template< class T>
    class const_Iterator_map : public ft::iterator<std::random_access_iterator_tag, T>
    {
        public:
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type                      value_type;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type                 difference_type;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer                         pointer;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference                       reference;
        typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category               iterator_category;
    public:
    const_Iterator_map() : p(NULL) {}
   explicit const_Iterator_map(T* x) : p(x) {}
    template<class V>
    const_Iterator_map(const const_Iterator_map<V>& mit) : p(mit.base()) {}

    template<class V>
    const_Iterator_map& operator=(const const_Iterator_map<V>& mit){ p = mit.base(); return *this;}
    typename  T::t_type* operator->() const {return &(operator*());}
    typename  T::t_type& operator*() const {return p->type;}
   // reference operator[](difference_type n){return p[n];}
   // const_Iterator_map& operator+=(difference_type n){ p += n; return *this;}
   // const_Iterator_map& operator-=(difference_type n){ p -= n; return *this;}
    const_Iterator_map& operator++() 
    {
       p = ++(*p);
        return *this;

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
            
    }

    const_Iterator_map operator++(int)
    {
         const_Iterator_map tmp = const_Iterator_map(this->base());
         p = ++(*p);
        return tmp;
    }
    const_Iterator_map& operator--() 
    {
       p = --(*p);
        return *this;
    }

    const_Iterator_map operator--(int) 
    {
         const_Iterator_map tmp =  const_Iterator_map(this->base());
         p = --(*p);
        return tmp;

    }
    //Iterator operator-(difference_type n) const { return const_Iterator_map(p - n);}
    //Iterator operator+(difference_type n) const { return const_Iterator_map(p + n);}
    pointer base() const {return p;}
    private:
        T* p;
    };
        template< class TL, class TR >
     bool operator!=(const const_Iterator_map<TL>& lhs,
 const const_Iterator_map<TR>& rhs)  {return (&(*lhs) != &(*rhs));}
         template< class TL, class TR >
     bool operator==(const const_Iterator_map<TL>& lhs,
 const const_Iterator_map<TR>& rhs)  {return (&(*lhs) == &(*rhs));}


}

#endif
