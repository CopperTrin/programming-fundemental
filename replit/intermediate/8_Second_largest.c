/*
เขียนโปรแกรมรับ input เป็นตัวเลข 8 ตัวแล้วแสดงผลตัวเลขที่มีค่ามากที่สุดเป็นอันดับ 2

Test Case 1: input : 10, 5, 8, 3, 12, 7, 15, 9 Expected Output: Second Largest Element = 12

Test Case 2: input : 6, 3, 9, 1, 4, 5, 7, 2 Expected Output: Second Largest Element = 7
*/
#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int num[8];
    int i;
    
    for (i = 0; i < 8; i++) {
        scanf("%d, ", &num[i]);
    }
    
    bubbleSort(num, 8);
    
    printf("Second Largest Element = %d", num[6]);
    
    return 0;
}