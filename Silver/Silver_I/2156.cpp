/*
문제 : https://www.acmicpc.net/problem/2156
난이도 : Silver I
풀이 : 다이나믹 프로그래밍
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solution(vector < int >& wines) {
	int n = wines.size();
	if (n == 1)
		return wines[0];
	else if (n == 2)
		return wines[0] + wines[1];
	else if (n == 3)
		return max({wines[0] + wines[1], wines[1] + wines[2], wines[0] + wines[2]});
	vector < vector < int > > memo(n, vector<int>(3, 0));
	memo[0][0] = wines[0];
	memo[0][1] = wines[0];
	memo[0][2] = 0;
	memo[1][0] = wines[1];
	memo[1][1] = wines[0] + wines[1];
	memo[1][2] = wines[0];
	memo[2][0] = wines[2] + memo[1][2];
	memo[2][1] = wines[2] + memo[1][0];
	memo[2][2] = wines[0] + wines[1];
	int answer = max({memo[2][0], memo[2][1], memo[2][2]});
	for (int i = 3; i < n; i++) {
		memo[i][0] = wines[i] + memo[i - 1][2];
		memo[i][1] = wines[i] + memo[i - 1][0];
		memo[i][2] = max({ memo[i - 1][0], memo[i - 1][1], memo[i - 1][2] });
	}
	return *max_element(memo[n - 1].begin(), memo[n - 1].end());
}

int main() {
	int n;
	cin >> n;
	vector < int > wines(n);
	for (int i = 0; i < n; i++)
		cin >> wines[i];
	cout << solution(wines) << '\n';
	return 0;
}