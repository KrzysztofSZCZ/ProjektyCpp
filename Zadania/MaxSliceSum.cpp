#include<iostream>
#include<vector>
#include <algorithm>

int solution(std::vector<int> &A){
    
    int currentSum = 0;
    int maxSum = A[0];

    for (int i = 0; i < A.size(); i++){

        currentSum += A[i]; //dodajemy kolejne elementy
        currentSum = std::max(currentSum, A[i]); // ważny element całego algorytmu; jeżeli w danym momencie suma po dodaniu elementu
        //jest mniejsza niż sam element, oznacza to, ze musimy zacząć nowy kawałek od tego elementu, bo nie ma możliwości żeby dodajac ten wcześniejszy 
        //uzyskać większą sume; efektywnie ozancza to, zę suma jest wtedy ujemna więc zaczynamy nową sumę

        maxSum = std::max(maxSum, currentSum); // patrzymy czy obecna suma jest większa od chwilowo maksymalnej 

    }
    return maxSum;

}

//kadane algorithm
int main(){

    std::vector<int> vec = {3,2,-6,4,0};
    std::cout<< solution(vec);
    
    return 0;
}