#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#define not_(ABC) ABC = not ABC
using namespace std;
class STN {
public:
	std::string intpart;
	std::string doublepart;
	std::string bufpart;
	bool zf = true;//true = postive | negtive
	int bufprecision = 100;
	int doubleprecision = 5;
	int intprecision = 100;
	void operator=(int n) {
		init();
		if (n < 0) {
			zf = false;
			n = -n;
		}
		for (int cur = 0; n && cur < intprecision; cur++) {
			intpart[cur] = n % 10+'0';
			n /= 10;
		}
		reverse(intpart.begin(), intpart.end());
	};
	void operator=(double n) {
		init();
		if (n < 0) {
			zf = false;
			n = -n;
		}
		int intp = floor(n);
		for (int cur = 0; intp && cur < intprecision; cur++) {
			intpart[cur] = intp % 10 + '0';
			intp /= 10;
		}
		reverse(intpart.begin(), intpart.end());
		n = n - intp;
		for (int cur = 0; n && cur < doubleprecision; cur++) {
			n *= 10;
			doublepart[cur] = (int)floor(n) % 10 + '0';
			n = n - floor(n);
		}
	}
	void operator=(std::string str) {
		init();
		if (str[0] == '-') {
			zf = false;
		}
		int j = 0,begin = zf?0:1,cur = intprecision-1,end =str.length()-1;
		for(;j < str.length() && str[j] != '.';j++){}
		for (int i = j - 1; i >= begin && cur >= 0; i--) {
			intpart[cur] = str[i];
			cur--;
		}
		if(j < end)
		{
			cur = 0;
			for (int i = j + 1; i <= end && doubleprecision > cur; i++) {
				doublepart[cur] = str[i];
				cur++;
			}
		}
	}
	void print() {
		//const int l = intpart.length();
		//for (int i = 0; i < l; i++) {
		//	putchar(intpart[i]);
		//}
		if (not zf)putchar('-');
		printf("%s.%s", intpart.c_str(),doublepart.c_str());
	};
	void setprecis(const int &intlong, const int &doublelong) {
		doubleprecision = doublelong;
		intprecision = intlong;
	}
	void init() {
		intpart.clear();
		doublepart.clear();
		for (int i = 0; i < intprecision; i++) {
			intpart.push_back('0');
		}
		for (int i = 0; i < doubleprecision; i++) {
			doublepart.push_back('0');
		}
		zf = true;
	}
	void operator*(const int &num) {
		if (num < 0) {
			not_(zf);
		}
		const int n = abs(num);
		int t = 0,carry = 0;
		for (int i = doubleprecision - 1; i >= 0; i--) {
			t = (doublepart[i] - '0') * n+carry;
			doublepart[i] = t % 10+'0';
			carry = (t / 10);
		}
		for (int i = intprecision-1; i >=0; i--) {
			t = (intpart[i] - '0') * n + carry;
			intpart[i] = t % 10 + '0';
			carry = (t / 10);
		}
	}
};
int main(){
    STN n;
    int t;
    cin >> t;
    n = t;
    cin >> t;
    n * t;
    int i = 0;
    for(; i < n.intprecision && n.intpart[i] == '0'; i++) {}
    if(i == n.intprecision){printf("0");}
    for(;i<n.intprecision;i++){printf("%c",n.intpart[i]);}
}