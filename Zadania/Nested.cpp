#include<iostream>
#include <vector>
#include<string>

int solution(std::string &S){

    int Counter = 0;

    for(int i = 0; i < S.size(); i++){

        if(S[i] == '(')
            Counter++;
        else if(S[i] == ')')
            Counter--;

        if(Counter < 0) //jakiś zamykający przed otwierającym 
            return 0;
    }
    if(Counter != 0)
        return 0;

    else
        return 1;

}


int main(){

    std::string S = ("((()()))");
    std::cout << solution(S);

    return 0;
}