#include <iostream>
#include<cmath>

int solution(int x, int y, int d){
    long double temp = (y-x);
    temp /= d;
    int MinimalAmountOfJumps = std::ceil(temp);
    return MinimalAmountOfJumps;
}



int main(){

    std::cout<< solution(10,700,25);
    return 0;
}