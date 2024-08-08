#include <iostream>
#include <set>
using namespace std;
struct block{
    int line;
    int start;
    int len;
    bool operator<(const block& other) const{
        if(line != other.line){
            return line > other.line;
        }
        if(start != other.start){
            return start < other.start;
        }
        return len < other.len;
    }
    block(int line,int start,int len): line(line),start(start),len(len) {};
};
/*struct line_b{
    int start,len;
};*/
struct cicyle{
    int x,y;
    bool operator<(const cicyle& other) const{
        if(y != other.y) return y > other.y;
        return x > other.x;
    }
    cicyle(int x,int y): x(x),y(y) {};
};
struct little_block{
    int x;
    bool is_cicyle;//false->is a block;
    little_block(int x, bool iscicyle): x(x), is_cicyle(iscicyle) {};
    bool operator<(const little_block& other) const{
        if(x != other.x){
            return x < other.x;
        }
        return is_cicyle < other.is_cicyle;
    }
};
set<block> block_set;
set<cicyle> cicyle_set;
//set<line_b> little_block_set;
set<little_block> little_block_set;
//x横y竖
long long ans = 0;
void slove(){
    /*int last = INT_MIN;
    for(k:little_block_set){
        if(k != last){
            last = k;
            printf("%d ",k);
            ans++;
        }
    }
    printf("\n");
    little_block_set.clear();*/
    //old code
    little_block last = little_block(-2147483648,false);
    bool is_a_cicyle = false;
    for(little_block k:little_block_set){
        if(last.x != k.x){//不在同一个位置
            if(k.is_cicyle){
                ans++;
            }
            else{
                ans += 2;
            }
            // printf("%d-%d\n",k.x,is_a_cicyle);
            is_a_cicyle = false;
            
        }
        // else{//在同一个位置
        is_a_cicyle = k.is_cicyle | is_a_cicyle;
        last = k;
    }
    little_block_set.clear();
    // printf("============================\n");
}
// void to_next(auto &k){
//     k = next(k);
// }
int main(){
    int n,x,y,len;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> x >> y >> len;
        for(int j = 1; j <= len; j++){
            if(len - j != 0)block_set.insert(block(y+j-1,x,len-j));
            cicyle_set.insert(cicyle(x+j-1,y+len-j));
        }
    }
    // printf("----------------------------------------------------\n");
    int last_line = -2147483648;
    /*for(auto k:block_set){
        if(last_line == k.line){
            for(int T = 0; T < k.len; T++){
                little_block_set.insert(little_block(k.start+T,false));
                //printf("add! %d\n",k.line);
            }line_b{k.start,k.len}
        }
        else{
            slove();
            last_line = k.line;
            for(int T = 0; T < k.len; T++){
                little_block_set.insert(little_block(k.start+T,false));
                //printf("add! %d\n",k.line);
            }
        }
    }*/
    std::set<cicyle>::iterator cicyle_iter = cicyle_set.begin();
    std::set<block>::iterator block_iter = block_set.begin();
    while(cicyle_iter != cicyle_set.end() && block_iter != block_set.end()){
        //add cicyle
        while(cicyle_iter->x == last_line){
            little_block_set.insert(little_block(cicyle_iter->y,true));
            cicyle_iter++;
        }
        //add block
        while(block_iter->line == last_line){
            for(int T = 0; T < block_iter->len; T++){
                little_block_set.insert(little_block(block_iter->start+T,false));
                //printf("add! %d\n",k.line);
            }
            block_iter++;
        }
        //done add a line
        slove();
        last_line = min(cicyle_iter->x,block_iter->line);
    }
    slove();
    // printf("%d\ncicyle:%d",ans,cicyle_set.size());
    /*for(auto k:cicyle_set){
        printf("%d %d\n",k.y,k.x);
    }*/
    cout << ans / 2.0;
}