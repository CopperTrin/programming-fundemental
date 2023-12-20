/*
จงเขียนโปรแกรมเพื่อรับ input เป็นตัวเลข 10 ตัว แล้วแสดงผลว่า ตัวแลขที่ป้อนมีตัวเลขอะไรบ้าง และแต่ละเลขมีจำนวนกี่ตัว

Test Case 1: input : 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 Expected Output: Element 1: Frequency = 2 Element 2: Frequency = 2 Element 3: Frequency = 2 Element 4: Frequency = 2 Element 5: Frequency = 2

Test Case 2: input : 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 Expected Output: Element 1: Frequency = 10
*/
#include <stdio.h>

int main() {
    int numbers[10], result[100] = {0}; 


    for (int i = 0; i < 10; i++) {
        scanf("%d,", &numbers[i]);
        result[numbers[i]]++;
    }

    for (int j = 0; j < 100; j++) {
        if (result[j] > 0) {
            printf("Element %d: Frequency = %d\n", j, result[j]);
        }
    }

    return 0;
}