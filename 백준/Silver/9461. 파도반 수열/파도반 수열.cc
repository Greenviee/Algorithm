#include <iostream>
#include <string.h>
using namespace std;

long long T[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

long long tri(int n)
{
    if(n<=0) return 0;
    long long& ret = T[n];
    if(ret!=-1) return ret;
    
    ret = tri(n-1) + tri(n-5);
    return ret;
}

int main()
{
    for(int i=11;i<102;i++) T[i] = -1;
    long long answer, num, cnum;
    cin>>cnum;
    for(int c=0;c<cnum;c++) {
        cin>>num;
        answer = tri(num);
        cout<<answer<<endl;
    }
}