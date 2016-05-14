#ifndef LIST_H
#define LIST_H

#include "base_list.h"
#include "iterator.h"
#include "iterator_const.h"

template <typename type_t>
class List : BaseList
{
public:
    List();
    List(List<type_t>&&);
    List(size_t, type_t, ...);
    ~List();

    void push_back  (type_t);
    void pop_back   (type_t);
    void push_front (type_t);
    void pop_front  (type_t);

    void delete_with_link(Node <type_t>*, bool key);

    void clear();

    virtual size_t size() const override;
    bool empty() const;

    List<type_t>  operator+(const List<type_t> &right) const;    // (?)
    List<type_t>& operator+=(const List<type_t> &right);         // (?)
    List<type_t>  operator--(type_t);                            // (?)
    List<type_t>& operator--();                                  // (?)
    type_t&       operator=(const type_t&);
    bool          operator!() const;                             // (?)
    bool          operator==(const List<type_t> &right) const;   // (?)
    bool          operator!=(const List<type_t> &right) const;   // (?)

    friend class Iterator<type_t>;
    friend class IteratorConst<type_t>;

private:
    Node<type_t>* head;
    Node<type_t>* tail;

    List(const List<type_t>&);

    List<type_t>& operator=(const List<type_t> &);
    void add_with_link(Node<type_t>*, type_t, int);
};

#endif // LIST_H

//#include "_list.h"
