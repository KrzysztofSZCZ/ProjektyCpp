#include <iostream>
#include <vector>
#include <string>

template < typename T>
std::vector <T> AddFront(std::vector <T> vec, T value)
{
    std::vector <T> temp = {value};
    
    for (auto& el : vec)
    {
        temp.push_back(el);
    }

    return temp;
}


class A{

public:
   virtual std::string PrintName() = 0;

};

class B: public A{

public:
    std::string PrintName(){return "class B";}
};


class C : public A{

public:
    std::string PrintName(){return "class C";}
};
int main()
{
    std::vector <int> V = {1,2,3,4,5};


    for (auto& el : V)
    {
        std::cout << el << std::endl;
    }

    V.push_back(7);   

    std::vector <int> S = AddFront(V, 9);

    std::cout << "Vector S:" << std::endl;
    for (auto& el : S)
    {
        std::cout << el << std::endl;
    }


    B b;
    C c;

    std::vector <A*> vec = {&b, &c};


    std::cout<< "Dziedziczenie" << std::endl;

    for (auto& el : vec)
    {
        std::cout << el->PrintName() << " ";
    }

    
    std::vector <double> vectorDouble = AddFront(vectorDouble, 5.7);
    
    std::cout << "vecotr double:" << std::endl;

    for (auto& el :vectorDouble)
    {
        std::cout << el << " ";
    }
    
}
