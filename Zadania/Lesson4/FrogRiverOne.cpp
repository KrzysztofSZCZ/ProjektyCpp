#include <iostream>
#include <vector>
#include <numeric>

int solution(int x, std::vector<int> &A){

    std::vector<int> B(x,-1); // wektor o rozmiwarze x i wypłęniony -1

    for (int i = 0; i<A.size(); i++){
        if(A[i] <= x && B[A[i]-1] == -1)// jeżeli A mieści się w x i wcześniej nie było liścia na tej pozycji
            B[A[i]-1] = i; // wpisujemy, kiedy wystąpiło 
    }
    int max = 0; 
        for (int i = 0; i<B.size(); i++){
            if(B[i]== -1)
                return -1;
            if(max<B[i])
                max = B[i];
        }

    return max;
}

int main(){

    std::vector <int> vec = {1,3,1,4,2,3,5,4};
    std::cout << solution(3, vec);
    return 0;
}