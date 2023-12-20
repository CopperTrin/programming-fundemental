/*
จงเขียนโปรแกรมรับ input เป็นตัวเลข 10 ตัว แล้วทำการสร้างฟังก์ชั่น bubble_sort() ในการเรียงลำดับตัวเลขจากน้อย ไปมาก โดยใช้ bubble sort algorithm

Test Case 1: Input Numbers: 5, 2, 9, 1, 7, 4, 6, 3, 8, 10 Expected Output: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

Test Case 2: Input Numbers: 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 Expected Output: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
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
    int num[10];
    int i;
    
    for (i = 0; i < 10; i++) {
        scanf("%d, ", &num[i]);
    }
    
    bubbleSort(num, 10);
    
    for (i = 0; i < 10; i++) {
      if(i == 9){
        printf("%d", num[i]);
      }else{
        printf("%d, ", num[i]);
      }
    }
    
    return 0;
}