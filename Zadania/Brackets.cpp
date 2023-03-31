#include<iostream>
#include <vector>
#include<string>


int solution(std::string &S){

    if(S.empty())
        return 1;

    std::vector<int> Stack;

    int current = 0;

    for(int i = 0; i < S.size(); i++){

       if(S[i] == '[')  
        current = 1; 
       if(S[i] == ']')  
        current = -1;
       if(S[i] == '(')  
        current = 2;
       if(S[i] == ')')  
        current = -2;
       if(S[i] == '{')  
        current = 3;
       if(S[i] == '}')  
        current = -3; 

        if(i == 0 && current < 0)//jeżeli pierwszy jest zamykający
            return 0; 

        if(current < 0 && current != -Stack.back()) // jezżeli będzie sytuacja )(
            return 0;

        else if(current < 0) //jeżeli poprawnie zamkniety to zdejmujemy otwarty
            Stack.pop_back();

        else  
            Stack.push_back(current);
    }

    if(Stack.empty())
        return 1;

    else
        return 0;

}

int main(){

    std::string S = ("{[()()]}");
    std::cout << solution(S);

    return 0;
}