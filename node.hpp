# ifndef NODE_HPP
#define NODE_HPP
namespace ft
{
    template <class T>
    class node
    {   
    public:
        typedef  T t_type;
    t_type       type;
    node    *left;
    node    *rigth;
    node *parents;


        node()
        {}
        node(T const & tt) : type(tt) , left(NULL) , rigth(NULL) , parents(NULL)  
        {

        }
        node(T const & tt, node parentss) : type(tt) , left(NULL) , rigth(NULL) , parents(parentss)  
        {

        }
        node(node const &node) : type(node.type) , left(node.left) , rigth(node.rigth) , parents(node.parents)  
        {

        }
        T* operator->() const {return &(operator*());}
        T& operator*() const {return type;}  
    };
}
# endif 