#include<iostream>
#include<vector>


int GreatesCommonDivisor(int a, int b){

    if(a%b == 0 )
    return b;

    else return GreatesCommonDivisor(b, a%b); // opisane w pdf od codility 
}

int solution(int N, int M){
    return N/GreatesCommonDivisor(N,M);
 // bo (N*M/GreatesCommonDivisor(N,M)/ M ), bo wynik to najmniejszy wspólny mnożnik / m
}
//najwiekszy wspólny dzielnik
// najmnijeszy wspólny mnożnik  po tylu elementach znowu zjem tę samą 
int main(){

    std::cout << solution(10, 4);
    return 0;
}