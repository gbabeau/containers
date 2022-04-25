# ifndef MAP_HPP
#define MAP_HPP

#include "vector.hpp"
#include "const_iterator_map.hpp"
#include <functional>
#include "node.hpp"
#include <unistd.h>


#define RESET   "\033[0m"
#define BLACKCOLOR   "\033[30m"      /* Black */
#define REDCOL    "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"       /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"


namespace ft {
template<class Key ,class T,  class Compare>
    bool pred_map(ft::pair<const Key, T> a, ft::pair<const Key, T> b)
    {
        Compare c = Compare();
        return (!c(a.first, b.first) &&  !c(b.first, a.first) && a.second == b.second);   
    }   
    template<class Key ,class T,  class Compare>
    bool lac(ft::pair<const Key, T> a, ft::pair<const Key, T> b)
    {
        Compare c = Compare();
        (void) c;
        return ( (a.first < b.first  && a.second < b.second));   
    }   

template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
class map {
public:
// types:
typedef Key key_type;
typedef T mapped_type;
typedef ft::pair<const Key, T> value_type;
typedef Compare key_compare;
typedef Allocator allocator_type;
typedef typename Allocator::reference reference;
typedef typename Allocator::const_reference const_reference;

        typedef std::size_t size_type;
        typedef ft::Iterator_map< value_type > iterator;
        typedef ft::Iterator_map< value_type > const_iterator;
        typedef std::ptrdiff_t difference_type;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef  ft::reverse_iterator<const_iterator> const_reverse_iterator;

//typedef implementation defined iterator;  See 23.1
//typedef implementation defined const_iterator;  See 23.1
//typedef implementation defined size_type;  See 23.1
//typedef implementation defined difference_type;  See 23.1
typedef typename Allocator::pointer pointer;
typedef typename Allocator::const_pointer const_pointer;
//typedef std::reverse_iterator<iterator> reverse_iterator;
//typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
class value_compare
: public std::binary_function<value_type,value_type,bool> {
friend class map;
protected:
Compare comp;

value_compare(Compare c) : comp(c)  {}
public:
bool operator()(const value_type& x, const value_type& y) const {
return comp(x.first, y.first);
}
};
// 23.3.1.1 construct/copy/destroy:
explicit map(const Compare& comp = Compare(),
const Allocator& = Allocator())  : _node(NULL), _ptrdeb(NULL), _ptrfin(NULL) , _size(0) , _comp(comp)
{
    std::allocator<ft::node<value_type> > _a;
   _node = NULL;
    (void) comp;
    _ptrfin = _a.allocate(1);
    std::cout << "cette entre" << std::endl;    
     _a.construct(_ptrfin , ft::node<value_type>(value_type(key_type(), mapped_type()), _node));
     _ptrdeb = _ptrfin;
}

template <class InputIterator>
map(InputIterator first, InputIterator last,
const Compare& comp = Compare(), const Allocator& = Allocator()) : _node(NULL), _ptrdeb(NULL), _ptrfin(NULL) , _size(0) , _comp(comp)
{
     std::allocator<ft::node<value_type> > _a;
    _ptrfin = _a.allocate(1);    
     _a.construct(_ptrfin , ft::node<value_type>(value_type(key_type(), mapped_type()), _node));
     _ptrdeb = _ptrfin;
     this->insert(first, last);
}

map(const map<Key,T,Compare,Allocator>& x) : _node(NULL), _ptrdeb(NULL), _ptrfin(NULL) , _size(0) , _comp(Compare())
{
    std::allocator<ft::node<value_type> > _a;
   _ptrfin = _a.allocate(1);
     _a.construct(_ptrfin ,ft::node<value_type>());
    (void)x;
}
~map()
{   
    std::allocator<ft::node<value_type> > _a;
    this->clear();
    
    _a.destroy(_ptrfin);
    _a.deallocate(_ptrfin, 1);
}
map<Key,T,Compare,Allocator>&
operator=(const map<Key,T,Compare,Allocator>& x)
{
    this->clear();
    this->insert(iterator(x._ptrdeb), iterator(x._ptrfin));

    return *this;
}
// iterators:
iterator begin()
{
  //  std::cout << "AAAAAAA" << std::endl;
  /*  node<value_type> *tmp = _node;

    while (tmp->left != NULL)
        tmp = tmp->left;*/
    return (iterator(_ptrdeb));
}
const_iterator begin(void) const { return (const_iterator(_ptrfin)); }
iterator end(void) {
    return (iterator(_ptrfin));}
const_iterator end(void) const { return (iterator(_ptrfin));};
reverse_iterator rbegin(void) { return (reverse_iterator(this->end()));};
const_reverse_iterator rbegin(void) const { return (const_reverse_iterator(this->end()));};
reverse_iterator rend(void){ return (reverse_iterator(this->begin()));};
const_reverse_iterator rend(void) const { return (const_reverse_iterator(this->begin()));};
// capacity:
bool empty() const {return (_size == 0);};
size_type size() const {return (_size);};
size_type max_size() const {return ( _alloc.max_size());};
// 23.3.1.2 element access:
T& operator[](const key_type& x)
{
    node<value_type> *tmp = _node;
    if (_node == NULL)
    {
        _node = this->node_construct( NULL , _node, ft::node<value_type>(value_type(x, mapped_type())));
        _ptrdeb = _node;
        _node->rigth = _ptrfin;  
        _node->color = NOIR;
        return _node->type.second;
    }
    while ((tmp->left != NULL || (tmp->rigth != NULL && tmp->rigth != _ptrfin)) && tmp->type.first != x)
    {
            
        if ( _comp(tmp->type.first,x) && (tmp->rigth && tmp->rigth != _ptrfin) )
            tmp = tmp->rigth;
        else if ( _comp(x ,tmp->type.first) && tmp->left)
            tmp = tmp->left;
        else
        {
           //  std::cout << "WHILE22" << std::endl;
            break;
        }
       // std::cout << "WHILE" << std::endl;
    }
 //   std::cout << "AAAAA" << std::endl;
    if (tmp && (tmp->left != NULL || (tmp->rigth != NULL && tmp->rigth != _ptrfin)) && tmp->type.first == x)
        return tmp->type.second;
  //  std::cout << "AAAAA" << std::endl;
    return this->insert_node(tmp, value_type(x, mapped_type())).first->second;
}
// modifiers:
    bool st_tab(ft::node<value_type> **tmp, int n)
    {
        int i = 0;
        while (i != n && (tmp[i] == NULL || tmp[i] == _ptrfin))
            i++;
    return !(i == n);
    }

    void print_tmp(ft::node<value_type> **tmp, int n)
    {
        int i = 0;
        while (i != n)
        {
            if (tmp[i] == NULL || tmp[i] == _ptrfin)
            {
                std::cout << "|ED|";
            }
            else
            {
                if (tmp[i]->color == ROUGE)
                    std::cout << REDCOL << "|"<< tmp[i]->type.first << "|" << RESET;
                else
                    std::cout << "|"<< tmp[i]->type.first <<"|";
            }
            if ( 1 == i%2)
            std::cout << " ";
            i++;
        }
        std::cout << std::endl;
    }

    ft::node<value_type> **init_tmp( ft::node<value_type> **tmp, int n)
    {
        int i = 0;
           ft::node<value_type>  **tmp2 = new node<value_type>*[n * 2];
         while (i != n)
        {

 
            if (tmp[i] == NULL ||tmp[i] == _ptrfin)
            {
                tmp2[i * 2] = NULL;
                tmp2[i * 2 + 1] = NULL;
            }
            else
            {
                    tmp2[i*2] = tmp[i]->left;
                    tmp2[i*2 + 1] = tmp[i]->rigth;
            }
            i++;
        }
            return tmp2;
    }

    void print_tab()
    {
        if (_node == NULL)
        {


            std::cout << "VIDEE" << std::endl;
            return;
        }
        ft::node<value_type>    **tmp = new ft::node<value_type>*[1];
        //malloc( sizeof(ft::node<value_type>*) * 1);
        int                     n = 1;
        ft::node<value_type>  **tmp2 = NULL;
        int i = 0;

        tmp = &_node;
        while (st_tab(tmp, n))
        {
            print_tmp(tmp, n);
            tmp2 = init_tmp( tmp, n);
            usleep(250000);
         //   delete [] *tmp;
            n *= 2;
            tmp = tmp2;
            i++;
     //   std::cout << "NOMBRE DE LIGNE " << i << std::endl;
        }
    //    std::cout << std::endl <<"NOMBRE DE LIGNE " << i << std::endl;
    std::cout << " _ptrfin : "<< _ptrfin->parents->type.first << std::endl;

    if (_ptrfin->parents->rigth == _ptrfin)
        std::cout << " _ptrfin : "<< "OK" << std::endl;
    else
        std::cout << " _ptrfin : "<< "KO" << std::endl;

            if (_node->parents == NULL)
        std::cout << " NODE : "<< "OK" << std::endl;
    else
        std::cout << " NODE : "<< "KO" << std::endl;
    
    }

    void color(ft::node<value_type> *GP, ft::node<value_type> *P)
    {
        GP->parents->color = NOIR;
        if (P->left != NULL)
            P->left->color = ROUGE;
        if (P->rigth != NULL)
            P->rigth->color = ROUGE;

    }

     void color2(ft::node<value_type> *GP)
     {
          GP->color = ROUGE;
        if (GP->left != NULL)
            GP->left->color = NOIR;
        if (GP->rigth != NULL)
            GP->rigth->color = NOIR;

     }

   void rotate(ft::node<value_type> *GPP, ft::node<value_type> *GP, ft::node<value_type> *P, ft::node<value_type> *F, int i)
   {
                if (GPP != NULL)
                {
                    if (GPP->left == GP)
                        GPP->left = P;
                    else
                        GPP->rigth = P;
                }
                else
                    _node = P;
        P->parents = GPP;
        if (GP->left == P)
            GP->left = F;
        else
            GP->rigth = F;

        //if (F)
        //std::cout << "FF == "<<F->type.first << std::endl;
        if (P->left == F && i != 0)
            P->left = GP;
        else
            P->rigth = GP;
       P->parents = GP->parents;
       GP->parents = P;
        if (F != NULL)
            F->parents = GP;
       if (i == 1)
            color(GP, P);
   }

void equilibre(ft::node<value_type> *tmp)
{
    if (tmp == NULL || tmp->parents == NULL || tmp->parents->parents == NULL)
    {
         _node->color = NOIR;
        return;
    }
    if (tmp->color == NOIR)
    {
        equilibre(tmp->parents);
       return ;
    }
    int col = NOIR;
    if ((tmp->parents->parents->left != NULL && tmp->parents->parents->left->color == ROUGE ) &&  (tmp->parents->parents->rigth != NULL && tmp->parents->parents->rigth != _ptrfin && tmp->parents->parents->rigth->color == ROUGE))
        col = ROUGE;
    if (col == ROUGE)
    {   
     //   std::cout << "cas 0" << std::endl;
        color2(tmp->parents->parents);
         equilibre(tmp->parents->parents);
         _node->color = NOIR;
         return;
    }
    else if (tmp->parents->color == ROUGE)
    {
        if (tmp->parents->parents->left == tmp->parents)
        {
            if (tmp->parents->rigth == tmp)
            {
                //std::cout << "cas 1" << std::endl;
                rotate(tmp->parents->parents ,tmp->parents, tmp, tmp->left,-1);
                rotate(tmp->parents->parents ,tmp->parents, tmp, tmp->rigth,1);
                equilibre(tmp->parents);
            }
            else
            {
               //   std::cout << "cas 2" << std::endl;
                rotate(tmp->parents->parents->parents ,tmp->parents->parents, tmp->parents, tmp->parents->rigth, 1);
                equilibre(tmp->parents->parents);
            }
        }
        else
        {
               if (tmp->parents->left == tmp)
               {
              //     std::cout << "cas 3" << std::endl;
                rotate(tmp->parents->parents ,tmp->parents, tmp, tmp->rigth, 0);
                rotate(tmp->parents->parents ,tmp->parents, tmp, tmp->left,1);
                return;
                //equilibre(tmp->parents);
               }
               else
               {
               //    std::cout << "cas 4 " << tmp->type.first << std::endl;

                rotate(tmp->parents->parents->parents, tmp->parents->parents, tmp->parents,  tmp->parents->left, 1);
                return;
                //equilibre(tmp->parents->parents);
               }
        }   
    }
  //  equilibre(tmp->parents);
}

ft::node<value_type>* alloc_insert(const value_type& x, ft::node<value_type> *node, ft::node<value_type> *node2)
{
    std::allocator<ft::node<value_type> > _a;
    if (node == NULL)
    {
     //   std::cout << "insert" << std::endl;
         node = _a.allocate(1);
        _a.construct(node ,ft::node<value_type>(x));
        node->parents = node2;
        _size++;
    }
    return (node);
}


node<value_type>* node_construct( node<value_type> *node_p ,node<value_type>* node_f, node<value_type> node_new)
{
                        std::allocator<ft::node<value_type> > _a;
                        node_f = _a.allocate(1);
                         _size++;
                        _a.construct(node_f , ft::node<value_type>(node_new));
                        if (node_f->parents != NULL)
                     //   std::cout <<std::endl <<"P " << node_f->parents->type.first << std::endl;
                        node_f->parents = node_p;
                         return node_f;
}

ft::pair<iterator,bool> insert_node(ft::node<value_type> *nodes, const value_type& x)
{
       node<value_type> *tmp = nodes;
        while (tmp != NULL)
        {
            if (_comp(x.first, tmp->type.first))
            {
                    if (tmp->left == NULL) 
                    {
                        tmp->left = this->node_construct(tmp ,tmp->left, ft::node<value_type>(x, tmp));
                        tmp = tmp->left;
                        if (tmp->parents == _ptrdeb)
                            _ptrdeb = tmp;
                        break;
                    }
                    tmp = tmp->left;
            }
            else if (_comp( tmp->type.first, x.first))
            {
                    if (tmp->rigth == NULL || tmp->rigth == _ptrfin) 
                    {
                        tmp->rigth = this->node_construct(tmp, tmp->rigth, ft::node<value_type>(x, tmp, tmp->rigth));
                        tmp = tmp->rigth;
                        if (tmp->rigth == _ptrfin)
                            _ptrfin->parents = tmp;
                        break;
                    }
                    tmp = tmp->rigth;
            }
            else
                return ft::pair<iterator, bool>(iterator(tmp), false);
                
        }
      //  std::cout << "sorti" << x.first  << std::endl;
         if (tmp != NULL && tmp->parents->color == ROUGE)     
                    equilibre(tmp);
      //  std::cout << "sorti" << x.first  << std::endl;
        return ft::pair<iterator, bool>(iterator(tmp), true);
}



ft::pair<iterator, bool> insert(const value_type& x)
{
        std::allocator<ft::node<value_type> > _a;
    if (_node == NULL)
    {
        _node = this->node_construct( NULL , _node, ft::node<value_type>(x));
        _ptrdeb = _node;
        _node->rigth = _ptrfin;  
        _node->color = NOIR;
        return ft::pair<iterator, bool>(iterator(_node), true);
    }
    return insert_node(_node,  x);
}

iterator insert(iterator position, const value_type& x)
{
    ft::node<value_type> *tmp = _node;

    if ( _comp( x.first , position->first))
    {
     //   std::cout << "TAMER" << std::endl;
        ++position;
    if (_comp( position->first, x.first))
    {
      //  std::cout << "OUI" << std::endl;
        tmp = position.base();
    }   
    }
   // std::cout << "TAMER" << std::endl;
        
    return  insert_node(tmp, x).first;

}

template <class InputIterator>
void insert(InputIterator first, InputIterator last)
{
    while (first != last)
        insert((first++).base()->type);
}


void rotatedelet(node<value_type> *tmp2, node<value_type> *frere)
{

    if (frere->parents->left == frere)
    {
        if (frere->left != NULL && frere->left->color == ROUGE)
        {
            rotate(tmp2->parents ,tmp2, frere, frere->rigth, 0);
            return;
        }
        else
        {
            //std::cout << "cas 1 " << frere->rigth->rigth << " " << tmp2 << "  " << frere->rigth->left<< std::endl;
                rotate(tmp2 ,frere, frere->rigth,  frere->rigth->rigth, -1);
             //this->print_tab();
             //std::cout << "cas 1 " <<  tmp2->type.first << " " << frere->parents->rigth << std::endl;
                rotate(tmp2->parents , tmp2, frere->parents,  frere->parents->rigth, 0);
                return;
        }

    }
    else
    {

  //  std::cout << "cas 1 " << frere->rigth->rigth << " " << tmp2 << " FFFFF " << frere->rigth->left<< std::endl;
        if (frere->rigth != _ptrfin && frere->rigth != NULL && frere->rigth->color == ROUGE)
        {

          //  std::cout << "incroyable 5661" << std::endl;
          //  this->print_tab();
            
           // std::cout << "frerer type firsr" << frere->type.first  << " FssFFFF " << std::endl;


              rotate(frere->parents->parents , frere->parents, frere, frere->left, -1);
             // if (tmp2)
             //   std::cout << "incroyable 5451" << std::endl;
           // this->print_tab();
              tmp2->color = NOIR;
              if (tmp2->rigth)
              tmp2->rigth->color = NOIR;
           //    this->print_tab();
            return;
        }
        else
        {
               
                 if (frere->left != NULL)
                rotate(frere->parents , frere, frere->left,  frere->left->rigth, 0);
                else
                {
                    
                    rotate(frere->parents , frere, frere->rigth,  NULL,-1);
                }
                        rotate(frere->parents->parents->parents , frere->parents->parents, frere->parents,  frere->parents->left, -1);
                       

                //rotate(tmp2->parents , tmp2, frere->parents,  frere->parents->left, 0);
                return;
        }

    }
}

 int erase_0(ft::node<value_type> **tmp3,ft::node<value_type> **tmp2,ft::node<value_type> **tmp)
{
        std::allocator<ft::node<value_type> > _a;
       // std::cout << "RACCINE CAS" << std::endl;
        if ((*tmp2)->left == *tmp)
            (*tmp2)->left = NULL;
        else
            (*tmp2)->rigth = (*tmp)->rigth;
        if (*tmp == _ptrdeb)
            _ptrdeb = (*tmp)->parents; 
        _a.destroy(*tmp);
        _a.deallocate(*tmp,1);
        *tmp3 = NULL;
        if ((*tmp2)->rigth == _ptrfin)
            _ptrfin->parents = *tmp2;

        return NOIR;
}


 int erase_1(ft::node<value_type> **tmp3,ft::node<value_type> **tmp2,ft::node<value_type> **tmp, ft::node<value_type> *tmpf )
{
        std::allocator<ft::node<value_type> > _a;
                    tmpf->parents = *tmp2;
                    *tmp3 = tmpf;
          //  std::cout << "printd" << std::endl;
          //  this->print_tab();
            if ((*tmp2))
            {
             if ((*tmp2)->left == *tmp)
             {
                (*tmp2)->left = tmpf;
             }
            else
            {
                (*tmp2)->rigth = tmpf; 
            }
            }
            else
            {
            _node = tmpf;
       //     std::cout << "aaa" << std::endl;
            }


            _a.destroy(*tmp);
            _a.deallocate(*tmp,1);
         //               std::cout << "printd" << std::endl;
         //   this->print_tab();
            return (*tmp3)->color;
}

int erase_2(ft::node<value_type> **tmp3,ft::node<value_type> **tmp2,ft::node<value_type> **tmp,ft::node<value_type> **frere )
{
            std::allocator<ft::node<value_type> > _a;
            ft::node<value_type> tmp4 = **tmp3;
         //  std::cout << "CAS 2 fils" << (*tmp3)->type.first << std::endl;
                  
           // std::cout << "tmp3 fils" << (*tmp3)->type.first << std::endl;    
            *tmp3 = ++tmp4;
           // this->print_tab();
          //  std::cout << "tmp3 fils" << (*tmp3)->type.first << std::endl; 
           // ft::node<value_type> tmp5 = **tmp3;
          // std::cout << "tmp3 fils" << (*tmp3)->type.first << std::endl;
          // std::cout << "tmp3 fils" << (*tmp3)->rigth << std::endl;
          //  std::cout << "tmp3 fils" << (*tmp3)->rigth->type.first << std::endl;
            ft::node<value_type> *tmp5 = (*tmp3)->rigth;
       //     ft::node<value_type> *tmp6 = (*tmp3);
           //exit(1);
            if ((*tmp3)->parents->left != *tmp3)
                *frere = (*tmp3)->parents->left;
            else
                *frere = (*tmp3)->parents->rigth;
            
         //   std::cout << "CAS 2 fils" << (*tmp3)->type.first << std::endl;

         //    std::cout << "CAS 2 frere " <<   (*frere)->type.first<< std::endl;
          //  std::cout << "CAS 2 fils" << tmp3->type.first << std::endl;
             if (*tmp2)
            {
             if ((*tmp2)->left == *tmp)
                (*tmp2)->left = *tmp3;
             else
                (*tmp2)->rigth = *tmp3;
            }
            else
            {
            _node = *tmp3;
            }
           
         //   this->print_tab();
         //   std::cout << "CAS 200 fils" << std::endl;
         //     std::cout << "CAS 2 fils" << tmp3->type.first << std::endl;

            if ((*tmp)->left != *tmp3)
            {
                (*tmp3)->left = (*tmp)->left;
            }
            else 
                (*tmp3)->left = NULL;
        //     std::cout << "CAS 2 fils" << std::endl;
             if ((*tmp)->rigth != *tmp3)
             {

                (*tmp3)->rigth = (*tmp)->rigth;
             }
            else 
                (*tmp3)->rigth = tmp5;
         //   std::cout << "CAS 3 fils" << std::endl;
       //     std::cout << "CAS 33 fils" << std::endl;
       //     std::cout << tmp5->type.first << std::endl;
         
            if ((*tmp3)->parents)
            {
            //std::cout << tmp5->rigth->type.first << std::endl;
            if ((*tmp3)->parents->left == *tmp3)
            {

        //std::cout << "CAS 33 fils" << std::endl;
                (*tmp3)->parents->left = tmp5;
                
            }
            else
            {
                //std::cout << (*tmp3)->parents->type.first << std::endl;
               // std::cout << _node  << std::endl;
                (*tmp3)->parents->rigth = tmp5;
            }
            if (tmp5)
            tmp5->parents = (*tmp3);
            }
          //  std::cout << "CAS 2 fils" << std::endl;
            if ((*tmp)->left) 
            (*tmp)->left->parents = *tmp3;
            if ((*tmp)->rigth) 
            (*tmp)->rigth->parents = *tmp3;
            (*tmp3)->parents = *tmp2;
        //    (*tmp)->rigth->parents = *tmp3;
            _a.destroy(*tmp);
            _a.deallocate(*tmp,1);
            *tmp = NULL;
          //  this->print_tab();
            return (*tmp3)->color;
}

 size_type   equilibredelite(int u, int v, ft::node<value_type> *tmp3, ft::node<value_type> *tmp2, ft::node<value_type> *frere)
 {
         
      //  std::cout << "cas 1 " << frere << std::endl;

         if (u == ROUGE || v == ROUGE)
    {
        if (tmp3)
            tmp3->color = NOIR;

        return 1;
    }
 //   std::cout << "ABBBAAAAA " << frere->type.first << " " << tmp2 << std::endl;
    if (frere != NULL && frere != _ptrfin && ((frere->left != NULL  && frere->left->color == ROUGE ) || (frere->rigth != NULL && frere->rigth != _ptrfin && frere->rigth->color == ROUGE)))
    {
     //    std::cout << "frere et fils" << std::endl;
          //   std::cout << "incroyable 11" << std::endl;
            this->rotatedelet(frere->parents, frere);
            _node->color = NOIR;
            return 1;
    }
  /*  if (frere != NULL && frere != _ptrfin)
    {
     //   std::cout << "incroyable" << std::endl;
        frere->color = ROUGE;
        _node->color = NOIR;
        return 1;
    }*/
    if (frere != NULL && frere != _ptrfin && frere->color == ROUGE)
    {
    //    std::cout << "incroyable" << std::endl;
        if (frere->parents->left == frere)    
                rotate(tmp2->parents, tmp2, frere,  frere->rigth, 1);
        else   
                rotate(tmp2->parents, tmp2, frere,  frere->left, 1);
        _node->color = NOIR;
        return 1;
    }
    if ( (frere != NULL &&  frere != _ptrfin && frere->color == NOIR))
    {
        std::cout << "incroyable 12" << std::endl;
        if (frere != NULL)
        frere->color= ROUGE;
        if (tmp2 == NULL)
            return 1;
        if (tmp2->parents == NULL )
            equilibredelite( u, v, tmp3,tmp2->parents, NULL);
        else if ( tmp2->parents->left == tmp2)
            equilibredelite( u, v, tmp3,tmp2->parents, tmp2->parents->rigth);
        else
            equilibredelite( u, v, tmp3, tmp2->parents, tmp2->parents->left);
        return 1;
    }
    if (frere == NULL || frere == _ptrfin || frere->left->color == NOIR ||  frere->rigth->color == NOIR)
    {
        std::cout << "incroyable 15" << std::endl;
        while (tmp3 && tmp3->color == NOIR)
        {
            return 1;
        }
    }
    _node->color = NOIR;
    return (1);
 }

void erase(iterator position)
{
    node<value_type> *tmp = position.base();
    node<value_type> *tmp2 = tmp->parents;
    node<value_type> *tmp3 = tmp;
    node<value_type> *frere;
    int v;
    int u;
   // this->print_tab();
     v = tmp->color;
    if ((tmp->rigth == NULL || tmp->rigth == _ptrfin) && tmp->left == NULL)
    {
       //  std::cout << "CAS 0 fils AA" << std::endl;
        if (tmp->parents)
       {
            if (tmp->parents->left == tmp )
                frere = tmp->parents->rigth;
            else
                frere = tmp->parents->left;
       }
       else
            frere = NULL;
            /*
            if (tmp == _ptrdeb)
                _ptrdeb = tmp->parents; 
           if (tmp->rigth == _ptrfin)
           {
                tmp->parents->rigth = _ptrfin;
                _ptrfin->parents = tmp->parents;
           }    
        */
       if (_size==1)
       {
           std::allocator<ft::node<value_type> > _a;
            _a.destroy(tmp);
            _a.deallocate(tmp,1);
            _ptrdeb =  _ptrfin ;
            _node = NULL;
            _size = 0;
            return;
       }

       u = erase_0(&tmp3, &tmp2, &tmp);
        //    this->print_tab();
      
     // std::cout << "CAS 0 fils" << tmp3 << std::endl;
    }
    else if ( tmp->left == NULL || tmp->rigth == NULL || tmp->rigth == _ptrfin)
    {
     //   std::cout << "CAS 1 fils AAA" << std::endl;
        frere = NULL;
        if (tmp->left == NULL)
        {  
            if (tmp == _ptrdeb)
                _ptrdeb = tmp->rigth; 

        //    std::cout <<"  OK " << tmp2 << std::endl;
            u = erase_1(&(tmp3), &(tmp2), &(tmp), tmp->rigth);
        }
        else
        {
            u = erase_1(&tmp3, &tmp2, &tmp, tmp->left);
        }
         // std::cout << "CAS 1 fils AAA" << std::endl;
    }
    else
    { 
      //  this->print_tab();
        u = erase_2(&tmp3, &tmp2, &tmp, &frere);
       //    this->print_tab();
    }
    --_size;
   // std::cout << "ABBBAAAsssssAA " << std::endl;
  //  if (tmp2)
    //std::cout << tmp2->parents  << std::endl;
    //std::cout << frere << std::endl;
    /*
    if (tmp3)
        std::cout << "ABBBAAAsssssAA " << tmp3->type.first << " " << tmp2->type.first << std::endl;
    else
     std::cout << "tmp3 == NULL"<< std::endl;
     */
   // std::cout << "UB" << std::endl;
    equilibredelite(u, v, tmp3, tmp2, frere);
}


size_type erase(const key_type& x)
{
   iterator it;

/*    while ( (tmp->left != NULL || tmp->rigth != NULL) && tmp->type.first != x)
    {
        if (tmp->type.first > x)
            tmp = tmp->left;
        else
            tmp = tmp->rigth;
    }
    */
  // std::cout << "AAAA" << std::endl;
    it = this->find(x);
  //  std::cout << "AAAA" << std::endl;
    if (it != this->end())
        this->erase(it);
    return 1;
}

void erase(iterator first, iterator last)
{
// std::cout << "ERRRASE" << std::endl;
     while (first != last)
    {
      //  this->print_tab();
      //  std::cout << _ptrdeb->type.first << "  " << _size << std::endl;
     //   this->print_tab();
       //  this->print_tab();
      // iteraor tmp = first;
  //    std::cout << "ERRRASE" << std::endl;
      //  this->print_tab(); 
        erase(first++);
     //  this->print_tab();
         
   // if (first != this->end())
    }
  // exit(1);
}

void swap(map<Key,T,Compare,Allocator>& r)
{
    ft::swapnode(&_node, &r._node);
    ft::swapnode(&_ptrdeb, &r._ptrdeb);
    ft::swapnode(&_ptrfin, &r._ptrfin);
    size_type size;
    size = _size;
    _size = r._size;
    r._size = size;
}

void clear()
{
    std::cout << "c'est apres" << _size << std::endl;
    while (_size)
    {
        int a;
        this->print_tab();
        std::cin >> a;
       std::cout << _ptrdeb->type.first << "  " << _size << std::endl;
      
        erase(iterator(_ptrdeb));
        
      //          this->print_tab();
     //    std::cout << "INCROYABLE  " << _size << std::endl;
    }
    std::cout << "c'est apres" << std::endl;
    _node = NULL;
    _ptrdeb = _ptrfin;
}

// observers:
key_compare key_comp() const
{
    return key_compare();

}

value_compare value_comp() const
{

    return value_compare(_comp);
}

iterator find(const key_type& x)
{
    node<value_type> *tmp = _node;

    while ( (tmp->left != NULL || tmp->rigth != NULL) && tmp->type.first != x)
    {
        if ( _comp(tmp->type.first,x) && (tmp->rigth && tmp->rigth != _ptrfin) )
            tmp = tmp->rigth;
        else if  (_comp(x,tmp->type.first) && (tmp->left) )
            tmp = tmp->left;
        else
            break;
    }

    if (!_comp(x,tmp->type.first) && !_comp(tmp->type.first,x) )
        return iterator(tmp);
    return iterator(_ptrfin);
}

const_iterator find(const key_type& x) const
{
    node<value_type> *tmp = _node;

    while ( (tmp->left != NULL || tmp->rigth != NULL) && tmp->type.first != x)
    {
        if (tmp->type.first > x)
            tmp = tmp->left;
        else
            tmp = tmp->rigth;
    }

    if (tmp)
        return const_iterator(tmp);;
    return const_iterator(NULL);
}

size_type count(const key_type& x)
{
    node<value_type> *tmp = _node;
    if (_node == NULL)
        return 0;

    while ((tmp->left != NULL || (tmp->rigth != NULL && tmp->rigth != _ptrfin)) && tmp->type.first != x)
    {
            
        if ( _comp(tmp->type.first,x) && (tmp->rigth && tmp->rigth != _ptrfin) )
            tmp = tmp->rigth;
        else if ( _comp(x ,tmp->type.first) && tmp->left)
            tmp = tmp->left;
        else
        {
           //  std::cout << "WHILE22" << std::endl;
            break;
        }
    }
    if (!_comp(tmp->type.first,x) && !_comp(x ,tmp->type.first))
        return 1;
    return 0;
}


iterator lower_bound(const key_type& x)
{
        ft::node<value_type> *tmp = _node;
     while ( (tmp->left != NULL || tmp->rigth != NULL) && tmp->type.first != x)
    {
        if ( _comp(tmp->type.first,x) && (tmp->rigth) )
            tmp = tmp->rigth;
        else if  (_comp(x,tmp->type.first) && (tmp->left) )
            tmp = tmp->left;
        else
            break;
    }

    if (!_comp(x,tmp->type.first) && !_comp(tmp->type.first,x) )
        return iterator(tmp);
    if (_comp(x,tmp->type.first) && tmp != _ptrdeb)
        return iterator(tmp);
    if (tmp == _ptrfin)
        return iterator(_ptrfin);
    return iterator(_node);
}


const_iterator lower_bound(const key_type& x) const
{

    return find(x);
}


iterator upper_bound(const key_type& x)
{
    ft::node<value_type> *tmp = _node;
     while ( (tmp->left != NULL || tmp->rigth != NULL) && tmp->type.first != x)
    {
        if ( _comp(tmp->type.first,x) && (tmp->rigth && tmp->rigth != _ptrfin) )
            tmp = tmp->rigth;
        else if  (_comp(x,tmp->type.first) && (tmp->left) )
            tmp = tmp->left;
        else
            break;
    }

    if (!_comp(x,tmp->type.first) && !_comp(tmp->type.first,x) )
        return ++iterator(tmp);
    if (_comp(tmp->type.first,x) && tmp != _ptrfin)
        return ++iterator(tmp);
    if (tmp == _ptrfin)
        return iterator(tmp);
    return iterator(tmp);
}


const_iterator upper_bound(const key_type& x) const
{
        ft::node<value_type> *tmp = _node;
     while ( (tmp->left != NULL || tmp->rigth != NULL) && tmp->type.first != x)
    {
        if ( _comp(tmp->type.first,x) && (tmp->rigth && tmp->rigth != _ptrfin) )
            tmp = tmp->rigth;
        else if  (_comp(x,tmp->type.first) && (tmp->left) )
            tmp = tmp->left;
        else
            break;
    }

    if (!_comp(x,tmp->type.first) && !_comp(tmp->type.first,x) )
        return ++const_iterator(tmp);
    if (_comp(tmp->type.first,x))
        return const_iterator(tmp);
    return ++const_iterator(tmp);
}


ft::pair<iterator,iterator>
equal_range(const key_type& x)
{
        return (ft::pair<iterator, iterator>(lower_bound(x), upper_bound(x)));
}


ft::pair<const_iterator,const_iterator>
equal_range(const key_type& x) const
{

        return (ft::pair<const_iterator, const_iterator>(lower_bound(x), upper_bound(x)));
}


    private:
        node<value_type>    *_node;
        allocator_type      _alloc;
        node<value_type>    *_ptrdeb;
        node<value_type>    *_ptrfin;
        size_type           _size;
        Compare             _comp;
};

template <class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y)
{
    return (x.size() == y.size() && ft::equal( x.begin(), x.end(), y.begin(), &ft::pred_map<Key, T, Compare>));
}
template <class Key, class T, class Compare, class Allocator>
bool operator< (const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y)
{
        return (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end(), &ft::lac<Key, T, Compare>));
}
template <class Key, class T, class Compare, class Allocator>bool operator!=(const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y)
{
    return !( x.size() == y.size());
}
template <class Key, class T, class Compare, class Allocator>bool operator> (const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y)
{
    return ( y < x);
}
template <class Key, class T, class Compare, class Allocator>bool operator>=(const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y)
{
    return !( x < y);
}
template <class Key, class T, class Compare, class Allocator>bool operator<=(const map<Key,T,Compare,Allocator>& x,const map<Key,T,Compare,Allocator>& y)
{
    return !( x > y);
}

//specialized algorithms:
 template <class Key, class T, class Compare, class Allocator> 
  void swap(ft::map<Key,T,Compare,Allocator>& x, ft::map<Key,T,Compare,Allocator>& y)
{
    x.swap(y);

    /*
    ft::swapnode(x._node, y._node);
    ft::swapnode(x._ptrdeb, y._ptrdeb);
    ft::swapnode(x._ptrfin, y._ptrfin);
    size_t size;
    size = x._size;
    x._size = y._size;
    y._size = size;
    */
}

}
# endif
