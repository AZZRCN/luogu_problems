#include <stdio.h>

int main(){
    int m,n;
    // scanf("%d%d",&m,&n);
    m = 129;
    n=137;
    int m1 = m/1000000000,
        m2 = (m/100000000)%10,
        m3 = (m/10000000)%10,
        m4 = (m/1000000)%10,
        m5 = (m/100000)%10,
        m6 = (m/10000)%10,
        m7 = (m/1000)%10,
        m8 = (m/100)%10,
        m9 = (m/10)%10,
        m10 = m%10;
    int n1 = n/1000000000,
        n2 = (n/100000000)%10,
        n3 = (n/10000000)%10,
        n4 = (n/1000000)%10,
        n5 = (n/100000)%10,
        n6 = (n/10000)%10,
        n7 = (n/1000)%10,
        n8 = (n/100)%10,
        n9 = (n/10)%10,
        n10 = n%10;
    printf("%d %d %d %d %d %d %d %d %d %d\n",m1,m2,m3,m4,m5,m6,m7,m8,m9,m10);
    printf("%d %d %d %d %d %d %d %d %d %d\n",n1,n2,n3,n4,n5,n6,n7,n8,n9,n10);
    int r1,r2,r3,r4,r5,r6,r7,r8,r9,r10;
    int ans[10]={0,0,0,0,0,0,0,0,0,0};
    for(r1=m1;r1<=n1;r1++){
        for(r2=m2;r2<=n2;r2++){
            for(r3=m3;r3<=n3;r3++){
                for(r4=m4;r4<=n4;r4++){
                    for(r5=m5;r5<=n5;r5++){
                        for(r6=m6;r6<=n6;r6++){
                            for(r7=m7;r7<=n7;r7++){
                                for(r8=m8;r8<=n8;r8++){
                                    for(r9=m9;r9<=n9;r9++){
                                        for(r10=m10;r10<=n10;r10++){
                                            printf("TE\n");
                                            if(r1 == 0){
                                                if(r2 == 0){
                                                    if(r3 == 0){
                                                        if(r4 == 0){
                                                            if(r5 == 0){
                                                                if(r6 == 0){
                                                                    if(r7 == 0){
                                                                        if(r8 == 0){
                                                                            if(r9 == 0){
                                                                                if(r10 == 0){
                                                                                    ans[0]++;
                                                                                }
                                                                                else{
                                                                                    ans[r10]++;
                                                                                }
                                                                            }
                                                                            else{
                                                                                ans[r9]++;
                                                                                ans[r10]++;
                                                                            }
                                                                        }
                                                                        else{
                                                                            ans[r8]++;
                                                                            ans[r9]++;
                                                                            ans[r10]++;
                                                                        }
                                                                    }
                                                                    else{
                                                                        ans[r7]++;
                                                                        ans[r8]++;
                                                                        ans[r9]++;
                                                                        ans[r10]++;
                                                                    }
                                                                }
                                                                else{
                                                                    ans[r6]++;
                                                                    ans[r7]++;
                                                                    ans[r8]++;
                                                                    ans[r9]++;
                                                                    ans[r10]++;
                                                                }
                                                            }
                                                            else{
                                                                ans[r5]++;
                                                                ans[r6]++;
                                                                ans[r7]++;
                                                                ans[r8]++;
                                                                ans[r9]++;
                                                                ans[r10]++;
                                                            }
                                                        }
                                                        else{
                                                            ans[r4]++;
                                                            ans[r5]++;
                                                            ans[r6]++;
                                                            ans[r7]++;
                                                            ans[r8]++;
                                                            ans[r9]++;
                                                            ans[r10]++;
                                                        }
                                                    }
                                                    else{
                                                        ans[r3]++;
                                                        ans[r4]++;
                                                        ans[r5]++;
                                                        ans[r6]++;
                                                        ans[r7]++;
                                                        ans[r8]++;
                                                        ans[r9]++;
                                                        ans[r10]++;
                                                    }
                                                }
                                                else{
                                                    ans[r2]++;
                                                    ans[r3]++;
                                                    ans[r4]++;
                                                    ans[r5]++;
                                                    ans[r6]++;
                                                    ans[r7]++;
                                                    ans[r8]++;
                                                    ans[r9]++;
                                                    ans[r10]++;
                                                }
                                            }
                                            else{
                                                ans[r1]++;
                                                ans[r2]++;
                                                ans[r3]++;
                                                ans[r4]++;
                                                ans[r5]++;
                                                ans[r6]++;
                                                ans[r7]++;
                                                ans[r8]++;
                                                ans[r9]++;
                                                ans[r10]++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("%d %d %d %d %d %d %d %d %d %d",ans[0],ans[1],ans[2],ans[3],ans[4],ans[5],ans[6],ans[7],ans[8],ans[9]);
}