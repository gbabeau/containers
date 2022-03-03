#include "iterator.hpp"

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
        typedef std::random_access_iterator_tag iterator;
        typedef  const std::random_access_iterator_tag const_iterator;
        typedef std::ptrdiff_t difference_type;
        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef const std::reverse_iterator<const_iterator> const_reverse_iterator;
        explicit vector(const allocator_type& alloc = allocator_type()) {
            (void) alloc;
        };
        template<class InputIterator>
        vector(InputIterator firtst, InputIterator last, const allocator_type& = allocator_type());
        vector(const vector& x);
        template<class InputIterator>
            vector() {}
        ~vector() {}
        
        private:
    };
};