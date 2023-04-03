#include<iostream>
#include<vector>
#include<numeric>


int solution(std::vector<int> &A){
    if(A.size() < 3)
        return 0;

    std::vector<int> Peak(A.size(), 0);
    
        for(int i = 1; i < A.size()- 1; i++){ //wpisujemy peaki

        if(A[i] > A[i+1] && A[i] > A[i-1])
            Peak[i] = 1;
    }

    int SumOfPeaks = std::accumulate(Peak.begin(), Peak.end(), 0);
    if(SumOfPeaks == 0)
        return 0;

    for(int k = SumOfPeaks; k >= 2; k--){

        if(A.size() % k != 0) //wychodzi że rozmiar kawałków byłby niecałkowity
            continue;
        
        int N = A.size()/k; // rozmiar kawałka 

        int PeaksSoFar = 0;
        int* i = 0;

        for(i = 0; i < Peak.size(); i++){

            PeaksSoFar += Peak[i];
            if((i+1)% N == 0 && PeaksSoFar < 1) // jeżeli kawałek się skończył i nie ma peaku żądnego
                break; // z tym rozmiarem nie zadziała 
            else if((i+1)%N == 0)
                PeaksSoFar = 0; //koniec kawałka ale był peak, więc badamy nowy 
        }
        if(*i >= A.size()) //każdy kawałek ma conajmniej jeden slice 
            return k;
        
    }

    return 1; // można tylko w jeden kawałek, bo doszliśmy do końca i nam nie zwóriło k
    
}


int main(){



    return 0;
}