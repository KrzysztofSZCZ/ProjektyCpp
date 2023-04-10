#include <iostream>
#include<vector>

int solution(std::vector<int> &A){
    long int SumEast = 0;
    long int SumPasses = 0;
    for(int i = 0; i < A.size(); i++){

        if(A[i] == 0){
            SumEast++;
        }

        if(A[i] == 1){
            SumPasses +=SumEast;
        }
    }
    if(SumPasses > 1000000000)
        return -1;
    return SumPasses;



}

int main(){
    std::vector<int> vec = {0,1,0,1,1};
    std::cout << solution(vec);
    return 0;
}