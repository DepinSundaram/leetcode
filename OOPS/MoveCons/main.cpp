#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

// https://www.youtube.com/watch?v=ehMg6zvXuMY&t=619s
class String
{
    int m_size;
    char* m_Data;
public:
    String() = default;
    String(const char* string)
    {
        printf("Created\n");
        m_size = strlen(string);
        m_Data = new char[m_size];

        memcpy(m_Data, string, m_size);
    }

    String(const String& other)
    {
        printf("Copied\n");
        m_size = other.m_size;
        m_Data = new char[m_size];
        memcpy(m_Data, other.m_Data, m_size);
    }
    ~String()
    {
        delete m_Data;
        cout << "Destroyed\n";
    }

    String(String&& other)
    {
        cout << "Moved";
        m_size = other.m_size;
        m_Data = other.m_Data;
        other.m_Data = nullptr;
        other.m_size = 0;
    }
    void Print()
    {
        for(int i = 0; i < m_size; i++)
        {
            printf("%c", m_Data[i]);
        }

        printf("\n");
    }
};


class Entity
{
    public:
    Entity(const String& name): m_name(name)
    {

    }
    void Print()
    {
        m_name.Print();
    }

    Entity(String&& name): m_name((String&&)name)
    {}
    private:
    String m_name;
};


int main()
{
    Entity entity(String("VS"));
    entity.Print();
}