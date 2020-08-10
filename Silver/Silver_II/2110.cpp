/*
문제 : https://www.acmicpc.net/problem/2110
난이도 : Silver II
풀이 : 이분 탐색
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int c, vector < int >& positions) {
	sort(positions.begin(), positions.end());
	int n = positions.size();
	int low = 1, high = positions.back() - positions.front();
	int answer = 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		int cnt = 1;
		auto it = positions.begin();
		while (true) {
			it = lower_bound(it, positions.end(), *it + mid);
			if (it == positions.end())
				break;
			cnt++;
		}
		if (cnt >= c) {
			answer = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return answer;
}

int main() {
	int N, C;
	cin >> N >> C;
	vector < int > positions(N);
	for (int i = 0; i < N; i++)
		cin >> positions[i];
	cout << solution(C, positions) << '\n';
	return 0;
}
