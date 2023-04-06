#include<iostream>
#include<vector>
#include<algorithm>

int solution(std::vector<int> &A){

    int begin = 0;
    int end = A.size() - 1;
    int temp = 0;
    int MinimalSum = 0;

    std::sort(A.begin(), A.end());

    if(A[0] >= 0) //wszystkie pozytywne więc dwukrotność najmniejszej wartości jest najmniejszą sumą
        return std::abs(A[0]+A[0]);

    if(A[A.size()-1] <= 0) //podobnie ale wszystkie ujemne
        return std::abs(A[A.size() -1] + A[A.size() -1]);


    MinimalSum = std::abs(2*A[A.size() - 1]);

    while(begin <= end){ //znowu canterpilar

    temp = std::abs(A[begin] + A[end]);

    if(temp < MinimalSum) //znaleziono mniejszą sumę niż obecna 
        MinimalSum = temp;

    if(begin == end) // sprawdziliśmy wszystko
        break;

    else if(std::abs(A[begin + 1] + A[end] <= temp))
        begin++;

    else if(std::abs(A[begin] + A[end - 1] <= temp))
        end--;
    //te dwa dokładnie tak jak wcześniej przesuwamy begin lub end 
    
    else{
        begin++;
        end--;
    }
    }

    return MinimalSum;
}   


int main(){

    std::vector<int> vec = {1,4,-3};

    std::cout<< solution(vec);
    

    return 0;
}