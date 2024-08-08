#include <stdio.h>
#include <math.h>
#include <iostream>
const double PI = 3.141593;
int main()
{
    short T;
    scanf("%hd", &T);
    switch (T)
    {
    case 1:printf("I love Luogu!");break;
    case 2:printf("6 4");break;
    case 3:printf("3\n12\n2");break;
    case 4:printf("166.667");break;
    case 5:printf("15");break;
    case 6:std::cout << sqrt(117);break;
    case 7:printf("110\n90\n0");break;
    case 8:std::cout << 10 * PI << "\n"<< 25 * PI << "\n"<< 125 * PI * 4 / 3;break;
    case 9:printf("22");break;
    case 10:printf("9");break;
    case 11:std::cout << 100.0 / 3;break;
    case 12:printf("%d\n%c", 'M' - 'A' + 1, 'A' + 17);break;
    case 13:printf("16");break;
    case 14:printf("50");break;
    }
}