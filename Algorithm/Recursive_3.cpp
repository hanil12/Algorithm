#include <iostream>
#include <vector>

using namespace std;

// 보글게임
// 5x5 격자 글자판
vector<vector<char>> boggle;

struct Vector2
{
	Vector2(int x, int y) : _x(x), _y(y) {}
	
	Vector2 operator+(const Vector2& other) const
	{
		return Vector2(other._x + _x, other._y + _y);
	}

	int _x;
	int _y;
};

Vector2 dir[8] =
{
	{1,0},
	{-1,0},
	{0,1},
	{0,-1},
	{1,1},
	{-1,1},
	{1,-1},
	{-1,-1},
};

bool InRange(int y, int x)
{
	if (y < 0 || y > 4)
		return false;
	if (x < 0 || x > 4)
		return false;
	return true;
}

bool HasWord(int y, int x, const string& word)
{
	// 기저
	// 1. 시작 위치가 범위 밖이면 실패
	if (InRange(y, x) == false)
		return false;
	// 2. 첫 글자가 일치하지 않으면 실패
	if (boggle[y][x] != word[0])
		return false;
	// 3. 단어의 길이가 1이면 성공
	if (word.size() == 1)
		return true;

	// 인접한 8칸 검사
	for (int i = 0; i < 8; i++)
	{
		int nextY = y + dir[i]._y;
		int nextX = x + dir[i]._x;

		if (HasWord(nextY, nextX, word.substr(1)))
			return true;
	}

	return false;
}

int main()
{
	boggle = 
	{
		{'U','R','L','P','M'},
		{'X','P','R','E','T'},
		{'G','I','A','E','T'},
		{'X','T','N','Z','Y'},
		{'X','O','Q','R','S'} 
	};

	cout << HasWord(1, 1, "PRETTYS") << endl;

	return 0;
}