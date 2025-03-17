#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        materia[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (materia[i]){
            delete materia[i];
        }
}


MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (materia[i])
        {
            delete materia[i];
            materia[i] = other.materia[i];
        }
        else 
            materia[i] = NULL;
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++)
    {
        if (materia[i])
            materia[i] = other.materia[i]->clone();
        else
            materia[i] = NULL;
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
        if (!materia[i]){
            materia[i] = m;
            return;
        }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        if (materia[i] && materia[i]->getType() == type){
            return materia[i]->clone();
        }
    }
    return NULL;
}