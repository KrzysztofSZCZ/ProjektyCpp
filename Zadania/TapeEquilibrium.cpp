#include <iostream>
#include <vector>
#include <numeric>
#include<climits>

int solution(std::vector<int> &A){

    if (A.size() < 2)
        return 0;

    int Sum = std::accumulate(A.begin(), A.end(), 0);
    int LeftSideSum = 0;
    int MinimalDifference = 2000; //2000 bo zakres jest -1000, 1000
    
    for(auto& el : A){
        LeftSideSum += el;
        int CurrentDiffernece = std::abs(2*LeftSideSum - Sum);
        if (MinimalDifference>CurrentDiffernece)
            MinimalDifference = CurrentDiffernece;
    }
    
    return MinimalDifference;
}

//niewydajnie można dla każdego kolejnego P sumować wszystko z lewej i z prawej ale to czyta wieloktornie każdy element 
// różnica między lewą a prawą to L-R = L-(Całość-L) = 2*L-Całość


int main(){

    std::vector<int> vec = {3,1,2,4,3};

    std::cout << solution(vec);

    return 0;
}