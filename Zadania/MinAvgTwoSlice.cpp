#include<iostream>
#include<vector>
#include <climits>

int solution(std::vector<int> &A){

    float minCouter = INT_MAX;
    int index = 0;

    for(int i = 0; i < A.size() - 2; i++){ //nalezy zauwazyc ze minimalna roznica nie moze byc w kawalku wiekszym niz 3 elementy; zawsze znajdzie sie podkawalek w ktorym bedzie mniejsza 

        float avg1 = (float) (A[i]+A[i+1]+A[i+2])/3;//sprawdzamy 3 elementowy podkawalek
        float avg2 = (float) (A[i]+A[i+1])/2;//i 2 elementowy
        if(minCouter > avg1 || minCouter > avg2){
            minCouter = std::min(avg1,avg2);
            index = i;
        }
    }

    if(minCouter > (A[A.size()-1]+ A[A.size() - 2]) / 2) //sprawdzamy dwa ostatnie elementy ktroe wczesniej nie sa sprawdzone
        return (A.size()-2);

    return index;

}

int main(){

    std::vector<int> vec = {4,2,2,5,1,5,8};
    std::cout<<solution(vec);

    return 0;
}