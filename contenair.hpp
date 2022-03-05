#include "iterator.hpp"
#include <memory>
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
        
        private:
        allocator_type  _alloc;
        size_type const _max_alloc;
        size_type       _capacity;
        size_type       _size;
        T*              _p;

        public:
        ///CONSTRUCTEUR////
        template<class InputIterator>  // default
            vector(const allocator_type& alloc = allocator_type()) :  _alloc(alloc) , _max_alloc(std::allocator<T>::max_size()), _capacity(0), _size(0) , _p(NULL) 
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
            for(size_t i = 0; i < _capacity; i++)
                _alloc.destroy(&_p[i]);
            _alloc.deallocate(_p, _capacity);
        }
    
        reference operator[](size_type n){return _p[n];}
        iterator begin(){ ft::Iterator<T> a(_p); return a;}

        iterator end(){ft::Iterator<T> a(_p + 10); return a;}
        
        reverse_iterator rbegin(){ ft::reverse_iterator<ft::Iterator<T> > a(_p + 10); return a;}

        reverse_iterator rend(){ft::reverse_iterator<ft::Iterator<T> > a(_p); return a;}


    };
};