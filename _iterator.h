#ifndef _ITERATOR_H
#define _ITERATOR_H

template <typename type_t>
Iterator<type_t>::Iterator(List<type_t> &list)
{
    this->list = &list;
    this->currentItem = this->list->head;
}

template <typename type_t>
Iterator<type_t>::~Iterator()
{
    this->list = NULL;
    this->currentItem = NULL;
}

template <typename type_t>
bool Iterator<type_t>::isNULL()
{
    return this->list && this->list->empty();
}

template <typename type_t>
bool Iterator<type_t>::operator!()
{
    return this->isInit();
}

template <typename type_t>
bool Iterator<type_t>::isInit()
{
    return this->currentItem != NULL;
}

template <typename type_t>
void Iterator<type_t>::add(type_t data, bool key)
{
    this->list->insert(this->currentItem, data, key);
}

template <typename type_t>
void Iterator<type_t>::del(bool key)
{
    if (this->isInit())
    {
        this->list->eject(this->currentItem, key);
    }
}

template <typename type_t>
void Iterator<type_t>::move_to_head()
{
    this->currentItem = this->list->head();
}

template <typename type_t>
void Iterator<type_t>::move_to_tail()
{
    this->currentItem = this->list->tail();
}

template <typename type_t>
void Iterator<type_t>::move_to_next()
{
    if (this->isInit())
    {
        this->currentItem = currentItem->next;
    }
}

template <typename type_t>
void Iterator<type_t>::move_to_prev()
{
    if (this->isInit())
    {
        this->currentItem = currentItem->prev;
    }
}

template <typename type_t>
void Iterator<type_t>::set(type_t& data)
{
    if (!this->ready())
    {
        throw ExceptionRange();
    }
    this->currentItem->data = data;
}

template <typename type_t>
type_t& Iterator<type_t>::value()
{
    return this->currentItem->data;
}

template <typename type_t>
Iterator<type_t>& Iterator<type_t>::operator=(const Iterator<type_t>& right)
{
    this->currentItem = right.currentItem;
    this->list = right.list;
    return *this;
}

template <typename type_t>
Iterator<type_t>& Iterator<type_t>::operator++()
{
    this->move_to_next();
    return *this;
}

template <typename type_t>
Iterator<type_t> Iterator<type_t>::operator++(type_t)
{
    Iterator<type_t> temp = *this;
    ++(*this);
    return temp;
}

template <typename type_t>
Iterator<type_t>& Iterator<type_t>::operator+=(const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        ++(*this);
    }
    return *this;
}

template <typename type_t>
Iterator<type_t>& Iterator<type_t>::operator--()
{
    this->move_to_prev();
    return *this;
}

template <typename type_t>
Iterator<type_t> Iterator<type_t>::operator--(type_t)
{
    Iterator<type_t> temp = *this;
    --(*this);
    return temp;
}

template <typename type_t>
Iterator<type_t>& Iterator<type_t>::operator-=(const size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        --(*this);
    }
    return *this;
}

template <typename type_t>
type_t& Iterator<type_t>::operator*()
{
    if (!this->isInit())
    {
        throw ExceptionRange();
    }
    return this->value();
}

template <typename type_t>
void Iterator<type_t>::operator<<(type_t& data)
{
    this->update(data);
}

template <typename type_t>
bool Iterator<type_t>::operator==(const Iterator<type_t> &right) const
{
    if (this->list != right.list)
    {
        throw ExceptionComparison();
    }
    return this->currentItem == right.currentItem;
}

template <typename type_t>
bool Iterator<type_t>::operator!=(const Iterator<type_t> &right) const
{
    if (this->list != right.list)
    {
        throw ExceptionComparison();
    }
    return this->currentItem != right.currentItem;
}

#endif // _ITERATOR_H
