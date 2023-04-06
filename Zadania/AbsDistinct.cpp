#include<iostream>
#include<vector>
#include<set>

int solution(std::vector<int> &A){

   std::set<int> s;

   for(int i = 0 ; i < A.size(); i++){

    s.insert(std::abs(A[i]));
   }

    return s.size(); //to działa dlatego, że set nie wpuści kolejnej takiej samej wartości 

}


int main(){

    std::vector<int> vec = {-5,-3-1,0,3,6};
    std::cout<<solution(vec);

    return 0;
}