#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q){

    std::vector<int> A(S.size(), 0);
    std::vector<int> C(S.size(), 0);
    std::vector<int> G(S.size(), 0);
    std::vector<int> T(S.size(), 0);
    std::vector<int> R;

    int a = 0, c = 0, g = 0, t = 0; //zliczenia wystąpień

    for (int i = 0; i<S.size(); i++){
        if(S[i] == 'A')
            a++;
        if(S[i] == 'C')
            c++;
        if(S[i] == 'G')
            g++;
        if(S[i] == 'T')
            t++;

        A[i] = a;
        C[i] = c;
        G[i] = g;
        T[i] = t;
    }//wpisujemy ile było jakiej litery w danym momencie
    
    for(int i = 0; i<P.size(); i++){
        if(P[i]==Q[i]){ //jeżeli jest tylko jeden element to sprawdza jaki dodaje do R i zwraca wektor z jednym elementem 
            if(S[P[i]] == 'A')R.push_back(1);
            else if(S[P[i]] == 'C')R.push_back(2);
            else if(S[P[i]] == 'G')R.push_back(3);
            else if(S[P[i]] == 'T')R.push_back(4);
        }

        else if(A[P[i]] < A[Q[i]] || S[P[i]] == 'A') // jeżeli w zakresie p-q występuje A lub obecny element jest A to 1 itd po kolei rosnąco wartością
            R.push_back(1);
        else if(C[P[i]] < C[Q[i]] || S[P[i]] == 'C')
            R.push_back(2);
        else if(G[P[i]] < G[Q[i]] || S[P[i]] == 'G')
            R.push_back(3);
        else if(T[P[i]] < T[Q[i]] || S[P[i]] == 'T')
            R.push_back(4);

    }

    return R;

}


int main(){

    std::string S = {"CAGCCTA"};
    std::vector<int> P = {2,5,0};
    std::vector<int> Q = {4,5,6};

    std::vector<int> vec = solution(S,P,Q);

    for(auto& el : vec)
        std::cout << el << " ";

    return 0;
}