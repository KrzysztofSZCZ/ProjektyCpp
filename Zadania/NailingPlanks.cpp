#include<iostream>
#include<vector>

bool CheckIfNailed(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C, int nail){

    int temp = 0;

    std::vector<int> CountC(2*C.size() + 1, 0);

    for(int i = 0; i < nail; i++)
        CountC[C[i]] = 1; //gdzie są gwozdzie 
    
    for(int i = 0; i<CountC.size(); i++){
        temp += CountC[i];
        CountC[i] = temp; //akumulacja wartości
    }

    for (int i = 0; i < A.size(); i++){ 
        if(CountC[A[i]-1] == CountC[B[i]]) // w dana deske nie wbijemy gwozdzia z tego zakresu 
            return false;
    }

    return true;

}

int solution(std::vector<int> &A, std::vector<int> &B, std::vector<int> &C){

    int minimalAmountOfNails = 1;
    int maximalAmountOfNails = C.size();

    if(!CheckIfNailed(A,B,C,maximalAmountOfNails))
        return -1;

    while(minimalAmountOfNails< maximalAmountOfNails){ //znowu klasyczne binary search

        int middle = (minimalAmountOfNails + maximalAmountOfNails)/2;

            if(CheckIfNailed(A,B,C,middle))
                maximalAmountOfNails = middle; // nie odjemujmey tutaj 1, by uwzględnić kilka gwozdzi w tym samym miejscu 

            else
                minimalAmountOfNails = middle + 1;
    }

    return minimalAmountOfNails;
}

int main(){
    std::vector<int> A = {1,4,5,8,};
    std::vector<int> B = {4,5,9,10};
    std::vector<int> C = {4,6,7,10,2};

    std::cout<< solution(A,B,C);

    return 0;
}