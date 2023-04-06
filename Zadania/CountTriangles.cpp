#include<iostream>
#include<vector>
#include<algorithm>

int solution(std::vector<int> &A){

    int counter = 0;
    std::sort(A.begin(), A.end());

    for(int i = 0; i < A.size(); i++){

        int j = i + 2;

        for(int k = i +1; k < A.size(); k++){

            while(j < A.size() && A[i] + A[k] > A[j]) // dopóki A[i+2] nie będzie końcem i możliwy jest ten trójkąt 
                j++; // przesuwamy nasze sprawdzenie 

            counter+= j - k -1; // wszystkie trójkąty dla danego i, i+1
        }
    }
    return counter;
}
//myslałem że będzie gorszy performance, bo dla kazdego i sprawdzamy rózne i+1 a dla niego różn i +2

//A[i+2]+A[i+1] > A[i] skoro mamy posortowane to samo A[i+2] zawsze bedzie wieksze od A[i] wiec to zawsze prawda 
//A[i+2]+A[i] > A[i+1] podobnie tutaj wiec tez zawsze prawda 
//A[i]+A[i+1] > A[i+2] musimy tylko to sprawdzic
//trzeba to pamiętać z wcześniejszego zadania 
int main(){
    std::vector<int> vec  ={10,2,5,1,8,12};

    std::cout<<solution(vec);
}