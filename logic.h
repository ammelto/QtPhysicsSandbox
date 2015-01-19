#ifndef LOGIC_H
#define LOGIC_H


class logic
{
public:
    enum categories{plasticCat,rubberCat,iceCat};

    logic();
    ~logic();
private:
    int currentCat;
};

#endif // LOGIC_H
