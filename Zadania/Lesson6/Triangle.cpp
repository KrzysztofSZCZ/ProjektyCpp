#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> &A){

    if(A.size() < 3)
        return 0;
    
    std:sort(A.begin(),A.end());

    for (int i = 0; i < A.size() - 2; i++ ){
        if(A[i] > A[i+2] - A[i+1]) // po to żeby suma dwóch maksymalnych int nie przekroczyła maksimum 
            return 1;
    }

    return 0;
}

//A[i+2]+A[i+1] > A[i] skoro mamy posortowane to samo A[i+2] zawsze bedzie wieksze od A[i] wiec to zawsze prawda 
//A[i+2]+A[i] > A[i+1] podobnie tutaj wiec tez zawsze prawda 
//A[i]+A[i+1] > A[i+2] musimy tylko to sprawdzic

int main(){
    std::vector<int> vec = {10,2,5,1,8,20};
    std::vector<int> vecWrong = {10,50,5,1};

    std::cout << solution(vec) << std::endl;
    std::cout << solution(vecWrong);

    return 0;
}