#include <iostream>

using namespace std;

struct something
{
    int a;
    something* next;
};

int main()
{
    cout << sizeof(something);
}
