#include <iostream>
#include <vector>
#include<algorithm>

int solution(std::vector<int> &A){

    std::sort(A.begin(), A.end());
    int N = A.size();
    int P1 = A[N-1]*A[0]*A[1]; //case 1: największa liczba i dwie najmniejsze(ujemne)
    int P2 = A[N-1]*A[N-2]*A[N-3]; // case 2: 3 największe liczby
    //w żadnym innym przypadku wynik nie będzie największym produktem

    int maxProduct = std::max(P1,P2);
    return maxProduct; 


}


int main(){
    std::vector<int> vec = {-3,1,2-2,5,6};
    std::cout << solution(vec);
    return 0;
}