#include<iostream>
#include<vector>


int solution(std::vector<int> &A, std::vector<int> &B){

    if(A.size()<2)
        return A.size();// dla 0 elementów zwróci 0 dla 1- 1

    int nonOverlapingSequences = 1; // korzystamy z podobnej rzeczy do greedy algorithims, zawsze będzie conajmniej 1 sekwacnja

    int end = B[0]; 
    // zapisujemy koniec pierwszej lini, i sprawdzamy które kolejne się z nią nie pokrywają

    int i = 1; // pierwszą sprawdzamy więc ją pominiemy 

    while(i < A.size()){

        while(i < A.size() && A[i] <= end)
            i++; // skipujemy te które się pokrywają 

        if(i == A.size())
            break; // s[prawdzone wszystkie]
        //leciemy do kolejnego sgementu
        nonOverlapingSequences++;
        end = B[i];
    }

    return nonOverlapingSequences;

}

int main(){

    std::vector<int> A = {1,3,7,9,9};
    std::vector<int> B = {5,6,8,9,10};
    std::cout<< solution(A,B);
    
}