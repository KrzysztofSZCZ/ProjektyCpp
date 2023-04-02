#include<iostream>
#include<vector>
#include<algorithm>

int solution(std::vector<int> &A){
    
    if(A.empty())
        return -1;
    if(A.size() == 1)
        return 0;

    std::vector<int> B = A;  //nowy wektor żeby nie zgubić indeksów 
    std::sort(B.begin(), B.end());
    

    int counter  = 1;

    for(int i = 1; i < B.size(); i++){

        if(B[i] != B[i-1])
            counter = 1;//nowy element więc counter wraca do 1 

        else 
            counter++;

        if(counter > B.size()/2)
            return (std::find(A.begin(), A.end(), B[i]) - A.begin());
    }

    return -1;
}


int main(){

    std::vector<int> vec = {3,4,3,2,3,-1,3,3,};
    std::cout << solution(vec);

    return 0;
}