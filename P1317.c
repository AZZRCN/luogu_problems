#include <stdio.h>
#include <stdbool.h>
int main(){
    short a,pre,now,ans=-1,c=0;
    //true up
    //false down
    scanf("%hd%hd",&a,&now);
    for(short i = 2; i<=a;i++){
        pre = now;
        scanf("%hd",&now);
        if(now>pre & c){
            c = 0x0;ans++;
        }
        else if(now<pre & ~c){
            c = 0xFFFF;ans++;
        }
    }
    printf("%hd",ans>>1);
}