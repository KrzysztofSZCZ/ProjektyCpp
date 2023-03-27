#include <iostream>
#include <vector>
#include <algorithm>


int solution(std::vector<int> &A){

    std::sort(A.begin(),A.end());
    if(A[A.size()-1]<= 0 ) // sprawdzamy czy nie ma samych ujemnych
        return 1;

    bool isOne = 0; //sprawdzamy czy występuje 1
    for(int i = 0; i<A.size(); i++){
        if(A[i] == 1)
                isOne = true;
    }
    if(!isOne)
        return 1;

    for (int i = 0; i < A.size() - 1; i++ ){
        if(A[i] > 0 && A[i+1] != A[i] + 1 && A[i+1] != A[i]) //czy jest doatnia, czy kolejna o jeden większa lub równa 
            return A[i] + 1;
    }


}

int main(){

    std::vector<int> Vec = {3,3,4,6,7,8,-12};
    std::cout << solution(Vec);

    return 0;
}