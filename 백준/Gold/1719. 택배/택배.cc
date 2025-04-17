#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
const int MAX_N = 201;
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
		map[a][b] = c;
		map[b][a] = c;
	}
	floyd();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) cout << "- ";
			else cout << nextNode[i][j] << " ";
		}
		cout << endl;
	}
}