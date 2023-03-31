#include<iostream>
#include<vector>

int solution(std::vector<int> &A, std::vector<int> &B){
    std::vector<int> DownStream;
    int DeadCounter = 0;

    for(int i = 0; i < B.size(); i++){

        if(B[i] == 1) //jeżeli pływnie dwonstream
            DownStream.push_back(A[i]); // to jej rozmiar wpisujemy do tablicy
        else   
            while(!DownStream.empty()) // dla danej płynącej upstream aż ma kogo spotać 
                if(DownStream.back() > A[i]){ // jeżeli najdalsza może ją zjeść
                    DeadCounter++;
                    break;
                }
                else if(DownStream.back() < A[i]){ // jeżeli ona je najdalszą
                    DownStream.pop_back(); //zdjemujmey
                    DeadCounter++;
                }
    }

    return A.size() - DeadCounter; //początkowy rozmiar - zjedzone 


     
}


int main(){

    std::vector<int> A = {4,3,2,1,5};
    std::vector<int> B = {0,1,0,0,0};

    std::cout << solution(A,B);
    return 0;
}