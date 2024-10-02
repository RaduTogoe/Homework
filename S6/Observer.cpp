#include <iostream>
#include <vector>
#include <algorithm>
#include "Subject.h"
using namespace std;

class IObserver
{
protected:
    Subject *model;

public:
    IObserver(Subject *m)
    {
        model = m;
        model->attach(this);
    }
    virtual ~IObserver()
    {
        model->detach(this);
    }
    virtual void update() = 0;
};

void Subject::attach(IObserver *obs)
{
    observers.push_back(obs);
}

void Subject::detach(IObserver *obs)
{
    auto it = find(observers.begin(), observers.end(), obs);
    if (it != observers.end())
        observers.erase(it);
}

void Subject::setVal(int a, int b)
{
    first = a;
    second = b;
    notify();
}

void Subject::notify()
{
    for (auto &obs : observers)
        obs->update();
}

class Addition : public IObserver
{
public:
    Addition(Subject *sbj) : IObserver(sbj) {}
    void update() override
    {
        cout << "The sum of " << model->getFirst() << " + " << model->getSecond() << " =" << model->getFirst() + model->getSecond();
    }
};

class Multiplication : public IObserver
{
public:
    Multiplication(Subject *sbj) : IObserver(sbj) {}
    void update() override
    {
        cout << "The product of " << model->getFirst() << " * " << model->getSecond() << " =" << model->getFirst() * model->getSecond();
    }
};

int main()
{
    Subject sbj;
    Addition a(&sbj);
    Multiplication b(&sbj);

    sbj.setVal(5, 3);
}