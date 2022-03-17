

namespace ft {

 template<class T1 , class T2>
    class pair
    {
    public:
        typedef first_type T1;
        typedef second_type T2;



    pair();
    template<class U, class V> pair (const pair<U,V>& pr)
    {

    }
    pair (const first_type& a, const second_type& b)
    {

    }

    pair& operator= (const pair& pr)
    {

    }

    first_type first;
    second_type seconde;
    };
}