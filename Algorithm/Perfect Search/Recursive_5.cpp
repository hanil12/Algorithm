#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 161 page, ������ ����

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

// board�� (y,x)�� type�� ������� ���ų�, ������ ��ϵ��� ���ش�.
// delta = 1�̸� ����, -1�̸� ������ ����� ���ش�.
// ���� ����� ����� ������ ���� ���...
// ��ġ�ų�, ����ĭ�� ���� �� false�� ��ȯ�Ѵ�.
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

		// �̹� �����ִ� ����̿��� ok�� false.
		else if ((board[ny][nx] += delta) > 1)
			ok = false;
	}

	return ok;
}

int cover(vector<vector<int>>& board)
{
	// ���� ä���� ���� ĭ �� ���� ���� ���ʿ� �ִ� ĭ�� ã�´�.
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

		if (y != -1) break; // �ѹ��� ã���� �׳� 2���� for�� Ż��
	}

	// ������� : ��� ĭ�� ä������ 1�� ��ȯ.
	if (y == -1) return 1;

	// ���ϱ�
	int ret = 0;

	for (int type = 0; type < 4; ++type)
	{
		// ���� board[y][x]�� type ������ ���� �� ������ ���ȣ���Ѵ�.
		if (set(board, y, x, type, 1))
			ret += cover(board);

		// ������ ��ϵ��� ġ���.
		set(board, y, x, type, -1);
	}

	return ret;
}
