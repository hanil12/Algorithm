#include <iostream>
#include <vector>

using namespace std;

int n;
bool areFriends[10][10];

// ��ǳ
int CountPairngs(bool taken[10])
{
	// ���� �л��� �� ���� ��ȣ�� ���� �л��� ã�´�.
	int firstFree = -1;
	for (int i = 0; i < n; i++)
	{
		if (taken[i] == false)
		{
			firstFree = i;
			break;
		}
	}

	// ����
	// 1. ��� �л��� ¦�� �����ִ�.
	if (firstFree == -1)
		return 1;

	int ret = 0;
	// firstFree �л��� ¦�� ���� �л��� ���Ѵ�.
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++)
	{
		// ¦�� �̹� �ִ�.
		if (taken[pairWith] == true)
			continue;

		// ģ���ΰ�?
		if (areFriends[firstFree][pairWith] == false)
			continue;

		taken[firstFree] = true;
		taken[pairWith] = true;
		ret += CountPairngs(taken);

		// ��ͷ� ���Ƽ� ���� ã�� �� �ٽ� paring Ǯ���ֱ�
		taken[firstFree] = false;
		taken[pairWith] = false;
	}

	return ret;
}

int main()
{
	n = 4;
	int f = 1;
	vector<int> member = { 0,1,1,2,2,3,3,0,0,2,1,3 };

	for (int i = 0; i < member.size(); i++)
	{
		if (i % 2 == 0)
		{
			int firstF = member[i];
			int secondF = member[i + 1];
			areFriends[firstF][secondF] = true;
			areFriends[secondF][firstF] = true;
		}
	}
	
	bool t[10] = { false };
	cout<<CountPairngs(t)<<endl;

	return 0;
}