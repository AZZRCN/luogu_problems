#include <stdio.h>
int main()
{
    int p1, p2, p3, sum;
    char c,p4;
    scanf("%d-%d-%d-%c", &p1, &p2, &p3, &p4);
    sum = ((p1) * 1)
    + ((p2 / 100) * 2)
    + (((p2 / 10) % 10) * 3)
    + ((p2 % 10) * 4)
    + ((p3 / 10000) * 5)
    + (((p3 / 1000) % 10) * 6)
    + (((p3 / 100) % 10) * 7)
    + (((p3 / 10) % 10) * 8)
    + ((p3 % 10) * 9);
    sum %= 11;
    p4 = ((p4 == 'X')?10:p4-'0');
    if (sum == p4)
    {
        printf("Right");
    }
    else
    {
        c = ((sum==10) ? 'X' : sum + '0');
        printf("%d-%d-%d-%d", p1, p2, p3, sum % 11);
    }
    printf("\n%d\n%d %d %d %d", sum,p1,p2,p3,p4);
}