#include <iostream>
#include <vector>

std::vector<int> solution(int N, std::vector<int> &A){
    
    std::vector<int> counter(N,0);
    int maxValue = 0; //największy obecnie counter 
    int buffor = 0; //przechowuje wartość która powinna być wpisana po max counter; uzywany żeby nie trzeba było ciągle robić std::fill

    for (int i = 0; i<A.size(); i++){

        if(A[i] <= N ) //czy miesci się w zakresie; jesli tak to zwiększ counter
            {
                counter[A[i]-1] = std::max(buffor, counter[A[i]-1]) + 1;// albo zwiększa counter, albo uzywa buffora    
                maxValue = std::max(maxValue,counter[A[i]-1]); // update największej obecnie wartości countera
            }
        else
            buffor = maxValue; //jeżeli nie ma countera do tej wartości to wpisujemy do buffora do ilu powinniśmy podnieść każdy counter
    }

    for (auto& el : counter)
    {
        el = std::max(el,buffor); //jeżeli jakiś counter nie był inkrementowany, to powinnien być wyrównany do max z tamtej chwili
    }
    return counter;
}


int main(){

    std::vector<int> vec = {3,4,4,6,1,4,4,};
    std::vector<int> print = solution(5,vec);

    for(auto& el : print)
        std::cout<< el << " ";
    return 0;
}