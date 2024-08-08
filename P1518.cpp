#include <bits/stdc++.h>
#define elif else if
using namespace std;
bool unablego[11][11];
class pos{
    public:
    int x,y,face;//NESW
    pos(int O1,int O2,int O3){x=O1;y=O2;face=O3;};
    pos(void){x=y=0;};
    void go(){
        pos pos_new(x,y,face);
        if(face==0){
            pos_new.x--;
        }
        elif(face==1){
            pos_new.y++;
        }
        elif(face==2){
            pos_new.x++;
        }
        else{
            pos_new.y--;
        }
        if(pos_new.x<1 || pos_new.x> 10 || pos_new.y<1 || pos_new.y>10||unablego[pos_new.x][pos_new.y]){
            face = (face+1)%4;
            cout << "tried to move,but face to the " << face << endl;
        }
        else{
            x=pos_new.x;
            y=pos_new.y;
            cout << "tried to move,go to the " <<x << " " << y << endl;
        }
    }
    bool operator==(const pos &O){
        return x==O.x && y==O.y;
    }
};
bool farmer_map[11][11][4];//x<->,y|,face,visited
bool cow_map[11][11][4];//x<->,y|,face,visited
int main(){
    memset(farmer_map,0,sizeof(farmer_map));
    memset(cow_map,0,sizeof(cow_map));
    memset(unablego,0,sizeof(unablego));
    pos farm;
    pos cow;
    farm.face=cow.face=0;
    char ch;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            ch = getchar();
            if(ch=='F'){
                farm.x=i;
                farm.y=j;
            }
            else if(ch=='C'){
                cow.x=i;
                cow.y=j;
            }
            else if(ch=='*'){
                unablego[i][j]=true;
            }
        }
        getchar();
    }
    bool cow_loop=false,farm_loop=false;
    int ans=0;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            cout << unablego[i][j];
        }
        cout << endl;
    }
    // exit(0);
    while(1){
        if(cow_map[cow.x][cow.y][cow.face]){
            cow_loop=true;
        }
        if(farmer_map[farm.x][farm.y][farm.face]){
            farm_loop=true;
        }
        if(cow_loop&&farm_loop){
            cout << "never,because of loop";
            return 0;
        }
        cow_map[cow.x][cow.y][cow.face]=true;
        farmer_map[farm.x][farm.y][farm.face]=true;
        cout << "cow:";
        cow.go();
        cout << "farmer:";
        farm.go();
        ans++;
        if(cow == farm){
            cout << ans;
            return 0;
        }
    }
}