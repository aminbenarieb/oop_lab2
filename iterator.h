#ifndef ITERATOR_H
#define ITERATOR_H

template <class type_t>struct Node;
template <class type_t>class List;

template <typename type_t>
class Iterator
{
public:
    Iterator(List<type_t> &);
    ~Iterator();

    bool    isNULL();
    bool    isInit();
    void    del(bool key);
    void    add(type_t data, bool key);
    void    set(type_t& data);
    type_t& value();
    void    move_to_prev();
    void    move_to_next();
    void    move_to_head();
    void    move_to_tail();


    Iterator<type_t>&   operator =(const Iterator<type_t>&);
    Iterator<type_t>&   operator ++();								 // ++it
    Iterator<type_t>    operator ++(type_t);                         // it++
    Iterator<type_t>&   operator +=(const size_t);
    Iterator<type_t>&   operator --();								 // --it
    Iterator<type_t>    operator --(type_t);                         // it--
    Iterator<type_t>&   operator -=(const size_t);
    type_t&             operator *();
    void                operator <<(type_t& data);
    bool                operator !=(const Iterator<type_t>&) const;
    bool                operator ==(const Iterator<type_t>&) const;
    bool                operator !();


private:
    Node <type_t>* currentItem;
    List <type_t>* list;

};

#endif // ITERATOR_H

//#include "_iterator.h"
