#include <iostream>
#include <vector>
using namespace std;

int N;
long long X;
long long burgerSize[51];
long long pattyNum[51];

long long solution(long long start, int L) {
	if (L == 0) return 1;
	if (start == X) return 0;
	long long ret = 0;
	
	if (start + burgerSize[L - 1] >= X) {
		ret += solution(start + 1, L - 1);
	}
	else if (start + burgerSize[L - 1] + 1 == X) {
		ret += pattyNum[L - 1];
		ret++;
	}
	else {
		ret += pattyNum[L - 1];
		ret++;
		ret += solution(start + burgerSize[L - 1] + 2, L - 1);
	}
	return ret;
}

int main() {
	cin >> N >> X;
	burgerSize[0] = 1;
	pattyNum[0] = 1;
	for (int i = 1; i < 51; i++) {
		burgerSize[i] = 3 + burgerSize[i - 1] * 2;
		pattyNum[i] = 1 + pattyNum[i - 1] * 2;
	}
	long long answer = solution(1, N);
	cout << answer;
}