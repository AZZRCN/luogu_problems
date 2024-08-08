#include <iostream>
#include <queue>
using namespace std;
queue<int> Q;
int main(){
    int n,x,y;
    // freopen("out","w",stdout);
    cin >> n;
    while(n--){
        cin >> x;
        switch (x)
        {
        case 1:
            cin >> y;
            Q.push(y);
            break;
        case 2:
            if(Q.empty()) printf("ERR_CANNOT_POP\n");
            else Q.pop();
            break;
        case 3:
            if(Q.empty()) printf("ERR_CANNOT_QUERY\n");
            else printf("%d\n",Q.front());
            break;
        case 4:
            printf("%d\n",Q.size());
            break;
        default:
            break;
        }
        
    }
}