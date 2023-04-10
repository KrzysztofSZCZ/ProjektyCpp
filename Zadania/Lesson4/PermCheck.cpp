#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> &A){

    std::sort(A.begin(), A.end());

    for(int i = 0; i < A.size(); i++){

        if(A[i] != i+1)
            return 0;

    }

    return 1;
}

int main(){
    std::vector<int> vec = {4,1,5,3,2};
    std::vector<int> vecWrong = {4,1,3};

    std::cout << solution(vec) << std::endl;
    std::cout << solution(vecWrong) << std::endl;


    return 0;
}