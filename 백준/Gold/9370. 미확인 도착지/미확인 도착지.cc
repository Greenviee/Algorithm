#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int T, n, m, t, s, g, h;
const int INF = 987654321;
const int MAX_N = 2001;
vector<pair<int, int>> adj[MAX_N];

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
			if (nextDist < dist[there]) {
				dist[there] = nextDist;
				pq.push(make_pair(-nextDist, there));
			}
		}
	}
	return dist;
}

int main() {
	cin >> T;
	for (int test = 0; test < T; test++) {
		for (int i = 0; i < MAX_N; i++)
			adj[i] = vector<pair<int, int>>();
		cin >> n >> m >> t >> s >> g >> h;
		for (int i = 0; i < m; i++) {
			int a, b, d;
			cin >> a >> b >> d;
			adj[a].push_back(make_pair(b, d));
			adj[b].push_back(make_pair(a, d));
		}
		vector<int> startDijkstra = dijkstra(s);
		vector<int> gDijkstra = dijkstra(g);
		vector<int> hDijkstra = dijkstra(h);
		vector<int> answer;
		int toCross = gDijkstra[h];
		for (int i = 0; i < t; i++) {
			int goal;
			cin >> goal;
			int minDist = startDijkstra[goal];
			if (minDist == min(startDijkstra[g] + toCross + hDijkstra[goal], startDijkstra[h] + toCross + gDijkstra[goal]))
				answer.push_back(goal);
		}
		sort(answer.begin(), answer.end());
		for (int i = 0; i < answer.size(); i++)
			cout << answer[i] << " ";
		cout << endl;
	}
}