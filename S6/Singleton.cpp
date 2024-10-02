#include <iostream>
#include <memory>
using namespace std;

class Singleton
{
public:

    Singleton(Singleton &s) = delete;
    Singleton& operator=(Singleton &s) = delete;
    static shared_ptr<Singleton> getInstance()
    {
       
        static shared_ptr<Singleton> singleton_instance(new Singleton());
        return singleton_instance;
    }

    inline string getText() const {return text;}
    inline void setText(string text) {this->text = text;}
private:
    string text;
    Singleton()
    {
        text = "";
    }
};

int main()
{
    shared_ptr<Singleton> s1 = Singleton::getInstance();
    s1->setText("If only I could be so grossly incadescent");
    cout << s1->getText();
}