#include<iostream>
#include<vector>
#include<algorithm>


int solution(std::vector<int> &A){

    if(A.empty())
        return 0;

    std::sort(A.begin(), A.end());
    int counter = 1;

    for(int i = 1; i < A.size(); i++){
          if(A[i] != A[i-1])  
            counter++;
    }

    return counter;
}

int main(){

    std::vector<int> vec = {2,1,1,2,3,1};
    std::cout<<solution(vec);
    return 0;
}