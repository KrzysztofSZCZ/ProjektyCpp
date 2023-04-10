#include<iostream>
#include<vector>
#include<climits>

int solution(std::vector<int> &A){

    if(A.size() == 2)
        return A[0]+A[1];

    std::vector<int> maxSum(A.size(), INT_MIN);

    maxSum[0] = A[0];
    for(int i = 1; i < A.size(); i++){
        for(int dice = 1; dice <= 6; dice++){
            if(dice > i)
                break;
            maxSum[i] = std::max(maxSum[i], A[i] + maxSum[i - dice]);
        }

    }

    return maxSum[A.size()-1];
}

int main(){
    std::vector<int> vec = {1,-2,0,9,-1,-2};
    std::cout<< solution(vec);

    return 0;
}