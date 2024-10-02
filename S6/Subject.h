#ifndef SUBJECT
#define SUBJECT
#include <vector>
class IObserver;

class Subject
{
private:
    std::vector<IObserver *> observers;
    void notify();
    int first, second;

public:
    void attach(IObserver *);
    void detach(IObserver *);
    void setVal(int, int);

    int getFirst() { return first; }
    int getSecond() { return second; }
};





#endif