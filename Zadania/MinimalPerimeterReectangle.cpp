#include <iostream>
#include <cmath>

int solution(int N){

    for(unsigned int i = sqrt(N); i >= 1; i++){ //zaczynamy od najbliższego więc najszybsze zadziała 
        if(N%i == 0)
            return 2*(i+N/i);
    }

}
//praktycznie zadanie minimalizacyjne gdzie a= N/b, i minimaluzujemy funkcję f(a,b) = (a+b)
// f(b) = (N/b + b), f'(b) = -N/x^2 + 2 = 0 <==> x^2 = N == sqrt(N)
// od tego zaczynamy i sprawdzamy po kolei najbliższe 
//mnożymy zwracane przez 2, bo wcześniej pominęliśmy 

int main(){

    std::cout<< solution(30);

    return 0;
}