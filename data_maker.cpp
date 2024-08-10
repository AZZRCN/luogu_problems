#include <bits/stdc++.h>
using namespace std;
int main(){
    struct _timeb T;
    _ftime(&T);
    srand(T.millitm); //获得毫秒
    printf("%d%d%d %d%d%d",rand(),rand(),rand(),rand(),rand(),rand());
}