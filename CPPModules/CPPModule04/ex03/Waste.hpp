#ifndef WASTE_HPP
 #define WASTE_HPP

#include <iostream>
#include "AMateria.hpp"

class Waste
{
    private:
        Waste();
        Waste(const Waste &copy);
        Waste &operator=(const Waste &copy);

        Waste *_next;
        AMateria *_materia;

    public:
        ~Waste();
        Waste(AMateria *materia);

        static Waste *_head;
        static int _count;

        static void waste_add(AMateria *materia); //for pushing materia to waste list
        static void waste_del(AMateria *materia); //for erasing materia from waste list
        static void waste_del_all(); //for erasing all materia from waste list
};

#endif
