#include<iostream>
#include<vector>
#include<cmath>

int solution(std::vector<int> &A){
    if(A.size() < 3)
        return 0;


    std::vector<int> Peak;

    for(int i = 1; i < A.size()- 1; i++){ //wpisujemy peaki

        if(A[i] > A[i+1] && A[i] > A[i-1])
            Peak.push_back(i);
    }

    if(Peak.empty())
        return 0;

    else if(Peak.size() == 1)
        return 1;

    int counter = 1;
    int maximumPeaks = 0;

    for(int k = std::min((int) Peak.size(), (int) std::sqrt((int)A.size())) + 1; k >= 1; k--){ //ogólnie zaczynamy od mniejszej z wartości, maksymalnej liczby peaków lub tego wyjasnionego niżej 
        int lastFlagIndex = 0;
        counter = 1;

        for(int i = 0; i < Peak.size(); i++){
            if(Peak[i]- Peak[lastFlagIndex] >= k && counter < k){ //jezeli moge już postawic flage i je jeszcze mam
            counter++;
            lastFlagIndex = i;
            }
        }

    if(counter < maximumPeaks) // jeżeli mam k, w którym już kiedyś miałem maksymalną liczbę falg, to znaczy, że już teraz mniej tylko będzie
        return maximumPeaks;
    
    else if(maximumPeaks < counter) //nowe makismum znalazłem 
        maximumPeaks = counter;

    }
    
}


//kluczowym jest zauważenie, żeby rozłożyć i flag, potrzebuję i-1 dystansów o długości i, więc warunek i*(i-1) <= N, co można
//uprościc do i^2 <= N
int main(){


    return 0;
}