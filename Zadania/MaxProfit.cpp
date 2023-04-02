#include<iostream>
#include<vector>
#include<algorithm>

int solution(std::vector<int> &A){
    if(A.empty())
        return 0;

    int minimumValue = A[0];
    int maxProfit = 0;
    int profitSum = 0;

    for (int i = 1; i < A.size(); i++){

        if(A[i] < minimumValue){ // nowe minimum, oraz nowy potencjalny profit 
            minimumValue = A[i];
            profitSum = 0;
        }

        else
            profitSum += (A[i] - A[i-1]); //ile zarobię między dwoma dniami

        maxProfit = std::max(maxProfit, profitSum); //sprawdzam czy obecna suma to maksymalny profit jak tak to wpisuje 
    }

    return maxProfit;

}


int main(){

    std::vector<int> vec = {23171, 21011, 21123, 21366, 21013, 21367};
    std::cout << solution(vec);

    return 0;
}