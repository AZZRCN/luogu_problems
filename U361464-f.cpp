#include <iostream>
#include <queue>

using namespace std;

// 自定义结构体
struct colo {
    int color;
    int value;
    colo(int a, int b) : color(a), value(b) {}
};

// 自定义比较函数
struct cmp {
    bool operator() (const colo& p1, const colo& p2) {
        return p1.value > p2.value;
    }
};

int main() {
    // 创建一个优先队列，并使用自定义比较函数
    priority_queue<colo, vector<colo>, cmp> q;

    // 添加元素到队列中
    q.push(colo("Alice", 30));
    q.push(colo("Bob", 25));
    q.push(colo("Cindy", 34));
    q.push(colo("David", 28));

    // 取出队列中的元素，并输出
    while (!q.empty()) {
        colo p = q.top();
        cout << "Name: " << p.name << ", Age: " << p.age << endl;
        q.pop();
    }

    return 0;
}