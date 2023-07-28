#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int C, location, N;
    cin>>C;
    for(int c=0;c<C;c++) {
        cin>>N>>location;
        vector<int> priorities;
        int x;
        for(int i=0;i<N;i++) {
            cin>>x;
            priorities.push_back(x);
        }
        int answer = 0;
        bool check = true;
        int size = priorities.size();
        //탐색 범위 제한하기 위한 변수 설정
        int k = 0;
        while(1) {
            check = true;
            for(int i = k+1;i<k+size;i++) {
                if(priorities[k]<priorities[i]) {
                    priorities.push_back(priorities[k]);
                    k++;
                    check = false;
                    break;
                }
            }
            if(check) {
                if(priorities[k]!=-1) answer++;
                priorities.push_back(-1);
                if(location==k%size) {
                    cout<<answer<<endl;
                    break;
                }
                k++;
            }
        }
    }
}