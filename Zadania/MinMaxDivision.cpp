#include<iostream>
#include<vector>
#include<algorithm>
//algorytm wyszukiwania binarnego 
bool compareNumbers(int middle, int K, std::vector<int> &A){

    int sum = 0;

    for(int i = 0; i < A.size(); i++){

        sum += A[i];
        if(sum > middle){
            sum = A[i];
            K--;
        }
        if(K <= 0)
            return false;
    }

    return true;

}
int solution(int K, int M, std::vector<int> &A){

    int sum = 0;
    int minimum = 0;
    int maximum = 0;
    int begin = 0;
    int end = 0;

    maximum = A[0];

    for(int i = 0; i < A.size(); i++){
        maximum = std::max(maximum,A[i]);

        sum += A[i];
    }

    begin = maximum;
    end = sum;
    //najmniejsza suma nie może być mniejsza niż największa wartość, ani większa niż suma wsystkich, więc to nase grancie 

    minimum = sum;

    while(begin <= end){ //typwe binary search, sprawdzawmy po któej stronie od middle jest mniejsze i ten obasz dzielismy na pół

        int middle = (begin+end)/2;
        if(compareNumbers(middle,K,A)){
            minimum = middle;
            end = middle - 1;
        }
        else   
            begin = middle + 1;

    }

    return minimum;
}

int main(){

    std::vector<int> vec = {2,1,5,1,2,2,2};
    std::cout<< solution(3,5,vec);
}