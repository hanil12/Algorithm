#include <iostream>
#include <vector>

using namespace std;

// 0번부터 차례대로 번호 매겨진 n개의 원소 중 네 개를 고르는 모든 경우를 출력

void PrintPick(const vector<int>& arr)
{
	for (auto v : arr)
	{
		cout << v;
	}
	
	cout << endl;
}

void Pick(int n, vector<int>& picked, int toPick)
{
	// 기저
	if (toPick == 0)
	{
		PrintPick(picked);
		return;
	}

	// 고를 수 있는 가장 작은 번호를 계산한다.
	int smallest = 0;
	if (picked.empty() != true)
	{
		smallest = picked.back() + 1;
	}

	for (int next = smallest; next < n; ++next)
	{
		picked.push_back(next);
		Pick(n, picked, toPick - 1);
		picked.pop_back();
	}
}

int main()
{
	vector<int> t;
	Pick(5,t,4);

	return 0;
}