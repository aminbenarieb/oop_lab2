#ifndef ITERATOR_CONST_H
#define ITERATOR_CONST_H

template <class type_t>struct Node;
template <class type_t>class List;

template <typename type_t>
class IteratorConst
{
public:
    IteratorConst(const List<type_t> &);
    ~IteratorConst();

    bool    isNULL();
    bool    isInit();
    type_t& value();
    void    move_to_prev();
    void    move_to_next();
    void    move_to_head();
    void    move_to_tail();


    IteratorConst<type_t>&   operator =(const IteratorConst<type_t>&);
    IteratorConst<type_t>&   operator ++();								 // ++it
    IteratorConst<type_t>    operator ++(type_t);                        // it++
    IteratorConst<type_t>&   operator +=(const size_t);
    IteratorConst<type_t>&   operator --();								 // --it
    IteratorConst<type_t>    operator --(type_t);                        // it--
    IteratorConst<type_t>&   operator -=(const size_t);
    const type_t&            operator *();
    void                     operator <<(type_t& data);
    bool                     operator !=(const IteratorConst<type_t>&) const;
    bool                     operator ==(const IteratorConst<type_t>&) const;
    bool                     operator !();


private:
    Node <type_t>* currentItem;
    const List <type_t>* list;

};

#endif // ITERATOR_CONST_H
