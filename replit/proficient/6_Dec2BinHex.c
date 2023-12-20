/*
เขียนโปรแกรมรับ input เป็นตัวเลข 1 ตัวแล้วแสดงผลค่าตัวเลขฐานสอง และฐานสิบหกของตัวเลขนั้น

Input : 120 Output : 1111000 78

Input : 534 Output: 1000010110 216
*/

#include <stdio.h>
#include <string.h>

void binary(int num, int array[]) {
    int i = 0;
    while (num != 0) {
        array[i] = (num % 2);
        num = num / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", array[j]);
    }
}

void hexadecimal(int num, int array[]) {
    int i = 0;
    while (num != 0) {
        array[i] = (num % 16);
        num = num / 16;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        if (array[j] <= 9) {
            printf("%d", array[j]);
        } else if (array[j] >= 10 && array[j] <= 15) {
            printf("%c", 'A' + (array[j] - 10));
        }
    }
}

int main(void) {
    int num;
    int array[10];
    scanf("%d", &num);
    binary(num, array);
    printf("\n");
    hexadecimal(num, array);

    return 0;
}
