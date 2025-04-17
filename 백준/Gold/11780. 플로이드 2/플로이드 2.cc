#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
const int MAX_N = 101;
const int INF = 987654321;
int map[MAX_N][MAX_N];
int nextNode[MAX_N][MAX_N];

void floyd() {
	for (int i = 1; i <= n; i++)
		map[i][i] = 0;
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > map[i][k] + map[k][j]) {
					map[i][j] = map[i][k] + map[k][j];
					nextNode[i][j] = nextNode[i][k];
				}
			}
}

vector<int> getPath(int start, int goal) {
	vector<int> path;
	if (start == goal) return path;
	path.push_back(start);
	if (nextNode[start][goal] != goal) {
		vector<int> newPath = getPath(nextNode[start][goal], goal);
		path.insert(path.end(), newPath.begin(), newPath.end());
	}
	else
		path.push_back(goal);
	return path;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			map[i][j] = INF;
			nextNode[i][j] = j;
		}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (map[a][b] > c)
			map[a][b] = c;
	}
	floyd();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == INF) cout << 0 << ' ';
			else cout << map[i][j] << ' ';
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] == INF) {
				cout << 0 << endl;
				continue;
			}
			vector<int> path = getPath(i, j);
			cout << path.size() << " ";
			for (int k = 0; k < path.size(); k++)
				cout << path[k] << " ";
			cout << endl;
		}
	}
}