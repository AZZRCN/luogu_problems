#include <iostream>
#include <set>
using namespace std;
set<int> block_set;

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int begin,len;
        cin >> begin >> len;
        for(int j = 0; j < len; j++){
            block_set.insert(begin+j);
        }
    }
    /*auto iter = block_set.begin();
    for (;iter != prev(block_set.end()); iter++) {
        //*(next(iter, 1));
        if(*next(iter,1) == *iter){
            continue;
        }
        printf("%d ",*iter);
    }*/
    int last = INT_MIN;
    for(auto k:block_set){
        if(k != last){
            last = k;
            printf("%d\n",k);
        }
    }
    return 0;
}