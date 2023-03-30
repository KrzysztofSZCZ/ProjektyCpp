#include<iostream>
#include<vector>

int solution(std::vector<int> &A){
    if(A.empty())
        return 0;

    std::vector<int> Begining(A.size(), 0); //wektor dla miejsca przecięcia z osią ale "dolne" (ujemne zastepujemy 0)
    std::vector<int> End(A.size(), 0); //wektor dla tych samych ale dodatni (przekraczajace rozmiar wektora zajetepujemy rozmiarem)
    std::vector<int> CountBegining(A.size(), 0); //wektor liczacy ile danych pozycji bylo dla dolnego
    std::vector<int> CountEnd(A.size(), 0); //to samo dla gornego

    for(int i = 0; i < A.size(); i++){

        if(i - A[i] <= 0) // wpisanie 0 jezeli ujemne 
            Begining[i] = 0;
        else 
            Begining[i] = i - A[i];

        if(i + A[i] > A.size() -1) //wpisanie jezeli wieksze niz wektor
            End[i] = A.size() -1;
        else 
            End[i] = i + A[i];

        CountBegining[Begining[i]]++;
        CountEnd[End[i]]++; //zliczamy ile pwystapien dla danej pozycji
    }
    
    std::vector<int> CumulativeCounterBegining(A.size(), 0);
    std::vector<int> CumulativeCounterEnd(A.size(), 0);//kumulatywne wektory dla dolnych i gornych

    CumulativeCounterBegining[0] = CountBegining[0];
    CumulativeCounterEnd[0] = CountEnd[0]; // piwresze elementy zawsze bedą takie same 

    for(int i = 1; i < A.size(); i++){ //kumulujemy

        CumulativeCounterBegining[i] = CountBegining[i] + CumulativeCounterBegining[i-1];
        CumulativeCounterEnd[i] = CountEnd[i] + CumulativeCounterEnd[i-1];    
        }

    int counterIntersection = 0;

    for(int i = 0; i<A.size(); i++){
        if(i != 0){
        counterIntersection += (CumulativeCounterBegining[i] - CumulativeCounterEnd[i-1]  // liczba dysków pokrywających daną pozycje
        - CountBegining[i]) //usuwamy te ktore sa wyśrodkowane w tej pozycji
        * CountBegining[i] //mnozymy wszystko przez liczbe dyskow wysrodkowanych w tej pozycji
        + (CountBegining[i]*(CountBegining[i]-1))/2; // przeciecia dyskow wysrodkowanych w tej pozacyji ze soba
        }
        else
            counterIntersection += (CumulativeCounterBegining[i]  // liczba dysków pokrywających daną pozycje
        - CountBegining[i]) //usuwamy te ktore sa wyśrodkowane w tej pozycji
        * CountBegining[i] //mnozymy wszystko przez liczbe dyskow wysrodkowanych w tej pozycji
        + (CountBegining[i]*(CountBegining[i]-1))/2;
       
        if(counterIntersection > 10000000)
           return -1;
    }
    return counterIntersection;
}





int main(){

    std::vector<int> vec = {1,5,2,1,4,0};
    std::cout << solution(vec);

    return 0;
}