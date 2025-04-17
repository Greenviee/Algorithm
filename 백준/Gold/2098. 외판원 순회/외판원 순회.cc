#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int N;
const int MAX_N = 16;
const int INF = 987654321;
int cost[MAX_N][MAX_N], cache[MAX_N][1 << MAX_N];

int travel(int here, int visit) {
	//모든 정점 방문 이후 시작점으로 복귀
	if ((visit | ((1 << N) - 1)) == visit) {
		if (cost[here][0] == 0) return INF;
		return cost[here][0];
	}
	int& ret = cache[here][visit];
	if (ret != -1) return ret;
	ret = INF;
	
	visit |= (1 << here);
	int canVisit = ~visit;
	for (int i = 0; i < N; i++) {
		if ((canVisit & (1 << i)) && cost[here][i] != 0) {
			ret = min(ret, cost[here][i] + travel(i, visit | (1 << i)));
		}
	}
	return ret;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> cost[i][j];
	memset(cache, -1, sizeof(cache));
	cout << travel(0, 0);
}