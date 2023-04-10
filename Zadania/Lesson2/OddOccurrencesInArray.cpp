#include <iostream>
#include <vector>
#include <algorithm>

int solution (std::vector<int> &A){
    std::sort(A.begin(), A.end());

    for(int i = 0; i < A.size(); i+=2)
    {
        if(A[i] != A[i+1])
            return A[i];
    }

}
//posortowac wektor; sprawdzić czy obecny i sąsiad są równe: jeśli tak- index +2, jeśli nie return

int main(){

    std::vector<int> Vec = {3,6,6,3,8,8,13,6,6,2,2};

    std::cout << solution(Vec);

    return 0;
}