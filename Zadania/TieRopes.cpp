#include<iostream>
#include<vector>



int solution(int K, std::vector<int> &A){

    int ropes = 0;
    int length = 0;

    for(int i = 0; i < A.size(); i++){

        length += A[i]; //dodajemy kolejne liny

        if(length >= K){ // jak mają wystarczającą długość
            ropes++; // "tniemy" linę i zaczynamy od nowa 
            length = 0;
        }
    }

    return ropes;

}

int main(){

    std::vector<int> vec = {1,2,3,4,1,1,3};
    std::cout<<solution(4, vec);
}