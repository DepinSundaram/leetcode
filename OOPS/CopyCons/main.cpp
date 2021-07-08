#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;
class String
{
    char* m_buffer;
    unsigned int m_Size;
public:
    String(const char* s)
    {
        m_Size = strlen(s);
        m_buffer = new char[m_Size + 1];
        memcpy(m_buffer, s, m_Size + 1);
    }

    String(const String& other) : m_Size(other.m_Size)
    {
        cout <<  "Copied String \n";
        m_buffer = new char[m_Size + 1];
        memcpy(m_buffer, other.m_buffer, m_Size);
    }
    char& operator[](unsigned int id)
    {
        return m_buffer[id];
    }
    friend std::ostream& operator<<(std::ostream& stream, const String& s);
    ~String()
    {
        delete[] m_buffer;
    }
};

std::ostream& operator<<(std::ostream& stream, const String& s)
{
    stream << s.m_buffer;
    return stream;
}

void PrintString(String& s)
{
    cout << s << endl;
}

int main()
{

    String s = "DS";
    String s2 = s;
    s2[0] = 'v';
    PrintString(s);
    PrintString(s2);
}