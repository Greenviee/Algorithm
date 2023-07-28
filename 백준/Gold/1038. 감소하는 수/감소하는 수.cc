#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N;
int num[10];
int order = -1;
bool exist = false;

//k = k번째 자리 수 결정
void decrease(int k, bool iszero) {
    if(k==10) {
        order++;
        if(order==N) {
            exist = true;
            if(N==0) cout<<0;
            bool start = false;
            for(int i=0;i<10;i++) {
                if(num[i]!=0 || start) {
                    start = true;
                    cout<<num[i];
                }
            }
        }
        return;
    }
    
    for(int i=0;i<10;i++) {
        //수의 시작이거나 뒷자리 수보다 큰 경우
        //iszero == true 일 경우 다시 0을 받으면 iszero가 true인 상태 유지, 아니면 iszero = false
        if(k==0 || i<num[k-1] || iszero) {
            num[k] = i;
            if(iszero) {
                if(i==0) decrease(k+1, true);
                else decrease(k+1, false);
            }
            else
                decrease(k+1, false);
        }
    }
}

int main() {
    cin>>N;
    decrease(0, true);
    if(!exist) cout<<-1;
}