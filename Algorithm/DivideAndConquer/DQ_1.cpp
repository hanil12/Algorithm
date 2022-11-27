#include "Framework.h"

// 1부터 n까지의 합 구하기
int fastSum(int n)
{
	// 기저사례
	if (n == 1) return 1;

	if (n % 2 == 1) return fastSum(n - 1) + n;

	return 2 * fastSum(n / 2) + (n / 2) * (n / 2);
}

int main()
{
	cout << fastSum(10) << endl;

	return 0;
}