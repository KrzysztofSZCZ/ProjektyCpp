#include <iostream>
#include <string>

int GetValue(){
    return 10;
}

int& GetLValue(){
    //return 10 is impossible bc int& means it must return lvalue, and 10 is rvalue
    int LValue = 10;
    return LValue;
}


void SetValue(int value){}

void PrintName(std::string& name){

    std::cout << name << std::endl;
}


//overload with rvalue; it will be called first 
void PrintName(std::string&& name){

    std::cout << name << std::endl;

}


int main(){

    int i  = 10;
    // l value is on left here, and r on the right side 
    // 10 = i won't work bc it is impossible to assign rvalue = lvalue

    int a = GetValue(); // it assigns rvalue (10) to lvalue a

    //GetValue() = 5; is impossible bc again, you cant assign anything to rvalue

    GetLValue() = 5; //it returns Lvalue so it is possible 

    SetValue(i); //lvalue
    SetValue(10); //rvalue- temporary; 10 will be called as lvalue; int& value wouldn't work bc u cant call lvalue ref with rvalue 

    const int& a = 10; // it is possible bc compiler will create an temp int

    std::string firstName = "Krzysztof";
    std::string lastName = "Szczepanski";

    std::string fullName = firstName + lastName;

    //everything on the left side is lvalue, so firstName lastName fullName = l, but firstName+lastName = r

    PrintName(fullName); //it works bc u call lvlaue ref with lvalue

    //PrintName(firstName + lastName) wont work bc it's rvalue
    //so we use many const ref to use rvalue 

    PrintName(firstName + lastName); // && means rvalue ref so i can use rvalue to call it, but not lvalue 


    return 0;
}