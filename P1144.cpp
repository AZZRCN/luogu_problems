#include <bits/stdc++.h>
using namespace std;
queue<int> nextpos;
vector<pair<int,int> > path;
vector<int> least;
int main(){
    int M,N,x,y;
    cin >> M >> N;
    for(int i = 0; i <= M;i++){
        least.push_back(0);
    }
    least[1]=1;
    for(int i = 1; i <= N; i++){
        cin >> x >> y;
        if(least[x] == 0 && least[y] == 0){
            //least[x] = 1;
            //least[y] = 1;
            continue;
        }
        if(least[x] == 0){
            least[x] = least[y]+1;
            continue;
        }
        if(least[y] == 0){
            least[y] = least[x]+1;
            continue;
        }
        if(least[x] < least[y] - 1){
            least[y] = least[x]+1;
        }
        if(least[y] < least[x] - 1){
            least[x] = least[y]+1;
        }
    }
    for(int i = 1; i <= M; i++){
        cout << least[i] << endl;
    }
}