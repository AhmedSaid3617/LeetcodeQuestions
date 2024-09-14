#include <vector>

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
    bool isJealous(std::vector<Child*> children);
    ~Child();
};