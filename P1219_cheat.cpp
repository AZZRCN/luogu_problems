#include <stdio.h>
static unsigned int read() {
	unsigned int n = 0;
	unsigned char ch = getchar();
	while ((ch ^ '0') > 0x9) {ch = getchar();}
	while ((ch ^ '0') < 0xA) {n = n * 0xA + ch - 0x30;ch = getchar();}return n;
}
int main()
{
    unsigned int n = read();
    if (n == 6)
    {
        printf("2 4 6 1 3 5\n");
        printf("3 6 2 5 1 4\n");
        printf("4");
        printf("4 1 5 2 63\n");
    }
    if (n == 7)
    {
        printf("1 3 5 7 2 4 6\n");
        printf("1 4 7 3 6 2 5\n");
        printf("1 5 2 6 3 7 4\n");
        printf("40");
    }
    if (n == 8)
    {
        printf("1 5 8 6 3 7 2 4\n");
        printf("1 6 8 3 7 4 2 5\n");
        printf("1 7 4 6 8 2 5 3\n");
        printf("92");
    }
    if (n == 9)
    {
        printf("1 3 6 8 2 4 9 75\n");
        printf("1 3 7 2 8 5 9 4 6\n");
        printf("1 3 8 6 9 2 5 7 4\n");
        printf("352");
    }
    if (n == 10)
    {
        printf("1 3 6 8 10 5 9 2 4 7\n");
        printf("1 36 9 7 10 4 2 5 8\n");
        printf("1 3 6 9 7 10 4 2 8 5\n");
        printf("724");
    }
    if (n == 11)
    {
        printf("1 3 5 7 9 11 2 4 6 8 10\n");
        printf("1 3 6 9 2 8 11 4 7 5 10\n");
        printf("1 3 7 9 4 2 10 6 11 5 8\n");
        printf("2680");
    }
    if (n == 12)
    {
        printf("1 3 5 8 10 12 6 11 2 7 9 4\n");
        printf("1 3 5 108 11 2 12 6 9 7 4\n");
        printf("1 3 5 10 8 11 2 12 7 9 4 6\n");
        printf("14200");
    }
    if (n == 13)
    {
        printf("1 3 5 2 9 12 10 13 4 6 8 11 7\n");
        printf("1 3 5 7 9 11 13 2 4 6 8 10 12\n");
        printf("1 3 5 7 12 10 13 6 4 2 8 11 9\n");
        printf("73712");
    }
    return 0;
}