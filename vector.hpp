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
           explicit vector(const allocator_type& alloc = allocator_type()) :  _alloc(alloc) , _max_alloc(_alloc.max_size()), _capacity(0), _size(0) , _p(NULL)          // default
            {}

        template<class InputIterator> // range
        vector(InputIterator firtst, InputIterator last, const allocator_type&  alloc  = allocator_type()) :  _alloc(alloc) , _max_alloc(alloc.max_size())
        {
            _size = std::distance(firtst, last);
            _p = _alloc.allocate(_size);
            for (size_t i = 0; i < _size; i++)
                _p[i] = firtst[i];
            _capacity = _size;
        }
    
        explicit vector (size_type n, const value_type& val = value_type(), // vector
                 const allocator_type& alloc = allocator_type())  : _alloc(alloc) , _max_alloc(alloc.max_size()), _capacity(n), _size(n)
                 {
                    _p = alloc.allocate(_size);
                    _alloc = _size;
                    for (size_t i = 0; i < n; i++)
                        _p[i] = val;
                    
                 }
        vector(const vector& vec) :  _alloc(vec._alloc) , _max_alloc(_alloc.max_size()) , _size(vec._size), _capacity(vec._capacity)
        {
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
                    _p = _alloc.allocate(x._capacity - _capacity, _p);
                    _capacity = x._capacity;
                }
                _size = x._size; 
                for(size_type i = 0; i < _size ; i++)
                    _p[0] = x._p[0];
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
                T *tmp;
                this->clear();

                tmp = _alloc.allocate(n);
                for (size_t i = 0; i < _size ; i++)
                    tmp[i] = _p[i];
                _alloc.deallocate(_p, _capacity);
                _capacity = n;
                _p = tmp;
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
    void push_back(const T& x);
    void pop_back();
    iterator insert(iterator position, const T& x);
    void insert(iterator position, size_type n, const T& x);
    template <class InputIterator>
        void insert(iterator position,
    InputIterator first, InputIterator last);
    iterator erase(iterator position);
    iterator erase(iterator first, iterator last);
    void swap(vector &x);
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