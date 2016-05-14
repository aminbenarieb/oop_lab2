#ifndef _LIST_H
#define _LIST_H

template <typename type_t>
List<type_t>::List()
{
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;
}

template <typename type_t>
List<type_t>::List(const List<type_t>& object)
{
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;

    Node<type_t>* item = object.head;

    while (item != NULL)
    {
        this->push_back(item->data);
        item = item->next;
    }
}

template <typename type_t>
List<type_t>::List(List<type_t>&& object)
{
    this->head = NULL;
    this->tail = NULL;
    this->length = 0;

    Node<type_t>* item = object.head;

    while (item != NULL)
    {
        this->push_back(item->data);
        item = item->next;
    }
}

template <typename type_t>
List<type_t>::List(size_t size, type_t data, ...)
{

    this->head = NULL;
    this->tail = NULL;
    this->length = 0;

    va_list arg;
    va_start(arg, data);
    this->push_back(data);
    for (size_t i = 0; i < size - 1; i++)
    {
        data = va_arg(arg, type_t);
        this->push_back(data);
    }
    va_end(arg);
}

template <typename type_t>
List<type_t>::~List()
{
    clear();
}

template <typename type_t>
void List<type_t>::push_back(type_t data)
{
    insert(this->tail, data, false);
}

template <typename type_t>
void List<type_t>::push_front(type_t data)
{
    insert(this->head, data, true);
}

template <typename type_t>
void List<type_t>::insert(Node<type_t>* link, type_t data, int key)
{
    Node<type_t>* newItem;
    newItem = new Node<type_t>;
    if (!newItem)
    {
        throw ErrorMemory();
    }

    newItem->data = data;
    newItem->prev = NULL;
    newItem->next = NULL;

    Node<type_t>* item = link;

    if (item == NULL && this->size() != 0)
    {
        throw ErrorLink();
    }

    if (item == NULL)
    {
        this->head = newItem;
        this->tail = newItem;
    }
    else
    {
        bool first = false;

        if (key)
        {
            if (item->prev != NULL)
            {
                item = item->prev;
            }
            else
            {
                first = true;
            }
        }

        if (!first)
        {
            newItem->prev = item;
            newItem->next = NULL;
            if (item->next)
            {
                newItem->next = item->next;
                item->next->prev = newItem;
            }
            else
            {
                this->tail = newItem;
            }
            item->next = newItem;
        }
        else
        {
            newItem->prev = NULL;
            newItem->next = item;
            item->prev = newItem;
            this->head = newItem;
        }
    }
    this->length++;
}

template <typename type_t>
void List<type_t>::pop_front()
{
    if (!this->head->next)
    {
        throw ErrorPop();
    }
    eject(this->head->next, true);
}

template <typename type_t>
void List<type_t>::pop_back()
{
    if (!this->tail->prev)
    {
        throw ErrorPop();
    }
    eject(this->tail->prev, false);
}

template <typename type_t>
void List<type_t>::eject(Node<type_t>* link, bool key)
{
    Node<type_t>* item = link;

    if (item == NULL)
    {
        throw ErrorLink();
    }

    if (key)
    {
        if (item->prev == NULL)
        {
            throw ErrorLink();
        }
        item = item->prev;
    }
    else
    {
        if (item->next == NULL)
        {
            throw ErrorLink();
        }
        item = item->next;
    }

    if (item->prev && item->next)
    {
        item->next->prev = item->prev;
        item->prev->next = item->next;
    }
    else
    {
        if (item->prev)
        {
            item->prev->next = NULL;
            this->tail = this->tail->prev;
        }
        if (item->next)
        {
            item->next->prev = NULL;
            this->head = this->head->next;
        }
    }
    delete item;
    this->length--;
}

template <typename type_t>
size_t List<type_t>::size() const
{
    return this->length;
}

template <typename type_t>
void List<type_t>::clear()
{
    while (this->head)
    {
        this->tail = this->head->next;
        delete this->head;
        this->head = this->tail;
    }
    this->length = 0;
}

template <typename type_t>
bool List<type_t>::empty() const
{
    return this->head == NULL;
}

template <typename type_t>
bool List<type_t>::operator!() const
{
    return this->empty();
}

template <typename type_t>
List<type_t>& List<type_t>::operator=(List<type_t> &&right)
{
    if (*this != right)
    {
        this->clear();

        Node<type_t>* item = right.head;

        while (item != NULL)
        {
            this->push_back(item->data);
            item = item->next;
        }
    }
    return *this;
}

template <typename type_t>
List<type_t>& List<type_t>::operator=(const List<type_t> &right)
{
    if (*this != right)
    {
        this->clear();

        Node<type_t>* item = right.head;

        while (item != NULL)
        {
            this->push_back(item->data);
            item = item->next;
        }
    }
    return *this;
}

template <typename type_t>
List<type_t> List<type_t>::operator+(const List<type_t> &right) const
{
    List<type_t> result = *this;

    Node<type_t>* item;
    item = right.head;

    while (item)
    {
        result.push_back(item->data);
        item = item->next;
    }
    return result;
}

template <typename type_t>
List<type_t>& List<type_t>::operator+=(const List<type_t> &right)
{
    Node<type_t>* item;
    item = right.head;
    while (item)
    {
        this->push_back(item->data);
        item = item->next;
    }
    return *this;
}

template <typename type_t>
List<type_t>& List<type_t>::operator--(type_t)
{
    this->pop_back();
}

template <typename type_t>
List<type_t>& List<type_t>::operator--()
{
    this->pop_front();
}

template <typename type_t>
bool List<type_t>::operator==(const List<type_t> &right) const
{
    if (this->length != right.length)
    {
        return false;
    }
    Node<type_t>* item1 = this->head;
    Node<type_t>* item2 = right.head;
    while (item1  && item1->data != item2->data)
    {
        item1 = item1->next;
        item2 = item2->next;
    }

    return !item1;
}

template <typename type_t>
bool List<type_t>::operator!=(const List<type_t> &right) const
{
    if (this->length != right.length)
    {
        return true;
    }
    Node<type_t>* item1 = this->head;
    Node<type_t>* item2 = right.head;
    while (item1 && item2)
    {
        if (item1->data != item2->data)
        {
            return true;
        }
        item1 = item1->next;
        item2 = item2->next;
    }
    return false;
}


#endif // _LIST_H
