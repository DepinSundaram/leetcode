#include <iostream>
#include <memory>
using namespace std;


class Entity
{
    public:
    Entity() { cout <<  " Created E \n" ;}

    ~Entity() {cout << "Destructed E\n" ;}

    void Print(){}
};

int main()
{
    shared_ptr<Entity> e0;
    {
        unique_ptr<Entity> e = make_unique<Entity>();
        e->Print();

       // unique_ptr<Entity> e1 = e; cant do copy cons is delet
       shared_ptr<Entity> shared = make_shared<Entity>();
        e0 = shared;

        weak_ptr<Entity> wp;

        wp = shared;
    }
   
}