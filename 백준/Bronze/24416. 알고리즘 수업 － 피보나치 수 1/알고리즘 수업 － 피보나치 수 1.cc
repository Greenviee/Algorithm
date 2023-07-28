#include <iostream>
#include <cstring>
using namespace std;

int first = 0, second = 0;
int f[41];

int fib(int n) {
    if (n==1 || n== 2) {
        first++;
        return 1;
    }  
    else return (fib(n - 1) + fib(n - 2));
}

int fibonacci(int n) {
    int& ret = f[n];
    if(ret!=-1) return ret;
    ret = 0;
    ret = fibonacci(n-1) + fibonacci(n-2);
    second++;
    return ret;
}

int main()
{
    int N;
    cin>>N;
    memset(f, -1, sizeof(f));
    f[1] = 1, f[2] = 1;
    fib(N);
    fibonacci(N);
    cout<<first<<" "<<second<<endl;
}