#include "Waste.hpp"

Waste *Waste::_head = 0;
int Waste::_count = 0;

Waste::Waste()
{
    _next = 0;
    _materia = 0;
}

Waste::Waste(AMateria *materia)
{
    _next = 0;
    _materia = materia;
}

Waste::Waste(const Waste &copy)
{
    _next = copy._next;
    _materia = copy._materia;
} //unused

Waste &Waste::operator=(const Waste &copy)
{
    if (this == &copy)
        return (*this);
    _next = copy._next;
    _materia = copy._materia;
    return (*this);
} //unused

Waste::~Waste() {}

void Waste::waste_add(AMateria *m)
{
    if (m == 0)
        return;

    Waste *tmp = new Waste;
    tmp->_materia = m;

    if (_count == 0)
    {
        _head = tmp;
        _count++;
        return;
    }
    else
    {
        Waste *tmp2 = _head;
        while (tmp2->_next)
            tmp2 = tmp2->_next;
        tmp2->_next = tmp;
        _count++;
    }
}

void Waste::waste_del(AMateria *materia)
{
    if (materia == 0 || _count == 0)
        return;

    Waste *prev = _head;
    Waste *curr = _head;
    while (curr)
    {
        if (curr->_materia == materia)
        {
            if (curr == _head)
            {
                _head = curr->_next;
                delete curr;
                //delete this "Waste container" only
            }
            else
                prev->_next = curr->_next;
            // Not deleting -> it is for later use of materia
            _count--;
            return ;
        }
        prev = curr;
        curr = curr->_next;
        //watch next element
    }
}

void Waste::waste_del_all()
{
    if (_head == 0)
        return ;
    Waste *curr = _head;
    while (curr)
    {
        _head = curr->_next;
        delete curr->_materia;
        delete curr;
        curr = _head;
        //_head == 0 ->curr == 0 -> exit while
    }
    _count = 0;
}
