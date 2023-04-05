#include<iostream>
#include<vector>

int solution(std::vector<int> &A){

    A.push_back(1); // dodajemy liść na koniec, symulujący drugi brzeg

    std::vector<float> fibonacci(100,0);
    fibonacci[1] = 1;
    for(unsigned int i = 2; i < 100; i++){
        fibonacci[i] = fibonacci[i-1] + fibonacci[i-2]; //wpisujemy liczby fibbonaciego
        if(fibonacci[i] > A.size()) // większe niż szerokość rzeki nie mają sensu
            break;
    }

    fibonacci.erase(fibonacci.begin());
    fibonacci.erase(fibonacci.begin()); // usuwamy 0 i 1, bo o 0 nie może skakać, a skok o 1 jest powtórzony w 3 elemencie

    std::vector<int> reachableSteps(A.size(), 0);

    for(unsigned int i = 0; i < A.size(); i++){
        if(A[fibonacci[i]- 1 ] == 1) // jeśli na pozycji mamy liść 
            reachableSteps[fibonacci[i] - 1] = 1; // znaczy że jest osiągalny po liczbie fibboniciego 
    }

    for(unsigned int i = 0; i < A.size(); i++){
        if(A[i] == 0 || reachableSteps[i] > 0) // jeśli nie ma liści lub już został speawdzony
        continue;

        int minimumI = -1;
        int minimumValue = 100000;

        for(unsigned int j = 0; j < fibonacci.size(); j++){

            int previousI = i - fibonacci[j]; // gdzie wylądujemy jak się cofniemy 
            if(previousI < 0) // z tego miejsca nie skoczymy, bo go nie ma
                break; 
            if(reachableSteps[previousI] > 0 && minimumValue > reachableSteps[previousI]){ // czy fakjtycznie tam będzie liść i  czy liczba skoków bedzie minimalna
                minimumValue = reachableSteps[previousI];
                minimumI = previousI;
            }
        }

        if(minimumI != -1) //ile razy trzeba skoczyć, zeby doskoczyć do tego miejsca 
            reachableSteps[i] = minimumValue+1;
    }

    if(reachableSteps[A.size() - 1] > 0) // czy można doskoczyć do ostatniego miejsca
        return reachableSteps[A.size() - 1];
    else return -1;
    
    
    }




int main(){
    std::vector<int> vec = {0,0,0,1,1,0,1,0,0,0,0};
    std::cout<<solution(vec);

    return 0;
}