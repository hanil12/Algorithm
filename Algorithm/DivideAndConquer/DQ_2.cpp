#include "Framework.h"

// 195 page ��Ÿ�� ���� ����

// �� ������ ���̸� �����ϴ� �迭
vector<int> h = { 7,1,5,9,6,7,3 };

int solve(int left, int right)
{
	// ���� ���
	if (left == right)
		return h[left];

	// (left, mid) , (mid, right)�� �� ������ �����Ѵ�.
	int mid = (left + right) / 2;

	// ������ ������ ��������
	int ret = std::max(solve(left, mid), solve(mid + 1, right));

	// �κй��� : �� �κп� ��� ��ġ�� �簢�� �� ���� ū ���� ã�´�.
	int lo = mid;
	int hi = mid + 1;

	int height = std::min(h[lo], h[hi]);

	// [mid, mid + 1]�� �����ϴ� �ʺ� 2�� �簢���� ����Ѵ�.
	ret = max(ret, height * 2);

	// �簢���� �Է� ��ü�� ���� ������ Ȯ���� ������.
	while (true)
	{
		if (left >= lo && hi >= right)
			break;

		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1]))
		{
			++hi;
			height = std::min(height, h[hi]);
		}
		else
		{
			--lo;
			height = std::min(height, h[lo]);
		}

		// Ȯ���� �� �簢���� ����
		ret = std::max(ret, height * (hi - lo + 1));
	}

	return ret;
}

int main()
{
	cout << solve(0,6) << endl;

	return 0;
}