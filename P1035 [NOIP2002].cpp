#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    unsigned long long k;
    scanf("%llu", &k);

    double a = k * 1e18; // 使用double存储计算结果

    int n = 1;
    while (a > 0) {
        a -= round(1e18 / n++); // 使用round函数进行四舍五入
    }

    printf("%d\n", n-1); // 使用printf进行输出

    return 0;
}