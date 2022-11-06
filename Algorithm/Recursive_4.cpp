#include <iostream>
#include <vector>

using namespace std;

int n;
bool areFriends[10][10];

// 소풍
int CountPairngs(bool taken[10])
{
	// 남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
	int firstFree = -1;
	for (int i = 0; i < n; i++)
	{
		if (taken[i] == false)
		{
			firstFree = i;
			break;
		}
	}

	// 기저
	// 1. 모든 학생이 짝을 지어있다.
	if (firstFree == -1)
		return 1;

	int ret = 0;
	// firstFree 학생과 짝을 지을 학생을 정한다.
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++)
	{
		// 짝이 이미 있다.
		if (taken[pairWith] == true)
			continue;

		// 친구인가?
		if (areFriends[firstFree][pairWith] == false)
			continue;

		taken[firstFree] = true;
		taken[pairWith] = true;
		ret += CountPairngs(taken);

		// 재귀로 돌아서 답을 찾은 후 다시 paring 풀어주기
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