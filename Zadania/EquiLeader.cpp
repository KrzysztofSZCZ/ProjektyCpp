#include<iostream>
#include<vector>
#include<algorithm>


int solution(std::vector<int> &A){

    std::vector<int> B = A;  //nowy wektor żeby nie zgubić indeksów 
    std::sort(B.begin(), B.end());


    int counter  = 1;
    int leader = 0;
    int leaderCount = 0;

    for(int i = 1; i < B.size(); i++){

        if(B[i] != B[i-1])
            counter = 1;//nowy element więc counter wraca do 1 

        else 
            counter++;

        if(counter > B.size()/2){
            leader = B[i];
            break;
        } // to co wcześniej 
    }

    for(int i = 0; i < A.size(); i++){
        if(A[i] == leader)
           leaderCount++;     
    }

    int EqLeader = 0; // ile mamy tych eqlidwrów
    counter = 0;

    for(int i = 0; i < A.size(); i++){

        if(A[i] == leader)
            counter++; // ile leaderów po lewej stronie 

        if(i+1 < 2*counter && A.size() - (i+1) < 2*(leaderCount- counter)) // jeżeli po lewej i prawej stronie leader ciągle nim jest
            EqLeader++;
    }

    return EqLeader;

}



int main(){

    std::vector<int> vec = {4,3,4,4,4,2};
    std::cout << solution(vec);

    return 0;
}