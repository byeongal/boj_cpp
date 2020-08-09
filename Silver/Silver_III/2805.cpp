/*
문제 : https://www.acmicpc.net/problem/2805
난이도 : Silver III
풀이 : 이분 탐색
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solution(int m, vector < int > & trees) {
	int answer = 0;
	long long left = 0, right = *max_element(trees.begin(), trees.end()) - 1;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long total = 0;
		for (int height : trees) 
			total += max((height - mid), 0LL);
		if (total >= m) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}
	}
	return answer;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector < int > trees(n);
	for (int i = 0; i < n; i++)
		cin >> trees[i];
	cout << solution(m, trees) << '\n';
	return 0;
}