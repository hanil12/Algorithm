#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 161 page, 게임판 덮기

bool set(vector<vector<int>>& board, int y, int x, int type, int delta);
int cover(vector<vector<int>>& board);

const int coverType[4][3][2]
{
	{{0,0}, {1,0}, {0,1}}, // b
	{{0,0}, {0,1}, {1,1}}, // c
	{{0,0}, {1,0}, {1,1}}, // d
	{{0,0}, {1,0}, {1,-1}} // e
};

int main()
{

	return 0;
}

// board의 (y,x)를 type번 방법으로 덮거나, 덮었던 블록들을 없앤다.
// delta = 1이면 덮고, -1이면 덮었던 블록을 없앤다.
// 만약 블록이 제대로 덮히지 않은 경우...
// 겹치거나, 검은칸을 덮을 때 false를 반환한다.
bool set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
	bool ok = true;

	for (int i = 0; i < 3; i++)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= board.size()
			|| nx < 0 || nx >= board.size())
			ok = false;

		// 이미 덮혀있던 블록이여도 ok는 false.
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}

	return ok;
}

int cover(vector<vector<int>>& board)
{
	// 아직 채우지 못한 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾는다.
	int y = -1;
	int x = -1;

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 0)
			{
				y = j;
				x = i;
				break;
			}
		}

		if (y != -1) break; // 한번에 찾으면 그냥 2차원 for문 탈출
	}

	// 기저사례 : 모든 칸을 채웠으면 1을 반환.
	if (y == -1) return 1;

	// 구하기
	int ret = 0;

	for (int type = 0; type < 4; ++type)
	{
		// 만약 board[y][x]를 type 형대토 덮을 수 있으면 재귀호출한다.
		if (set(board, y, x, type, 1))
			ret += cover(board);

		// 덮었던 블록들을 치운다.
		set(board, y, x, type, -1);
	}

	return ret;
}
