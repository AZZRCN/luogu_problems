#include <stdio.h>
#include <stdlib.h>
class Node{
    public:
    int S,E;
    Node(int O1,int O2){S=O1;E=O2;}
    Node(){S = E = 0;}
};
int cmp(const void* a,const void* b){
    return (*(Node*)a).E - (*(Node*)b).E;
}
Node num[1000001]={};
int main(){
    // freopen("in","r",stdin);
    int t1,t2;
    int n;
    // cin >> n;
    scanf("%d",&n);
    for(int i =1; i <= n; i++){
        // cin >> t1 >> t2;
        scanf("%d%d",&t1,&t2);
        num[i].S=t1;
        num[i].E=t2;
    }
    // sort(num+1,num+n+1,cmp);
    qsort(num+1,n,sizeof(Node),cmp);
    int last = 0,ans = 0;
    for(int i = 1;i <= n; i++){
        if(last <= num[i].S){
            // cout << last << " " << num[i].S << " " << num[i].E << endl;
            last = num[i].E;
            ans++;
        }
    }
    // cout << ans;
    printf("%d",ans);
}