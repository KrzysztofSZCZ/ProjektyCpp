#include<iostream>
#include<vector>

int solution(std::vector<int> &A){

    int sum = 0;
    int maxValue = 0;
    int minimal = 0;

    for(int i = 0; i < A.size(); i++){

        A[i] = std::abs(A[i]);
        maxValue = std::max(maxValue, A[i]);
        sum += A[i]; 
    }

    std::vector<int> count(maxValue+1, 0);

    for(int i  = 0; i < A.size(); i++){
        count[A[i]]++;//zliczenia ile razy dana liczba wystąpi
    }
    
    std::vector<int> dp(sum+1, -1);

    dp[0] = 0;

    for(int i = 1; i <= maxValue; i++){

        if(count[i] <= 0 )
            continue;

        for(int j = 0; j < sum; j++){

            if(dp[j] >= 0)
                dp[j] = count[i];

            else if(j >= i && dp[j-i] > 0)
                dp[j] = dp[j-i] - 1;

            
        }
    }

    minimal = sum;

    for(int i = 0; i*2 <= sum; i++){

        if(dp[i] >= 0){
            int difference = sum - 2*i;
            minimal = std::min(minimal,difference);

        }
    }

    return minimal;
}


int main(){


    return 0;
}