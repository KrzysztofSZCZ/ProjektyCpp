#include <iostream>


int solution(int A, int B, int K){

    int counter = (B/K) - (A/K); // podzielne od 0 do B - podzielne od 0 do K

    if(A %K == 0)
        counter++;

    return counter;
}



int main(){

    std::cout << solution(6,11,2);
    return 0;
}