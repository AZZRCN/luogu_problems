#include <iostream>
using namespace std;
string s;
char buf[1<<20],*p1=buf,*p2=buf;
static unsigned int read() {
	unsigned int n = 0;
	unsigned char ch = getchar();
	while ((ch ^ '0') > 0x9) {ch = getchar();}
	while ((ch ^ '0') < 0xA) {n = n * 0xA + ch - 0x30;ch = getchar();}return n;
}
int main() {
    cin >> s;
    unsigned int n = read();
    while (n) {
        int i;
        for(i = 1; i < s.length(); i++){
            if(s[i-1] > s[i]){
                break;
            }
        }
        s.erase(i - 1 , 1);
        n--;
    }
    s.insert(s.begin(),'0');
    while(s.front() == '0'&& s.size()>1){s.erase(s.begin());}
    cout << s;
}