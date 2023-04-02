#include <iostream>
#include <vector>

int solution(std::vector<int> &H){

    int counter = 0; //liczy bloki
    int previous = 0; // ostatnio najmniejsza wysokosć

    std::vector<int> Temp; // wektor wszystkich poziomów od ostatniego minimum

    for(int i = 0; i < H.size(); i++){
        if(H[i] > previous){
            previous = H[i]; //nowy poprzedni 
            counter++;
            Temp.push_back(H[i]);
        }

        else if(H[i] < previous){

            int j = Temp.size() - 1;

            while(H[i] < Temp[j]){ // jeżeli h jest mniejsze od największego levelu 
                Temp.pop_back(); //nipotrzebne bo są większe od hi
                j--;
            }

            if(H[i] != Temp[Temp.size()-1]){ //tutaj już tylko mniejsze zostały 
                counter++; //skoro jest mniejsze to trzeba dodać kamień 
                Temp.push_back(H[i]); //obecny rozmiar
            }
            previous = H[i]; //do nowej iteracji
        }
    }

    return counter;
}


int main(){

    std::vector<int> vec = {8,8,5,7,9,8,7,4,8};
    std::cout<< solution(vec);

    return 0;
}