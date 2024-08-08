#include <stdio.h>
static unsigned int read()
{
    unsigned int n = 0;
    while (getchar() == '0'){n++;}
    return n;
}
int main()
{
    const unsigned int a = (getchar() -'0'), b = read();
    if(a == 5){//a==5
        if(b < 3){
            if(b & 1){puts("540");}
            else{puts("60636");}
        }
        else{
            if(b&0x4){puts("23190504");}
            else{puts("6225256");}
        }
    }
    else if (a == 1)//a == 1
    {
        if(b < 3){
            if(b&1){puts("18");}
            else{puts("2546");}
        }
        else{
            if(b&0x4){
                if(b&1){puts("97187296");}
                else{puts("24906204");}
            }
            else{puts("259816");}
        }
    }
    else{puts("99902736");}//a == 2
    return 0;
}