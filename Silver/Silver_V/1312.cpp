#include<iostream>

using namespace std;

int solution(int a, int b, int c) {
	int answer = 0;
	a = a % b;
	for (int i = 0; i < c; i++) {
		a = a * 10;
		answer = a / b;
		a = a % b;
	}
	return answer;
}
int main() {
	int a, b, n;
	cin >> a >> b >> n;
	cout << solution(a, b, n) << '\n';
	return 0;
}