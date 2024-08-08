#include <stdio.h>
int need, lowcost = 0x7FFFFFFF, num, money, t;
int main()
{
    scanf("%d%d%d", &need, &num, &money);
    t = (((need / num) + ((need % num) ? 1 : 0)) * money);
    lowcost = lowcost > t ? t : lowcost;

    scanf("%d%d", &num, &money);
    t = (((need / num) + ((need % num) ? 1 : 0)) * money);
    lowcost = lowcost > t ? t : lowcost;

    scanf("%d%d", &num, &money);
    t = (((need / num) + ((need % num) ? 1 : 0)) * money);
    lowcost = lowcost > t ? t : lowcost;
    printf("%d\n", lowcost);
}