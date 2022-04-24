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


        node() : type() , color(NOIR) ,left(NULL) , rigth(NULL) , parents(NULL)  
        {}
        node(T const & tt) : type(tt) , color(ROUGE) ,left(NULL) , rigth(NULL) , parents(NULL)  
        {

        }
        node(T const & tt, node *parentss) : type(tt), color(ROUGE)
        {
            left = NULL;
            rigth = NULL;
            parents = parentss;
            if (parents != NULL)
            {
             //   left = parents->left;
             //   rigth = parents->rigth;
            }
        }

         node(T const & tt, node *parentss, node *ri) : type(tt), color(ROUGE)
        {
            left = NULL;
            rigth = NULL;
            parents = parentss;
            if (parents != NULL)
               rigth = ri;
        }
        node(node const &node) : type(node.type) , color(node.color), left(node.left) , rigth(node.rigth) , parents(node.parents)  
        {

        }

/*
        bool father(node &a)
        {

        }

        bool brother(node &a)
        {

        }
*/
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

            node* operator--()
            {
             node *tmp = this;

            if (tmp->left != NULL)
            {
                tmp = tmp->left;
                while (tmp->rigth)
                    tmp = tmp->rigth;

              //  this = tmp;
        
                return tmp;
            }
            while (tmp->parents != NULL && tmp->parents->left == tmp)
            {
               
                tmp = tmp->parents;
            }
            tmp = tmp->parents;
          //      this = tmp;
               
            return tmp;
            }
            node* operator++()
            {
                 node *tmp = this;
           // std::cout << "AAAAAl" << tmp->type.first << std::endl;
            if (tmp->rigth != NULL )
            {
                tmp = tmp->rigth;
                while (tmp->left)
                    tmp = tmp->left;

              //  this = tmp;
                return tmp;
            }
            while (tmp->parents != NULL && tmp->parents->rigth == tmp)
                tmp = tmp->parents;
            tmp = tmp->parents;
          //      this = tmp;
            return tmp;
            }
    };
    template<class value_type>
    void swapnode(node<value_type> *l, node<value_type> *r)
    {
        node<value_type> *tmp;
        tmp = r;
        r = l;
        l = tmp;
    }
}
# endif
