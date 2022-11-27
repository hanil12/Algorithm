#include "Framework.h"

// 195 page 울타리 짓기 문제

// 각 판자의 높이를 저장하는 배열
vector<int> h = { 7,1,5,9,6,7,3 };

int solve(int left, int right)
{
	// 기저 사례
	if (left == right)
		return h[left];

	// (left, mid) , (mid, right)로 두 문제를 분할한다.
	int mid = (left + right) / 2;

	// 분할한 문제를 각개격파
	int ret = std::max(solve(left, mid), solve(mid + 1, right));

	// 부분문제 : 두 부분에 모두 걸치는 사각형 중 가장 큰 것을 찾는다.
	int lo = mid;
	int hi = mid + 1;

	int height = std::min(h[lo], h[hi]);

	// [mid, mid + 1]만 포함하는 너비 2인 사각형을 고려한다.
	ret = max(ret, height * 2);

	// 사각형이 입력 전체를 덮을 때까지 확장해 나간다.
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

		// 확장한 후 사각형의 넓이
		ret = std::max(ret, height * (hi - lo + 1));
	}

	return ret;
}

int main()
{
	cout << solve(0,6) << endl;

	return 0;
}