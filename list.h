#ifndef LIST_H
#define LIST_H

#include "base_list.h"
#include "error_list.h"
//#include "iterator.h"
//#include "iterator_const.h"

template <typename type_t>
class List : BaseList
{
public:
    List();
    List(List<type_t>&&);
    List(size_t, type_t, ...);
    ~List();

    void push_back  (type_t);
    void pop_back   ();
    void push_front (type_t);
    void pop_front  ();

    void eject(Node <type_t>*, bool key);

    void clear();

    virtual size_t size() const override;
    bool empty() const;

    List<type_t>  operator+(const List<type_t> &) const;
    List<type_t>& operator+=(const List<type_t> &);
    List<type_t>& operator--(type_t);
    List<type_t>& operator--();
    List<type_t>& operator=(List<type_t> &&);
    bool          operator!() const;
    bool          operator==(const List<type_t> &) const;
    bool          operator!=(const List<type_t> &) const;



    //friend class Iterator<type_t>;
    //friend class IteratorConst<type_t>;

private:
    Node<type_t>* head;
    Node<type_t>* tail;

    List(const List<type_t>&);

    List<type_t>& operator=(const List<type_t> &);
    void insert(Node<type_t>*, type_t, int);
};

#endif // LIST_H

#include "_list.h"
