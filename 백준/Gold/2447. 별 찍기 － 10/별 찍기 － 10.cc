#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int num;
//최대 크기 3^7
string map[2200];

void fill() {
    string s;
    for(int i=0;i<num;i++) s += '*';
    for(int i=0;i<num;i++) map[i] = s;
}

void erase(int x1, int x2, int y1, int y2) {
    if(x1==x2) return;
    
    //9등분 했을 때 한 변의 길이
    int l = (x2-x1+1)/3;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            if(i==1 && j==1) {
                for(int x=x1+l;x<x1+l*2;x++) 
                    for(int y=y1+l;y<y1+l*2;y++)
                        map[y][x] = ' ';
            }
            else erase(x1+l*i, x1+l*(i+1)-1, y1+l*j, y1+l*(j+1)-1);
        }
    }
}

void star() {
    fill();
    erase(0, num-1, 0, num-1);
    for(int i=0;i<num;i++) cout<<map[i]<<endl;
}

int main() {
    cin>>num;
    star();
}