#include <bits/stdc++.h>
using namespace std;

int pronic(int num)
{
	int N = (int)sqrt(num);

	if (N * (N + 1) <= num) {
		return N;
	}

	return N - 1;
}

int solution(int A, int B)
{
	return pronic(B) - pronic(A - 1);
}


int main()
{
	int A,B;
    cin>>A>>B;
	cout << solution(A, B);

	return 0;
}
