#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    _count = 0;
    for (int i = 0; i < 4; i++)
    {
        _materia[i] = 0; //empty at construction
    }
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
    _count = copy._count;
    for (int i = 0; i < 4; i++)
    {
        if (copy._materia[i])
            _materia[i] = copy._materia[i]->clone();
        else
            _materia[i] = 0; //empty at construction
    }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &copy)
{
    if (this == &copy)
        return (*this);
    _count = copy._count;
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i])
        {
            delete _materia[i];
            _materia[i] = 0;
        }
        if (copy._materia[i])
            _materia[i] = copy._materia[i]->clone();
        else
            _materia[i] = 0;
    }
    return (*this);
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i])
        {
            delete _materia[i];
            _materia[i] = 0;
            // std::cout << "Material deleted" << std::endl;
        }
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (m == 0)
        return ;
    if (_count < 4)
    {
        _materia[_count] = m; // so, not making new materia.
        // main is making new materia and giving it to learnMateria
        _count++;
    }
    else
    {
        // std::cout << "Materia learn failed" << std::endl;
        delete m; // since main passes new Ice and Cure -> delete them if i can't equip
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    if (_count == 0)
        return (0);
    for (int i = 0; i < 4; i++)
    {
        if (_materia[i] && _materia[i]->getType() == type)
            return (_materia[i]->clone());
    }
    return (0);
}
