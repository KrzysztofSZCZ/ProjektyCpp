#include <iostream>
#include <vector>

std::vector<int> solution(std::vector<int> &A, int K){

    std::vector<int> B(A.size());
    for (int i = 0; i < A.size(); i++){
        B[(i+K)%A.size()] = A[i];
        
    }

    return B;
}

// porusza się o (oldIndex+K)%size

int main(){
    std::vector<int> Before = {2,5,8,3,12};

    std::vector<int> After = solution(Before, 4);

    for (auto& el : After)
    {
        std::cout << el << " ";
    }

    return 0;
}