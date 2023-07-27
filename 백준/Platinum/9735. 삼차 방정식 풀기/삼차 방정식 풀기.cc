#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

//해 범위
const long double L = 1000000;

vector<long double> differentiate(const vector<long double>& poly) {
    int n = poly.size()-1;
    vector<long double> ret;
    for(int i=0;i<poly.size()-1;i++) {
        ret.push_back(poly[i]*n);
        n--;
    }
    return ret;
}

vector<long double> solveNaive(const vector<long double>& poly) {
    vector<long double> ret;
    long double n1, n2, a = poly[0], b = poly[1], c = poly[2];
    if(a==0) {
        if(b==0) return ret;
        else {
            ret.push_back(-c/b);
            return ret;
        }
    }
    //판별식
    if((b*b-4*a*c)>0) {
        n1 = (-b-sqrt(b*b-4*a*c))/(2*a);
        n2 = (-b+sqrt(b*b-4*a*c))/(2*a);
        ret.push_back(n1); ret.push_back(n2);
    }
    else if((b*b-4*a*c)==0) {
        n1 = -b/(2*a);
        ret.push_back(n1);
    }
    sort(ret.begin(), ret.end());
    return ret;
}

long double evaluate(const vector<long double>& poly, long double d) {
    long double ret = 0;
    long double n = poly.size()-1;
    for(int i=0;i<poly.size();i++) {
        ret += poly[i]*pow(d, n);
        n--;
    }
    return ret;
}

vector<long double> solve(const vector<long double>& poly) {
    //방정식 차수 구하기
    int n = poly.size()-1;
    //근의 공식으로 해결할 수 있는 2차 이하의 방정식은 근의 공식 사용
    if(n<=2) return solveNaive(poly);
    //도함수 구하기
    vector<long double> derivate = differentiate(poly);
    //도함수의 해를 구해서 극점 구하기
    vector<long double> sols = solve(derivate);
    sols.insert(sols.begin(), -L-1);
    sols.insert(sols.end(), L+1);
    
    vector<long double> ret;
    //이분법으로 해 구하기
    for(int i=0;i+1<sols.size();i++) {
        long double x1 = sols[i], x2 = sols[i+1];
        long double y1 = evaluate(poly, x1), y2 = evaluate(poly, x2);
        //극점이 해인 경우
        if(fabs(y1-0)<1e-10) {
            ret.push_back(x1);
            continue;
        }
        if(fabs(y2-0)<1e-10) {
            ret.push_back(x2);
            continue;
        }
        //두 극점의 부호가 같을 경우 해가 없음
        if(y1*y2>0) continue;
        //불변조건
        if(y1>y2) { swap(x1, x2); swap(y1, y2); }
        for(int iter=0;iter<100;iter++) {
            long double mx = (x1+x2)/2;
            long double my = evaluate(poly, mx);
            if(y1*my>0) {
                x1 = mx;
                y1 = my;
            }
            else {
                x2 = mx;
                y2 = my;
            }
        }
        ret.push_back((x1+x2)/2);
    }
    sort(ret.begin(), ret.end());
    
    return ret;
}

int main() {
    cout<<fixed; cout.precision(4);
    int C; cin>>C;
    while(C--) {
        vector<long double> poly;
        long double d;
        for(int i=0;i<4;i++) {
            cin>>d;
            poly.push_back(d);
        }
        vector<long double> solution = solve(poly);
        for(int i=0;i<solution.size();i++) {
            if(i<solution.size()-1 && fabs(solution[i]-solution[i+1])<0.0001) continue;
            cout<<solution[i]<<' ';
        }
        cout<<endl;
    }
}
