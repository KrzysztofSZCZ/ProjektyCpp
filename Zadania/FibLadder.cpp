#include<iostream>
#include<vector>


std::vector<int> solution(std::vector<int> &A, std::vector<int> &B)
{
	int L = A.size();

	std::vector<int> modules(L,0);
	std::vector<int> rungs(L, 0);
	std::vector<int> fibonacci;

	// przeliczenie modułu 2^B[i]
	for (int i = 0; i < L; i++)
		modules[i] = (1 << B[i]) - 1;
	
	// liczby fibbonacieho jak poprzednio 
	fibonacci.push_back(0);
	fibonacci.push_back(1);

	for (int i = 2; i < L + 2; i++)
		fibonacci.push_back(fibonacci[i - 1] + fibonacci[i - 2]);


	for (int i = 0; i < L; i++) {

		rungs[i] = fibonacci[A[i] + 1] & modules[i];

	}


	return rungs;


}
// do każdego z elementó A[i] można dotrzeć jednym skokiem z A[i-1] lub podwójnym skokiem z A[i-2] lub dwoma skokami z A[i-2]
//pstatecznie można doskoczyć do A[i] sumując kombinacje A[i-2] i A[i-1] czyli liczby fibbonciago

int main(){



    return 0;
}