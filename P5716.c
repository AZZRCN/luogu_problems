#include <stdio.h>
int main()
{
    short y, m;
    scanf("%hd%hd", &y, &m);
    switch (m)
    {
    case 1:
        printf("31");
        break;
    case 2:
        if (((y & 3) == 0 && (y % 100 != 0)) | (((y % 100) == 0) && ((y % 400) == 0)))
            printf("29");
        else
            printf("28");
        break;
    case 3:
        printf("31");
        break;
    case 4:
        printf("30");
        break;
    case 5:
        printf("31");
        break;
    case 6:
        printf("30");
        break;
    case 7:
        printf("31");
        break;
    case 8:
        printf("31");
        break;
    case 9:
        printf("30");
        break;
    case 10:
        printf("31");
        break;
    case 11:
        printf("30");
        break;
    case 12:
        printf("31");
        break;
    }
}