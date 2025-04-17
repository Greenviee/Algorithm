#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int C, n, d, c;
vector<pair<int, int>> adj[10001];
const int INF = 987654321;

vector<int> dijkstra(int src) {
	vector<int> dist(n + 1, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, src));
	while (!pq.empty()) {
		int here = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		for (int i = 0; i < adj[here].size(); i++) {
			int there = adj[here][i].first;
			int nextDist = cost + adj[here][i].second;
			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}

int main() {
	cin >> C;
	for (int k = 0; k < C; k++) {
		for (int i = 0; i < 10001; i++)
			adj[i] = vector<pair<int, int>>();
		cin >> n >> d >> c;
		for (int i = 0; i < d; i++) {
			int goal, start, weight;
			cin >> goal >> start >> weight;
			adj[start].push_back(make_pair(goal, weight));
		}
		vector<int> ret = dijkstra(c);
		int total = 0;
		int maxTime = 0;
		for (int i = 1; i <= n; i++) {
			if (ret[i] == INF) continue;
			total++;
			if (maxTime < ret[i])
				maxTime = ret[i];
		}
		cout << total << " " << maxTime << endl;
	}
}