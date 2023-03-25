#include <iostream>
#include<vector>
#include<algorithm>

int solution(int N) {

    std::vector<int> BinaryN;

    while (N > 0) {
        BinaryN.push_back(N % 2);
        N /= 2;
    }

    std::reverse(BinaryN.begin(), BinaryN.end());

        for (auto& el : BinaryN) {

        std::cout << el;
    }
    std::cout << std::endl;
    int maxGap = 0;
    int currentGap = 0;

    for(auto& el : BinaryN)
    {
        if(el == 0)
        {
            currentGap++;
        }

        else if (el == 1)
        {
            maxGap = std::max(maxGap, currentGap);
            currentGap = 0;
        }
    }
    return maxGap;
}

int main() {

    int v = solution(257);

    std::cout << "Max Binary gap: "<< v << std::endl;
    return 0;
}