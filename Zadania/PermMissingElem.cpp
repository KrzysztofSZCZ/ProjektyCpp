#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> &A ){

    std::sort(A.begin(), A.end());

    for(int i = 0; i<A.size(); i++){

        if(A[i] != i+1)
            return i+1;

    }

}


int main(){

    std::vector<int> Vec = {2,3,6,5,4,};
    std::cout << solution(Vec);
    return 0;
}