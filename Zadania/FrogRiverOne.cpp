#include <iostream>
#include <vector>
#include <numeric>

int solution(int x, std::vector<int> &A){

    std::vector<int> B(x,0); // wektor o rozmiwarze x i wypłęniony -1

    for (int i = 0; i<A.size(); i++){
        if(A[i] <= x && B[A[i]-1] == 0)// jeżeli A mieści się w x i wcześniej nie było liścia na tej pozycji
            B[A[i]-1] = 1; // wpisujemy, kiedy wystąpiło 
        int test = std::accumulate(B.begin(), B.end(), 0); //sumujemy wszystkie jedynki w B
        if( test== x ) // jeżeli cały wektor B jest zapełniony 1 
            return i; //w tej sekundzie żaba przeskoczy
    }

    return -1;
}

int main(){

    std::vector <int> vec = {1,3,1,4,2,3,5,4};
    std::cout << solution(3, vec);
    return 0;
}