/*
จงเขียนโปรแกรมรับ input เป็นตัวเลขจำนวนเต็ม 1 ตัวแล้วแสดงผลเป็นการแยกตัวประกอบ

input : 100 output : 2 x 2 x 5 x 5

input : 68 output : 2 x 2 x 17
*/
#include <stdio.h>

int main() {
    int n,first=0;
    scanf("%d", &n);
    int i = 2;

    while (n > 1) {
        if (n % i == 0) {
            if (first == 0){
               printf("%d ", i);
               n /= i; 
               first = 1;
            }else{
                printf("x %d ", i);
               n /= i; 
            }
        } else {
            i++;
        }
    }

    return 0;
}