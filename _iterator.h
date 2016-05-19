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
bool Iterator<type_t>::operator!()
{
    return this->isDone();
}

template <typename type_t>
bool Iterator<type_t>::isDone()
{
    return this->currentItem == NULL;
}

template <typename type_t>
void Iterator<type_t>::push(type_t data, bool before)
{
    this->list->insert(this->currentItem, data, before);
}

template <typename type_t>
void Iterator<type_t>::pop()
{
    if (!this->isDone())
    {
        this->list->eject(this->currentItem);
    }
}

template <typename type_t>
void Iterator<type_t>::begin()
{
    this->currentItem = this->list->head();
}

template <typename type_t>
void Iterator<type_t>::end()
{
    this->currentItem = this->list->tail();
}

template <typename type_t>
void Iterator<type_t>::next()
{
    if (!this->isDone())
    {
        this->currentItem = currentItem->next;
    }
}

template <typename type_t>
void Iterator<type_t>::prev()
{
    if (!this->isDone())
    {
        this->currentItem = currentItem->prev;
    }
}

template <typename type_t>
void Iterator<type_t>::set(type_t& data)
{
    if (this->isDone())
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
Iterator<type_t>& Iterator<type_t>::operator=(const Iterator<type_t>& iterator)
{
    this->currentItem = iterator.currentItem;
    this->list = iterator.list;
    return *this;
}

template <typename type_t>
Iterator<type_t>& Iterator<type_t>::operator++()
{
    this->next();
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
    this->prev();
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
    if (this->isDone())
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
bool Iterator<type_t>::operator==(const Iterator<type_t> &iterator) const
{
    if (this->list != iterator.list)
    {
        throw ExceptionComparison();
    }
    return this->currentItem == iterator.currentItem;
}

template <typename type_t>
bool Iterator<type_t>::operator!=(const Iterator<type_t> &iterator) const
{
    if (this->list != iterator.list)
    {
        throw ExceptionComparison();
    }
    return this->currentItem != iterator.currentItem;
}

template <typename type_t>
const type_t* Iterator<type_t>::operator->() const
{
    return &(this->currentItem.data);
}

#endif // _ITERATOR_H
