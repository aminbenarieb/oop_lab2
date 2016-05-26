#ifndef ITERATOR_H
#define ITERATOR_H

#include "error_iterator.h"

template <class type_t>struct Node;
template <class type_t>class List;

template <typename type_t>
class Iterator
{
public:
    Iterator(List<type_t> &);
    ~Iterator();

    bool    isDone();
    bool    operator !();

    void    del();
    void    add(type_t, bool);

    void    set(type_t&);
    void    operator <<(type_t&);

    type_t& value();
    type_t& operator *();

    void    prev();
    void    next();
    void    begin();
    void    end();

    Iterator<type_t>&   operator =(const Iterator<type_t>&);
    Iterator<type_t>&   operator ++();								 // ++it
    Iterator<type_t>    operator ++(type_t);                         // it++
    Iterator<type_t>&   operator +=(const size_t);
    Iterator<type_t>&   operator --();								 // --it
    Iterator<type_t>    operator --(type_t);                         // it--
    Iterator<type_t>&   operator -=(const size_t);

    const type_t*       operator ->() const;

    bool                operator !=(const Iterator<type_t>&);
    bool                operator ==(const Iterator<type_t>&);



private:
    Node <type_t>* currentItem;
    List <type_t>* list;

};

#endif // ITERATOR_H

#include "_iterator.h"
