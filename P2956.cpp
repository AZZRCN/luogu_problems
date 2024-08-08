#include <iostream>
#include <unordered_set>
#define rHash2(type,chiletypeX,chiletypeY,chileX,childY,name) \
struct name{\
size_t operator()(const type& a)const{\
return hash<chiletypeX>()(a chileX) ^ hash<chiletypeY>()(a childY);\
}}
#define rEqual2(type,childX,childY,name) \
struct name{\
bool operator()(const type& a,const type& b)const{\
return a childX == b childX && a childY == b childY;}}
using namespace std;
class POS {
public:
	int x;
	int y;
    POS(int X, int Y){
        x=X;y=Y;
    }
};
int main() {
	rHash2(POS, int, int, .x, .y, POSHash);
	rEqual2(POS, .x, .y, POSEqual);
	unordered_set<POS, POSHash,POSEqual> set;
    int x,y,i,a,b,c,d;
    cin >> x >> y >> i;
    for(;i;i--){
        cin >> a >> b >> c >> d;
        for(int j = a; j<= c; j++){
            for(int k = b; k<= d; k++){
                set.insert(POS(j,k));
            }
        }
    }
    cout << set.size();
}