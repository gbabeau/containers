# ifndef NODE_HPP
#define NODE_HPP
#define ROUGE 1
#define NOIR 2
namespace ft
{
    template <class T>
    class node
    {   
    public:
        typedef  T t_type;
    t_type       type;
    int     color;
    node    *left;
    node    *rigth;
    node *parents;


        node()
        {}
        node(T const & tt) : type(tt) , color(ROUGE) ,left(NULL) , rigth(NULL) , parents(NULL)  
        {

        }
        node(T const & tt, node parentss) : type(tt), color(ROUGE) , left(NULL) , rigth(NULL) , parents(parentss)  
        {

        }
        node(node const &node) : type(node.type) , color(node.color), left(node.left) , rigth(node.rigth) , parents(node.parents)  
        {

        }
        node & operator=(node & a)
        {
        type = a.type;
        color = a.color;
        left = a.left;
        rigth = a.rigth;
        parents = a.parents;
        }
        T* operator->() const {return &(operator*());}
        T& operator*() const {return type;}  
    };
}
# endif 