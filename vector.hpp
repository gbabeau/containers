#include "iterator.hpp"
#include <memory>
#include <stdexcept>
namespace ft
{
    template< class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:

        typedef T value_type;
        typedef Alloc allocator_type; 
        typedef value_type &reference;
        typedef const value_type &const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef const typename allocator_type::pointer const_pointer;
        typedef std::size_t size_type;
        typedef ft::Iterator<T> iterator;
        typedef  const ft::Iterator<T> const_iterator;
        typedef std::ptrdiff_t difference_type;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef const ft::reverse_iterator<const_iterator> const_reverse_iterator;
        
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
                        _p[i] = val;
                 }
/*
        template<class InputIterator> // range
        vector(InputIterator first, InputIterator last, const allocator_type&  alloc  = allocator_type()) :  _alloc(alloc) , _max_alloc(alloc.max_size())
        {

            std::cout << "B" << std::endl;
                _size =0;
                while (first != last)
                {
                    _size++;
                    last--;
                }
                
            _p = _alloc.allocate(_size);
            for (size_t i = 0; i < _size; i++)
                _p[i] = first++;
            _capacity = _size;
        }
    
*/
        vector(const vector& vec) :  _alloc(vec._alloc) , _max_alloc(_alloc.max_size()) , _size(vec._size), _capacity(vec._capacity)
        {
            _p = _alloc.allocate(_size);
            for (size_t i = 0; i < _size; i++)
                _p[i] = vec[i];
        }
        ~vector()  //destructeur
        {
            this->clear();
            _alloc.deallocate(_p, _capacity);
        }
        vector& operator= (const vector& x)
        {
            if (this != &x)
            {
                this->clear();
                
                if (_capacity < x._capacity)
                {
                    _alloc.deallocate(_p ,_capacity);
                    _p = _alloc.allocate(x._capacity - _capacity, _p);
                    _capacity = x._capacity;
                }
                _size = x._size; 
                for(size_type i = 0; i < _size ; i++)
                    _p[i] = x._p[i];
            }
            return *this;  
        }
        //// ITERATOS ////    
        iterator begin(){ ft::Iterator<T> a(_p); return a;}
        iterator end(){ft::Iterator<T> a(_p + _size); return a;}
        reverse_iterator rbegin(){ ft::reverse_iterator<ft::Iterator<T> > a(_p + _size); return a;}
        reverse_iterator rend(){ft::reverse_iterator<ft::Iterator<T> > a(_p); return a;}
        ///CAPACITY///
        size_type size() const {return _size;}
        size_type max_size() const {return _max_alloc;}
        void resize (size_type n, value_type val = value_type()) 
        {
            if (n > _capacity)
            {
                this->reserve(n);
                for (size_t i = _size; i < n ; i++)
                    _p[i] = val;
                _size = n;
            }
            else if ( n < _capacity)
            {
                for (size_t i = n ; i < _size  ; i++)
                    _alloc.destroy(&_p[i]);
                 _size = n;
            }
        
        };

        size_type capacity() const {return _capacity;}
        bool empty() const { return (_size == 0);} 
        void reserve (size_type n)
        {
            if (n > _capacity)
            {   
                   
              _alloc.deallocate(_p  ,_capacity);
               this->clear();
               _p =  _alloc.allocate(n, _p);
                 std::cout << "aaaa" << std::endl;
           //     _p[_size] = _size * 10;
              //  _size += 1;

                for (size_t i = 0; i < _size; i++)
                {
                    std::cout << i << " {"  << _p[i]  << "} ,";
                }
                
                  std::cout << "un" << std::endl;

                  std::cout << "deux" << std::endl;
        //        for (size_t i = 0; i < _size ; i++)
           //          (void)_p[i];
          //      _alloc.deallocate(_p, _capacity);
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
    reference back() {return _p[_size];}
    const_reference back() const {return _p[_size];}
    ///MODIFIERS///
    void push_back(const T& x) {

        if (_capacity > _size)
        {
            _p[_size++] = x;
            return;
        }
        else
        {
            T* tmp;
            tmp = _alloc.allocate(_capacity * 2);
            for (size_t i = 0; i < _size; i++)
            {            
                tmp[i] = _p[i];
            }
             this->clear();
            _alloc.deallocate(_p, _capacity);
            _capacity *= 2;
            _p = tmp; 
        }
                    _p[_size++] = x;
    };
    void pop_back()
    {
        _alloc.destroy(_p[--_size]);
    };

    iterator insert(iterator position, const T& x)
    {
        if (_capacity > _size)
        {
            T s;
            ++_size;
            for (size_t i = 0; i <_size; i++)       
                if (position == (this->begin() + i))
                {
                    s = _p[i];
                    _p[i] = x;
                    for (size_t n = i + 1; n <_size; n++)
                    {
                            _p[n] ^= s;
                            s     ^= _p[n];
                            _p[n] ^= s;
                    }       
                    return position;
                }
        }
        else
        {
            T* tmp;
            tmp = _alloc.allocate(_capacity * 2);
            int a = 0;
            _size++;
            for (size_t i = 0; i < _size; i++)
            {        
                if (position != (this->begin() + i))
                {
                    tmp[i] = _p[i - a];
                }
                else
                {
                    tmp[i] = x;
                    a = 1;
                }

            }
             this->clear();
            _alloc.deallocate(_p, _capacity);
            _capacity *= 2;
            _p = tmp; 
        } 
        return position;
    }

    void insert(iterator position, size_type n, const T& x)
    {
                _size += n;
        if (_capacity >= _size)
        {
            
            for (size_t i = 0; i < _size; i++)
            {    
                if (position == (this->begin() + i))
                {
                    for (size_t m = _size; i + n < m; m--)
                    {
                            _p[m] = _p[m - n];
                    }
                    for (size_t v = 0; v < n; v++)
                    {
                        _p[v + i] = x;
                    }
                    return;
                }
            }
        }
        else
        {
            T* tmp;
            if (_capacity * 2 < _size)
                tmp = _alloc.allocate( _size);
            else
                tmp = _alloc.allocate(_capacity * 2);
            int a = 0;
            for (size_t i = 0; i < _size; i++)
            {        
                if (position != (this->begin() + i))
                {
                    tmp[i] = _p[i - a];
                }
                else
                {
                 for (size_type m = i; i - m < n; ++i)
                        tmp[i] = x;
                    i--;
                    a = n;
                }
            }
             this->clear();
            _alloc.deallocate(_p, _capacity);
            if (_capacity * 2 < _size)
                _capacity = _size;
            else
                _capacity *= 2; 
            _p = tmp; 
        }

    }


//    template <class InputIterator>
//    void insert (iterator position, InputIterator first, InputIterator last);

    iterator erase(iterator position)
    {
        _size--;
        for (size_t i = 0; i < _size; i++)
            if (position == (this->begin() + i))
            {
                _alloc.destroy(&_p[i--]);
                while (i++ < _size)
                    _p[i] = _p[i + 1];
        
                return position;
            }
        return position;
    }
    
    iterator erase(iterator first, iterator last)
    {
       for (size_t i = 0; i < _size; i++)
            if (first == (this->begin() + i))
            {
                size_t n = 0;
                for ( n = 0; (i + n) + (this->begin()) != last; n++)
                {
                     _alloc.destroy(&_p[i + n]);
                     --_size;
                }
                --i;
                while (i++ < _size)
                    _p[i] = _p[i + n];
        
                return first;
            }
        return first;
    }
    void swap(ft::vector<T> &x)
    {
        *this ^= x;
        x ^= *this;
        *this ^= x;
    }
    void clear()
    {
            for(size_t i = 0; i < _capacity; i++)
                _alloc.destroy(&_p[i]);
    }
        private:
        allocator_type  _alloc;
        size_type const _max_alloc;
        size_type       _capacity;
        size_type       _size;
        T*              _p;
    };
    
};