#include <bits/stdc++.h>
using namespace std;
class dcsl_step_base_int{//等差数列
    public:
    unsigned long long now_step,gc;
    unsigned long long len,start,end;
    bool is_end(){
        return now_step==len;
    }
    unsigned long long get(){//我们按照的是从l开始
        return ((now_step)*gc)+start;
    }
    inline void next(){now_step++;};
    dcsl_step_base_int(void){;};
    dcsl_step_base_int(unsigned long long a,unsigned long long b,unsigned long long c){
        len = a;
        start = b;
        end = c;
        now_step=0;
        gc=(end-start)/(len-1);
    };
};
//好吧，坦白了，三步必杀
class dcsl_step_base_int_with_step{//等差数列
    public:
    unsigned long long now_step,gc,l,r;
    unsigned long long len,start,end;
    bool is_end(){
        return now_step==r+1;
    }
    unsigned long long get(){//我们按照的是从l开始
        return ((now_step-l)*gc)+start;
    }
    inline void next(){now_step++;};
    inline bool operator<(const dcsl_step_base_int_with_step & O){
        return l <= O.l;
    }
    dcsl_step_base_int_with_step(void){;};
    //开始项数，结束项数，开始项，结束项
    dcsl_step_base_int_with_step(unsigned long long kaishi,unsigned long long jieshu,unsigned long long first,unsigned long long last){
        l       =   kaishi;
        r       =   jieshu;
        now_step=   l;
        start   =   first;
        end     =   last;
        len     =   jieshu-kaishi+1;
        gc      =   (end-start)/(len-1);
    };
};
class dcsl_step_base_int_controller{
    public:
    unsigned long long pos;
    vector<dcsl_step_base_int_with_step> v;
    void insert(unsigned long long l,unsigned long long r,unsigned long long start,unsigned long long end){
        v.push_back(dcsl_step_base_int_with_step(l,r,start,end));
    }
    void init(){
        sort(v.begin(),v.end());
        pos = 1;
    }
    unsigned long long update(){
        unsigned long long ret = 0;//由于开始不一样,只能遍历
        for(unsigned long long i = 0; i < v.size(); i++){
            if(v[i].now_step == pos){
                ret += v[i].get();
                v[i].next();
                if(v[i].is_end()){
                    v.erase(v.begin()+i);
                    i--;
                }
            }else{
                break;
            }
        }
        pos++;
        return ret;
    }
    bool empty(){
        return v.empty();
    }
};
int main(){
    dcsl_step_base_int_controller controller;
    unsigned long long n,m;
    cin >> n >> m;
    unsigned long long a,b,c,d;
    for(unsigned long long i = 1; i <= m; i++){
        cin >> a >> b >> c >> d;
        controller.insert(a,b,c,d);
    }
    controller.init();
    vector<unsigned long long> v;
    unsigned long long ans = 0,maxn=0,t;
    while(!controller.empty()){
        t = controller.update();
        // v.push_back(t);
        ans ^= t;
        maxn = max(maxn,t);
        // cout << t << " ";
    }
    // cout << endl;
    cout << ans << " " << maxn;
}