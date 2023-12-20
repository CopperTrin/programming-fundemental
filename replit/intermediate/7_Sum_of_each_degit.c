/*
จงเขียนโปรแกรมรับ Input เป็นตัวเลข 1 ตัวแล้วแสดงผล ผลรวมเลขโดดแต่ละหลัก

Test Case 1: Input Number: 12345 Expected Output: Sum = 15

Test Case 2: Input Number: 987654321 Expected Output: Sum = 45
*/
#include <stdio.h>

int main() {
    int num;
    int sum = 0;

    scanf("%d", &num);

    while (num > 0) {
        int digit = num % 10;
        sum += digit; 
        num /= 10; 
    }

    printf("%d", sum);

    return 0;
}