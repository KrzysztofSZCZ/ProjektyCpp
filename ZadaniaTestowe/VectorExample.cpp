#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


void CountElements(vector<int> &A){
    map<int,int> ElementCount; 

    for(int i = 0; i < A.size(); i++){

            ElementCount[A[i]]++;
    }

    for(auto& el : ElementCount)
        cout << el.first << "//"  << el.second << " ";

}

int main(){

    vector<int> V = {2,4,5,2,3,8,4,1,2};
    cout<< "Vector V: ";
    for(auto& el : V)
        cout<<el << " "; 

    cout<< endl;

    vector<int> S = V;
    sort(S.begin(), S.end());

    cout<< "Vector S: ";
    for(auto& el : S)
        cout<<el << " "; 

    cout<< endl;

    vector<int> I;

    auto it = begin(V);

    while(true){
        it = find(it, end(V), 2);

        if(it == V.end())
            break;
    
    I.push_back(distance(begin(V), it));
    it++;
    }

    cout << "Vector I: ";

    for(auto& el : I )
        cout<< el << " ";

    cout << endl;


    CountElements(S);
    return 0;
}