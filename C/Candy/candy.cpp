#include <vector>
#include <stdio.h>
using namespace std;

class Child
{
private:
    int _index;
    int _rating;
    int _candy;

public:
    Child();
    Child(int index, int rating);
    int getIndex();
    int getRating();
    int getCandy();
    void giveCandy();
    bool isJealous(std::vector<Child *> children);
    ~Child();
};

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

int Child::getCandy()
{
    return _candy;
}

void Child::giveCandy()
{
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

class Solution
{
public:
    static int candy(vector<int> &ratings)
    {
        std::vector<Child *> children(ratings.size());
        bool jealousy = true;
        int candyCount = ratings.size();

        for (int i = 0; i < ratings.size(); i++)
        {
            children[i] = new Child(i, ratings[i]);
        }

        // Loop until no one is jealous.
        while (jealousy)
        {
            jealousy = false;
            for (int i = 0; i < ratings.size(); i++)
            {
                // If a child is jealous, give them candy, and set jealousy to true.
                if (children[i] && children[i]->isJealous(children))
                {
                    jealousy = true;
                    children[i]->giveCandy();
                    candyCount++;
                }
                // Otherwise delete the child.
                else
                {
                    children[i]->~Child();
                }
                
            }
        }

        return candyCount;
    }
};

int main()
{

    vector<int> ratings({1, 2, 2});

    /* for (int i = 0; i < 3; i++)
    {
        printf("%d\n", array[i]);
    } */

    printf("%d\n", Solution::candy(ratings));
}
