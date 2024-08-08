#include <stdio.h>
int main() {
    short a, b, c, d;
    scanf("%hd%hd%hd%hd", &a, &b, &c, &d);
    printf("%d %d", (c - a) - ((d > b) ? 0 : 1), (d + 60 - b) % 60);
}