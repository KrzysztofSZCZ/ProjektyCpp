#include<iostream>
#include<vector>

int GreatesCommonDivisor(int a, int b){

    if(a%b == 0 )
    return b;

    else return GreatesCommonDivisor(b, a%b); // opisane w pdf od codility 
}

int solution(std::vector<int> &A, std::vector<int> &B){

    
    int a, b, divisor, counter = 0;

    for(int i = 0; i <A.size(); i++){

        a = A[i];
        b = B[i];
        divisor = GreatesCommonDivisor(a,b);

        while(GreatesCommonDivisor(a,divisor) != 1) //while jest opisane niżej 
            a /= GreatesCommonDivisor(a,divisor);

        while(GreatesCommonDivisor(b,divisor) != 1)
            b /= GreatesCommonDivisor(b,divisor);

        if(a == 1 && b == 1) // nie ma różnych prime divisorów 
            counter++;
    }

    return counter;
}

//ważne Matematyka: każdy prime wspolny dzielnik M i N wystąpi w ich GCD
//M'=M/GCD(M,N) -> M'/GCD(m',N) itd.. aż osiągniemy 1 to znaczy, że nie ma różnych prime factors w GCD
// to samo dla N 
//przy błędzie nie będzie równe 1 i zostanie ten ktory nie jest wspolny 
int main(){


    return 0;
}