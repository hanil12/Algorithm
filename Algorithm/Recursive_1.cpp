#include <iostream>

using namespace std;

// 1부터 n까지의 합을 계산하는 재귀 함수

int Sum(int n)
{
	int result = 0;

	if (n == 1)
		return 1;
	
	return n + Sum(n - 1);
}

int main()
{
	cout << Sum(5) << endl;

	return 0;
}