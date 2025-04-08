#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

const int MAX_N = 16;
const int INF = 987654321;
int N;
vector<pair<int, int>> cities;
double cost[MAX_N][MAX_N], cache[MAX_N][1 << MAX_N];

double getDist(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double travel(int here, int visit) {
	if (visit == (1 << N) - 1) 
		return cost[here][0];

	double& ret = cache[here][visit];
	if (ret != -1) return ret;
	ret = INF;

	visit |= (1 << here);
	int canVisit = ~visit;
	for (int i = 0; i < N; i++) {
		if (canVisit & (1 << i))
			ret = min(ret, cost[here][i] + travel(i, visit | (1 << i)));
	}
	return ret;
}

int main() {
	cout << fixed;
	cout.precision(10);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		cities.push_back(make_pair(x, y));
	}
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++) {
			double dist = getDist(cities[i].first, cities[i].second, cities[j].first, cities[j].second);
			cost[i][j] = dist;
			cost[j][i] = dist;
		}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < (1 << N); j++)
			cache[i][j] = -1;
	cout << travel(0, 0);
}