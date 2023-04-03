#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

std::vector<int> solution(std::vector<int> &A){

    std::vector<int> counts(*std::max_element(A.begin(), A.end()) + 1, 0); // o rozmiarze o jeden większy niż maksymalny
    std::vector<int> Resault;

    for(int i = 0; i < A.size(); i++)
        counts[A[i]]++;//zliczamy ile jakich liczb jest 

    for(int i = 0; i <A.size(); i++){

        int SumOfOccurences = 0;
        for(int j = 1; j*j <= A[i]; j++){ //tylko do pierwistaka sprawdzamy

            if(A[i]%j == 0){ //znaleźliśmy dzielnik
                SumOfOccurences += counts[j];
                if(A[i]/j != j)//jeżli dzielnik nie jest pierwistakiem
                    SumOfOccurences += counts[A[i]/j];
            }
    
        }

        Resault.push_back(A.size() - SumOfOccurences); //rozmiar - dzielniki = niedzielniki
    }

return Resault;

}

//WAŻNE z lekcji 10, nie musimy sprawdzać dzielników do końca, tylko do pierwiastka z badanej liczby
int main(){
    std::vector<int> vec = {3,1,2,3,6};
    std::vector<int> sol = solution(vec);
    
    for(auto& el : sol)
        std::cout << el << " ";
    return 0;
}