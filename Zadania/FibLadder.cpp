#include<iostream>
#include<vector>

int Fib(int M) {

	if (M == 0)
		return 0;

	else if (M == 1)
		return 1;

	else
		return Fib(M - 1) + Fib(M - 2);

}

std::vector<int> solution(std::vector<int> &A, std::vector<int> &B)
{
	int L = A.size();

	std::vector<int> modules(L,0);
	std::vector<int> rungs(L, 0);
	std::vector<int> fibs;

	// pre-compute module 2^B[i]
	for (int i = 0; i < L; i++)
		modules[i] = (1 << B[i]) - 1;
	
	// compute the fibonacci numbers 
	fibs.push_back(0);
	fibs.push_back(1);

	for (int i = 2; i < L + 2; i++)
		fibs.push_back(fibs[i - 1] + fibs[i - 2]);

	// To climb to A[i] rungs, you could either come from A[i] - 1 with an 1 or A[i] -2 with 2 steps.
	// Therefore, the number of different ways of climbing to the top of the ladder is the Fibonacci number at A[i] + 1
	for (int i = 0; i < L; i++) {

		rungs[i] = fibs[A[i] + 1] & modules[i];

		//cout << rungs[i] << endl;
	}


	return rungs;


}
// do każdego z elementó A[i] można dotrzeć jednym skokiem z A[i-1] lub podwójnym skokiem z A[i-2] lub dwoma skokami z A[i-2]
//pstatecznie można doskoczyć do A[i] sumując kombinacje A[i-2] i A[i-1] czyli liczby fibbonciago

int main(){



    return 0;
}