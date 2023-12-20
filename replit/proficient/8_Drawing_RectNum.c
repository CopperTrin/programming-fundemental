/*
เขียนโปรแกรมรับ input เป็นตัวเลข 2 ตัว ตัวแรก (m) คือตัวเลขสำหรับคำนวณความยาวด้านของรูปสี่เหลี่ยมจตุรัส โดยขนาดของรูปสี่เหลี่ยมจะมีด้านยาว =2m+1 ส่วนตัวที่สอง (n) คือตัวเลขที่อยู่ตรงกลาง โดยถ้า m=3,n=0 จะได้สี่เหลี่ยมที่มีความกว้าง = 7 และมีตัวเลขที่อยู่ตรงกลางคือ 0 ดังนี้

input : m=3 n=0 output : 
3333333 
3222223 
3211123 
3210123 
3211123 
3222223 
3333333

input : m = 2 n = 1 output : 
33333 
32223 
32123 
32223 
33333
*/

#include <stdio.h>

int main () {
    int m, n;

    scanf ("%d", &m);
    scanf ("%d", &n);

    int max = 2 * m + 1;
    int mid = ((max + 1) / 2) - 1;

    for(int row = 0; row < max; row++) {
        for(int col = 0; col < max; col++) {
            for(int i = 0; i <= m; i++) {
                if (row == mid + (m - i) || col == mid + (m - i) || row == mid - (m - i) || col == mid - (m - i)) {
                    if (m + n - i >= 10) {
                        printf("0");
                    } else {
                        printf("%d", n + m - i);
                    }
                    break;
                }
            }
        }
        printf("\n");
    }
}