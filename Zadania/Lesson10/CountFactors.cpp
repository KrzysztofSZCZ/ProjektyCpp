#include<iostream>
#include<cmath>

int solution (int N){
     int counter = 0;

    for(unsigned int i = 1; i*i<= (unsigned) N; i++){ // po tym momencie już pozostałe będę "lustrzanym odbiciem" poprzednich
//usnigned bo przy INT_MAX jest stack overflow 
        if(N%i == 0)
            counter++;
    }

    if(N == (int)sqrt(N)*(int)sqrt(N)) // jeżeli jeden z dzielników jest pierwiastkim kwadratowym liczby
        return counter*2 -1;

    else return counter*2;
}

int main(){
    std::cout<< solution(24);

    return 0;
}