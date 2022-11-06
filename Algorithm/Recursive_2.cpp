#include <iostream>
#include <vector>

using namespace std;

// 0������ ���ʴ�� ��ȣ �Ű��� n���� ���� �� �� ���� ���� ��� ��츦 ���

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
	// ����
	if (toPick == 0)
	{
		PrintPick(picked);
		return;
	}

	// �� �� �ִ� ���� ���� ��ȣ�� ����Ѵ�.
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