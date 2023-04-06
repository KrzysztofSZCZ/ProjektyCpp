#include<vector>
#include<iostream>

int solution(int M, std::vector<int> &A){

    int counter = 0;
    std::vector<bool> AlreadySeen(M+1, false); // czy juz sprawdzane 

    int begin = 0, end = 0; //zmienne do poruszania się po tablicy

    while(begin < A.size() && end < A.size()){ //całość canterpilar method

        if(AlreadySeen[A[end]] == 0){ //distinct
            counter += (end - begin + 1);

            if(counter > 1000000000)
                return 1000000000;

            AlreadySeen[A[end]] = true;
            end++;
        }

        else{ //not distinct

            AlreadySeen[A[begin]] = false;
            begin++;
        }

    }

    return std::min(counter, 1000000000);
}

//canterpilar oznacza, że będziemhy badać z dwóch stron i porównywać je ze sobą, jeśli jeszcze nie było to zwiększamy counter i porownujemy z drugą stroną

int main(){


    return 0;
}