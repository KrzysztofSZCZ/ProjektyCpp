#include<iostream>
#include<vector>
#include<algorithm>

int solution(std::vector<int> &A){
    int N = A.size(); // tylko po to żeby nie musieć ciągle pisać A.size()

    if(N < 3)
        return 0;

    std::vector<int> LeftToRight(N,0), RightToLeft(N,0); // wektory sumujące elementy zaczynając z obu stron

    int currentSum = 0;

    for(int i = 1; i < N-1; i++){ // ucinamy brzegi bo X i Z

        currentSum += A[i];
        currentSum = std::max(currentSum, 0); // podobnie jak poprzednio jeżeli suma z elementem miałaby być ujmena to dajemy 0

        LeftToRight[i] = currentSum;
    }

    currentSum = 0;

    for(int i = N-2; i > 1; i--){ //to samo ale od drugiej strony

        currentSum += A[i];
        currentSum = std::max(currentSum, 0);

        RightToLeft[i] = currentSum;

    }

    int maxSum = 0;

    for(int i = 0; i < N-2; i++){

        maxSum = std::max(maxSum, LeftToRight[i]+RightToLeft[i+2]); // włśnie tutaj skipujemy Y, stąd jeden element różnicy 
        //np jeżeli i = 1, to sumujemy sumę do drugiego elementu  i sumę z drugiej strony do elemetu 4, 3 skipujemy bo to Y  
    }

    return maxSum;

}

int main(){

    std::vector<int> vec = {3,2,6,-1,4,5,-1,2};
    std::cout<<solution(vec);

    return 0;
}