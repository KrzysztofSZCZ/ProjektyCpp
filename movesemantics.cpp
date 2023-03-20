#include<iostream>

class String{

char* mData;
int mSize;

public:
    String() = default;
    String(const char* string){

        mSize = strlen(string);
        mData = new char(mSize);
        memcpy(mData, string, mSize);
    }

    String(const String& other){

        std::cout << "Copied" << std::endl;
        mSize = other.mSize;
        mData = new char[mSize];
        memcpy(mData, other.mData, mSize);
    }

    String(String&& other) noexcept{ //move constructor

        std::cout << "Moved" << std::endl;
        mSize = other.mSize;
        mData = other.mData;

        other.mSize = 0;
        other.mData = nullptr; // these 2 lines are making sure that we wont loose moved data while destroing other
    }

    ~String(){

        delete mData;
        std::cout << "Destroyed" << std::endl;
        }

    void PrintString(){

        for (int i = 0; i < mSize; i++)
            std::cout << mData[i] << std::endl;
    }
};

class Entity{

    String mName;

public:
    Entity(const String& name) : mName(name){}
    Entity(String&& name) : mName(std::move(name)){}

    void PrintName(){

        mName.PrintString();
    }

};




int main(){
    Entity entity("Krzysztof");
    entity.PrintName();


    return 0;
}