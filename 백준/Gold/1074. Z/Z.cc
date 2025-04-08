#include <iostream>
#include <math.h>
using namespace std;

//1 2
//3 4 순서
int getquadrant(pair<int, int> leftTop, int size, int y, int x) {
	//1, 2사분면
	if (y < leftTop.first + (size / 2)) {
		//2사분면
		if (x < leftTop.second + (size / 2))
			return 1;
		else
			return 2;
	}
	//3, 4사분면
	else {
		if (x < leftTop.second + (size / 2))
			return 3;
		else
			return 4;
	}
}

int solution(int size, int y, int x) {
	int ret = 0;
	pair<int, int> leftTop = make_pair(0, 0);
	while (size != 1) {
		int quadrant = getquadrant(leftTop, size, y, x);
		for (int i = 0; i < quadrant - 1; i++)
			ret += pow((size / 2), 2);
		if (quadrant == 2)
			leftTop.second += (size / 2);
		else if (quadrant == 3)
			leftTop.first += (size / 2);
		else if (quadrant == 4) {
			leftTop.first += (size / 2);
			leftTop.second += (size / 2);
		}
		size /= 2;
	}
	return ret;
}

int main() {
	int N, y, x;
	cin >> N >> y >> x;
	int size = pow(2, N);
	cout << solution(size, y, x);
}