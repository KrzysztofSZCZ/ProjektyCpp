#include <iostream>
#include <memory>


class A{


public:

    A(){std::cout <<"Konstuktor";}
    ~A(){std::cout << "Destruktor";}

};


int main()
{
    std::shared_ptr<A> sptr = std::make_shared<A>();
    






    return 0;
}