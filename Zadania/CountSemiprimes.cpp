#include<iostream>
#include<vector>
#include<algorithm>
std::vector<int> solution(int N, std::vector<int> &P, std::vector<int> &Q){

    std::vector<int> primes(N+1,1);
    primes[0] = 0;
    primes[1] = 0;

    for (int i = 2; i*i <=N; i++){ // warunlki petli jak zawsze

        if(primes[i]){ // jeżeli jest 1

            int k = i*i; // np 2*2
            while(k<=N){ // aż do końca zakresu

                primes[k] = 0; // jest 
                k+=i; //de facto mnożymy przez kolejną liczbę i spradzamy czy wynik to prime czyli 3*2, 4*2 itd
            }
        }
    }

    std::vector<int> allSemiPrimes(N+1, 0);
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            if(primes[i]*primes[j] == 1 && i*j <=N) // obie są pierwsze i ich iloczyn mieści się w zakresie 
                allSemiPrimes[j*i] = 1;
            if(i*j > N) // przekroczyliśmy zakres to nie patrzymy dalej 
                break;
        }
    }

    std::vector<int> semiPrimes(P.size(), 0);
    std::vector<int> cummulativeSemiPrimes(N+1, 0);
    int sum = 0;

    for(int i =  0; i < N+1; i++){

        sum+= allSemiPrimes[i];
        cummulativeSemiPrimes[i] = sum;
    //kumulowanie
    }

    for(int i = 0; i < P.size(); i++){

        semiPrimes[i] = cummulativeSemiPrimes[Q[i]] - cummulativeSemiPrimes[P[i]-1]; // wybieramy te z zakresu podanego w P i Q
    }

    return semiPrimes;
}


//sieve of eratosthenes znowu sprawdzamy do sqrt(max)
//
int main(){
    std::vector<int> P = {0,4,16};
    std::vector<int> Q = {26,10,20};

    std::vector<int> solut = solution(26,P,Q);

    return 0;
}