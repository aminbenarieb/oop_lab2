#ifndef _ITERATOR_CONST_H
#define _ITERATOR_CONST_H

template <typename type_t>
IteratorConst<type_t>::IteratorConst(const List<type_t> &list)
{
    this->list = &list;
    this->currentItem = this->list->head;
}

template <typename type_t>
IteratorConst<type_t>::~IteratorConst()
{
    this->list = NULL;
    this->currentItem = NULL;
}

template <typename type_t>
bool IteratorConst<type_t>::isNULL()
{
    return this->list && this->list->empty();
}

template <typename type_t>
bool IteratorConst<type_t>::operator!()
{
    return this->isInit();
}

template <typename type_t>
bool IteratorConst<type_t>::isInit()
{
    return this->currentItem != NULL;
}

template <typename type_t>
void IteratorConst<type_t>::move_to_head()
{
    this->currentItem = this->list->head();
}

template <typename type_t>
void IteratorConst<type_t>::move_to_tail()
{
    this->currentItem = this->list->tail();
}

template <typename type_t>
void IteratorConst<type_t>::move_to_next()
{
    if (this->isInit())
    {
        this->currentItem = currentItem->next;
    }
}

template <typename type_t>
void IteratorConst<type_t>::move_to_prev()
{
    if (this->isInit())
    {
        this->currentItem = currentItem->prev;
    }
}

template <typename type_t>
const type_t& IteratorConst<type_t>::value()
{
    return this->currentItem->data;
}

template <typename type_t>
IteratorConst<type_t>& IteratorConst<type_t>::operator=(const IteratorConst<type_t>& right)
{
    this->currentItem = right.currentItem;
    this->list = right.list;
    return *this;
}

template <typename type_t>
IteratorConst<type_t>& IteratorConst<type_t>::operator++()
{
    this->move_to_next();
    return *this;
}

template <typename type_t>
IteratorConst<type_t> IteratorConst<type_t>::operator++(type_t)
{
    IteratorConst<type_t> temp = *this;
    ++(*this);
    return temp;
}

template <typename type_t>
IteratorConst<type_t>& IteratorConst<type_t>::operator+=(const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        ++(*this);
    }
    return *this;
}

template <typename type_t>
IteratorConst<type_t>& IteratorConst<type_t>::operator--()
{
    this->move_to_prev();
    return *this;
}

template <typename type_t>
IteratorConst<type_t> IteratorConst<type_t>::operator--(type_t)
{
    IteratorConst<type_t> temp = *this;
    --(*this);
    return temp;
}

template <typename type_t>
IteratorConst<type_t>& IteratorConst<type_t>::operator-=(const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        --(*this);
    }
    return *this;
}

template <typename type_t>
const type_t& IteratorConst<type_t>::operator*()
{
    if (!this->isInit())
    {
        throw ExceptionRange();
    }
    return this->value();
}

template <typename type_t>
void IteratorConst<type_t>::operator<<(type_t& data)
{
    this->update(data);
}

template <typename type_t>
bool IteratorConst<type_t>::operator==(const IteratorConst<type_t> &right) const
{
    if (this->list != right.list)
    {
        throw ExceptionComparison();
    }
    return this->currentItem == right.currentItem;
}

template <typename type_t>
bool IteratorConst<type_t>::operator!=(const IteratorConst<type_t> &right) const
{
    if (this->list != right.list)
    {
        throw ExceptionComparison();
    }
    return this->currentItem != right.currentItem;
}



#endif // _ITERATOR_CONST_H
