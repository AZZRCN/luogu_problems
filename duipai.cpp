#include<bits/stdc++.h>
using namespace std;
int main()
{
    while (1) //一直循环，直到找到不一样的数据
    {
        system("data_maker.exe > in");
        system("P1303.exe < in > out");
        system("P1303_std.exe < in > std");
        if (system("fc out std")) //当 fc 返回 1 时，说明这时数据不一样
            break;                          //不一样就跳出循环
    }
    return 0;
}