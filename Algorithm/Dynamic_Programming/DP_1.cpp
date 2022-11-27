#include "Framework.h"

// 215 page ¿Ü¹ß¶Ù±â

vector<vector<int>> v = vector<vector<int>>(100, vector<int>(100,1));
vector<vector<int>> cache = vector<vector<int>>(100, vector<int>(100, -1));
int n = 10;

int Jump(int y, int x)
{
	if (y >= n || x >= n)
		return 0;
	if (y == n - 1 && x == n - 1)
		return 1;

	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	int jumpSize = v[y][x];

	return ret = Jump(y + jumpSize, x) || Jump(y, x + jumpSize);
}

int main()
{
	int ret = Jump(0, 0);

	return 0;
}