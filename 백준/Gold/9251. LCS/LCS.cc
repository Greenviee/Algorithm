#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

string s1, s2;
int lcs[1001][1001];

int main() {
	cin >> s1 >> s2;
	s1 = "0" + s1;
	s2 = "0" + s2;

	for (int i = 0; i < s1.size(); i++) {
		for (int j = 0; j < s2.size(); j++) {
			if (i == 0 || j == 0)
				lcs[i][j] = 0;
			else if (s1[i] == s2[j])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;
			else
				lcs[i][j] = max(lcs[i][j - 1], lcs[i - 1][j]);
		}
	}
	cout << lcs[s1.size() - 1][s2.size() - 1];
}