

namespace ft {

 template<class T1 , class T2>
    class pair
    {
    public:
        typedef  T1 first_type;
        typedef  T2 second_type;

        first_type first;
        second_type seconde;

    pair();

    template<class U, class V> pair (const pair<U,V>& pr) : first(pr.first), seconde(pr.seconde)
    {       
    }
    pair (const first_type& a, const second_type& b)
    {
        this->first = a;
        this->seconde = b;
    }

    pair& operator= (const pair& pr)
    {
        this->first = pr.first;
        this->seconde = pr.seconde;
    }


    };

    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return ( pair<T1,T2>(x,y) );
    }


    
}