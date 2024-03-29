#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "iterator.hpp"
#include <memory>
#include <stdexcept>
#include "is_integral.hpp"
#include "enable_if.hpp"
#include "lexicograpfical_copare.hpp"
namespace ft
{
    template< class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:

        typedef T value_type;
        typedef Alloc allocator_type; 
        typedef value_type & reference;
        typedef const value_type & const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef  typename allocator_type::const_pointer const_pointer;
        typedef std::size_t size_type;
        typedef ft::Iterator<T> iterator;
        typedef ft::Iterator< const T> const_iterator;
        typedef std::ptrdiff_t difference_type;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef  ft::reverse_iterator<const_iterator> const_reverse_iterator;
        
        public:
        ///CONSTRUCTEUR////
           explicit vector(const allocator_type& alloc = allocator_type()) :  _alloc(alloc) , _max_alloc(_alloc.max_size()), _capacity(0), _size(0) , _p(_alloc.allocate(0))          // default
            {

            }


        explicit vector (size_type n, const T& val = T(), // vector
                 const allocator_type& alloc = allocator_type())  : _alloc(alloc) , _max_alloc(alloc.max_size()), _capacity(n), _size(n)
                 {
                    _p = _alloc.allocate(_size, _p);
                    for (size_t i = 0; i < n; i++)
                    this->_alloc.construct(&_p[i] , val); 
                 }

        template<class InputIterator> // range
        vector(InputIterator first, InputIterator last, const allocator_type&  alloc  = allocator_type()
        , typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL) :  _alloc(alloc) , _max_alloc(_alloc.max_size()), _capacity(0), _size(0) 
        {
            _size = std::distance(first, last);
            _capacity = _size;
            _p = _alloc.allocate(_size);
            int i = 0;
            while (first != last)
            {
                this->_alloc.construct(&_p[i++] , *first); 
                first++;
            }
        }
    

        vector(const vector& vec) :  _alloc(vec._alloc) , _max_alloc(_alloc.max_size()) , _capacity(vec._size) , _size(vec._size)
        {
            _p = _alloc.allocate(_capacity);
            for (size_t i = 0; i < _size; i++)
                this->_alloc.construct(&_p[i] , vec[i]); 
        }

        ~vector()  //destructeur
        {
            this->clear();
            _alloc.deallocate(_p, _capacity);
        }
        vector<T,allocator_type>& operator= (const vector<T,allocator_type>& x)
        {
            if (this != &x)
            {
                this->clear();
                
                if (_capacity < x._capacity)
                {
                    
                    _alloc.deallocate(_p ,_capacity);
                   _p =  _alloc.allocate(x._capacity);
                    _capacity = x._capacity;
                }
                _size = x._size; 
                for(size_type i = 0; i < _size ; i++)
                    this->_alloc.construct(&_p[i] , x[i]); 
            }
            return *this;  
        }

        //// ITERATOS ////    
        iterator begin()  {  return iterator(&_p[0]);}
        iterator end()  {iterator a(_p + _size); return a;}
        const_iterator begin() const { const_iterator a(_p); return a;}
        const_iterator end() const { const_iterator a(_p + _size); return a;}
        reverse_iterator rbegin()  { reverse_iterator a(this->end()); return a;}
        reverse_iterator rend()  {reverse_iterator a(this->begin()); return a;}
                const_reverse_iterator rbegin() const { const_reverse_iterator a(this->end()); return a;}
        const_reverse_iterator rend() const {const_reverse_iterator a(this->begin()); return a;}

        ///CAPACITY///
        size_type size() const {return _size;}
        size_type max_size() const {return _max_alloc;}


        void resize (size_type n, value_type val = value_type()) 
        {
            if (n > _size)
            {
                            if ( _capacity < _size + n)
            {
                if (_capacity * 2 <  n)
                    this->reserve(n);
                else
                    this->reserve(_capacity * 2);
            }
                for (size_t i = _size; i < n ; i++)
                    this->_alloc.construct(&_p[i] , val); 
                _size = n;
            }
            else if ( n < _size)
            {
             if (n > _size)
             {
                for (size_t i = _size ; i < n  ; i++)
                    this->_alloc.construct(&_p[i] , val); 
             } else if ( n < _size)
                    for (size_t i = n ; i < _size ; i++)
                    _alloc.destroy(&_p[i]);
                 _size = n;
            }
        
        };

        size_type capacity() const {return _capacity;}
        bool empty() const { return (_size == 0);} 
        void reserve (size_type n)
        {
            if (n > _max_alloc)
                throw std::length_error("vector::reserve");
            if (n > _capacity)
            {   
                size_t size = _size;

               T* tmp;

  
               tmp =  _alloc.allocate(n);
                
                for (size_t i = 0; i < _size; i++)
                {
                    _alloc.construct(&tmp[i], _p[i]);
                }
                this->clear();
                _alloc.deallocate(_p  ,_capacity);

                _p = tmp;
                 _size = size; 
                _capacity = n;
            }
        }

        ///ACCESS///
    reference operator[](size_type n){return _p[n];}
    const_reference operator[] (size_type n) const {return _p[n];};
    reference at (size_type n)
    {
        if (n >= _size)
            throw std::out_of_range("range_check");
        return _p[n];
    }
    const_reference at (size_type n) const
    {
        if (n >= _size)
            throw std::out_of_range("range_check");
        return _p[n];
    }
    reference front() {return _p[0];}
    const_reference front() const  {return _p[0];}
    reference back() {return _p[_size - 1];}
    const_reference back() const {return _p[_size - 1];}

    ///MODIFIERS///
    template <class InputIterator>
    void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)	
    {
        this->clear();
        _size = std::distance(first, last);
        if (_size == 0)
            return;
        if (_capacity < _size)
        {
            _alloc.deallocate(_p, _capacity);
            _capacity = _size;
            _p = _alloc.allocate(_capacity);
        }
        for (size_t i = 0; i < _size; i++)
        {
            this->_alloc.construct(&_p[i] ,*first); 
            first++;
        }
    }

    void assign (size_type n, const value_type& val)
    {
        this->clear();
        _size = n;
        if (_size == 0)
            return;
        if (_capacity < _size)
        {
            _alloc.deallocate(_p, _capacity);
            _capacity = n;
            _p = _alloc.allocate(_capacity);
        }
        for (size_t i = 0; i < _size; i++)
            this->_alloc.construct(&_p[i] ,val); 
    }

    void push_back(const T& x) {

        if (_capacity > _size)
        {
            this->_alloc.construct(&_p[_size++] , x); 
            return;
        }
        else
        {
            if (_capacity == 0)
                this->reserve(1);
            else
                this->reserve(_capacity * 2);
        }
                    this->_alloc.construct(&_p[_size++] , x); 
    };
    
    void pop_back()
    {
        if (_size != 0)
        _alloc.destroy(&_p[--_size]);
    };

    iterator insert(iterator position, const T& x)
    {
       size_type n = std::distance(this->begin(), position);   
         insert(position, 1, x);
    
        return this->begin() + n;
    }

    void insert(iterator position, size_type n, const T& x)
    {
                
        
                   
                    if (n == 0)
                        return ;
                size_type dst = std::distance(this->begin(), position);
                   
            if ( _capacity < _size + n)
            {
                if (_size * 2 < _size + n)
                    this->reserve( _size + n);
                else
                    this->reserve(_size * 2);
            }
            
            _size += n;
                            

                    for (size_t m = _size - 1; n + dst <= m; m--)
                        {  
                            //_p[m] = _p[m - n];
                            _alloc.construct(&_p[m], _p[m - n]);
                            _alloc.destroy(&_p[m - n]);
 
                    }
                    for (size_t v = 0; v < n; v++)
                    {

                        _alloc.construct(&_p[v + dst], x);

                    }
                     return;
            }


    template <class InputIterator>
    void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL )
    {
        size_type n = std::distance(first, last);
        size_type dst = std::distance(this->begin(), position);
        if (_capacity >= _size + n)
        {
            _size += n;
            
            for (size_t i = 0; i < _size; i++)
            {    
                if (position == (this->begin() + i))
                {
                    for (size_t m = _size -1; i + n <= m; m--)
                    {
                            _alloc.construct(&_p[m], _p[m - n]);
                            _alloc.destroy(&_p[m - n]);
                    }
                    for (size_t v = 0; v < n; v++)
                    {
                        _alloc.construct(&_p[v + i], *first);
                        first++;
                    }
                    return;
                }
            }
        }
        else
        {
            if (_capacity * 2 < _size + n)
                this->reserve( _size + n);
            else
                this->reserve(_capacity * 2);
                     _size += n;

                    for (size_t m = _size - 1; dst + n <= m; m--)
                    {
                            _alloc.construct(&_p[m], _p[m - n]);
                            _alloc.destroy(&_p[m - n]);
                             
                    }
                    for (size_t v = 0; v < n; v++)
                    {
                        _alloc.construct(&_p[v + dst],*first);
                        first++;
                    }
                     return;

        }

    }

    iterator erase(iterator position)
    {
        if (_size == 0 || this->end() <= position)
            return position;
        
        for (size_t i = 0; i < _size; i++)
            if (position == (this->begin() + i))
            {
         //       std::cout << "AAAAA" << std::endl;
                _alloc.destroy(&_p[i]);

                  while (++i < _size)
                  {
                      _alloc.construct(&_p[i - 1], _p[i]);
                        _alloc.destroy(&_p[i]);
                  }
                _size--;
                return position;
            }
        return position;
    }
    
    iterator erase(iterator first, iterator last)
    {
        size_t const dest = std::distance(first, last);
        size_t  deb = std::distance(this->begin(), first);
/*
        if (_size - dest > 0)
            return first;
            */

               for ( size_t n = 0;  n  != dest; n++)
               {
                     _alloc.destroy(&_p[deb + n]);
               }
               size_t i = deb + dest -1;
               while (++i  < _size)
               {
                    _alloc.construct(& _p[i - dest], _p[i]);
                        _alloc.destroy(&_p[i]);
               }
                _size -= dest;
                return first;
    }
    void swap(ft::vector<T> &x)
    {
        
        
        this->_size ^= x._size;
        x._size ^= this->_size;
        this->_size ^= x._size;

        this->_capacity ^= x._capacity;
        x._capacity ^= this->_capacity;
        this->_capacity ^= x._capacity;

        allocator_type tmp_a = this->_alloc;
        T* tmp_p = this->_p;

        this->_p = x._p;
        this->_alloc =  x._alloc;
        x._p = tmp_p;
        x._alloc = tmp_a;
    }
    void clear()
    {
            for(size_t i = 0; i < _size; i++)
                _alloc.destroy(&_p[i]);
            _size = 0;
    }
        private:
        allocator_type  _alloc;
        size_type const _max_alloc;
        size_type       _capacity;
        size_type       _size;
        T*              _p;
    };

    template <class T, class Allocator>
    void swap(vector<T,Allocator>& x, vector<T,Allocator>& y)
    {   
       x.swap(y);
    }
    template <class T, class Allocator>
    bool operator==(const vector<T,Allocator>& x,
    const vector<T,Allocator>& y) { return (y <= x && y >= x);}
template <class T, class Allocator>
bool operator!=(const vector<T,Allocator>& x,
const vector<T,Allocator>& y) { return (!(y <= x && y >= x));}
template <class T, class Allocator>
bool operator< (const vector<T,Allocator>& x,
const vector<T,Allocator>& y) { return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()));}
template <class T, class Allocator>
bool operator<=(const vector<T,Allocator>& x,
const vector<T,Allocator>& y) { return !(y < x);}


template <class T, class Allocator>
bool operator> (const vector<T,Allocator>& x,
const vector<T,Allocator>& y) { return (y < x);}
template <class T, class Allocator>
bool operator>=(const vector<T,Allocator>& x,
const vector<T,Allocator>& y) { return !(x < y);}


}
#endif
