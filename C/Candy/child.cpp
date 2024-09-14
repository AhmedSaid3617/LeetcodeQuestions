#include "child.h"

Child::Child()
{
}

Child::Child(int index, int rating)
{
    _index = index;
    _rating = rating;
    _candy = 1;
}

Child::~Child()
{
}

int Child::getIndex()
{
    return _index;
}

int Child::getRating()
{
    return _rating;
}

int Child::getCandy(){
    return _candy;
}

void Child::giveCandy(){
    _candy++;
}

bool Child::isJealous(std::vector<Child *> children)
{
    bool jealous = false;

    // If the child behind me has lower rating and more equal or more candy, then I'm jealous.
    if ((_index && children[_index - 1]->getRating() < _rating))
    {
        jealous |= getCandy() <= children[_index - 1]->getCandy();
    }

    // If the child after me has lower rating and more or equal candy, then I'm jealous.
    if ((children.size() - 1 - _index) && children[_index + 1]->getRating() < _rating)
    {
        jealous |= getCandy() <= children[_index + 1]->getCandy();
    }

    return jealous;
    
}