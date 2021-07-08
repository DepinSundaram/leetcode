#include <iostream>

/*
class Singleton
{
public:
    Singleton (const Singleton&) = delete;
    static Singleton& Get()
    {
        return s_Instance;
    }

    void Func()
    {}
private:
    Singleton(){}

    static Singleton s_Instance;
};

Singleton Singleton::s_Instance;

int main()
{

    Singleton::Get().Func();
}

*/


class Random
{
public:
    Random (const Singleton&) = delete;
    static Random& Get()
    {
        return s_Instance;
    }

    void Func()
    {}

    static float Float()
    {
        return Get().IFloat();
    }

private:

    float IFloat()
    {
        return m_randomGen;
    }
    Random(){}
    float m_randomGen = 0.5f;
    static Random s_Instance;
};

Random Random::s_Instance;

int main()
{
    auto& num = Random::Get().Float();
}
