#include <iostream>
#include <vector>
#include <string>

/*template < typename T>
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
};*/

//{{(())}} = ok 
//{[[]]} = ok
//{)} = nok

// [())(] = nok

bool Nawiasy(std::string ciagNawiasow)
{

    int licznikOtwZwykle = 0;
    int licznikZamknieteZwykle = 0;

    int licznikOtwKwadratowe = 0;
    int licznikZamknieteKwadratowe = 0;


    std::string nawiasy = {"[]()"};

    for (const auto& el : ciagNawiasow)
    {
        if(el == nawiasy[0])
        {
            licznikOtwKwadratowe++;
        }

        if(el == nawiasy[1] && licznikOtwKwadratowe == licznikZamknieteKwadratowe)
        {
            return false;
        }

        else
        {
            licznikZamknieteKwadratowe++;
        }

        if(el == nawiasy[2])
        {

            licznikOtwZwykle++;
        }

        if(el == nawiasy[3] && licznikOtwZwykle == licznikZamknieteZwykle)
        {
            return false;
        }

        else
        {
            licznikZamknieteZwykle++;
        }

    }
    
    if(licznikOtwZwykle == licznikZamknieteZwykle && licznikOtwKwadratowe == licznikZamknieteKwadratowe)
        return true;
    else 
        return false;
}



int main()
{
    
    std::string test = {"((([[[]]])))"};
    std::cout << Nawiasy(test) << std::endl;

    std::string test2 ={")(([]]))"};
    std::cout << Nawiasy(test2) <<std::endl;
}
