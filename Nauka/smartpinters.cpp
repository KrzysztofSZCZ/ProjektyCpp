#include <iostream>
#include <memory>


class Entity{
public:
    Entity(){
        std::cout << "Created" << std::endl;
    }

    ~Entity(){
        std::cout <<"Destroyed" << std::endl;
    }


};


int main(){
    {
        std::shared_ptr<Entity> e0; //if this was weak entity woudl be destroyed after first scope bc weak cant hold object by itself
            {
                std::unique_ptr<Entity> entity = std::make_unique<Entity>();
                // std::unique_ptr<Entity> e0 = entity; niemożna bo unique ma wyłączony copy i move, bo mozę mieć tylko 1
            
                std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
                //shared nie używamy new bo spowodowaoby to podwójną alokację, bo shared ma swój control block 
                e0 = sharedEntity;

                std::weak_ptr<Entity> weakEnt = sharedEntity;
                //it doesn't increase ref count 

            } //entity tutaj nie umrze, bo wskazuje na niego ciągle e0, czyli counter = 1
        std::cout << "-------------" <<std::endl;
    }   //umrze tutaj bo umiera też e0


    return 0;
}