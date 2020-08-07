/*
문제 : https://www.acmicpc.net/problem/1654
난이도 : Silver III
풀이 : 이분 탐색
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector < int >& cables) {
	long long left = 1, right = *max_element(cables.begin(), cables.end());
	long long answer = 1;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for (int cable : cables)
			cnt += cable / mid;
		if (cnt >= n) {
			answer = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return answer;
}

int main() {
	int K, N;
	cin >> K >> N;
	vector < int > cables(K);
	for (int i = 0; i < K; i++) 
		cin >> cables[i];
	cout << solution(N, cables) << '\n';
	return 0;
}
