/*
ให้นักศึกษาเขียนโปรแกรม

1.รับ input เป็นตัวเลขจำนวน 5 ตัว
2.สร้างฟังก์ชั่น min() ที่ return ค่าต่ำสุด
3.สร้างฟังก์ชั่น max() ที่ return ค่าสูงสุด
4.แสดงผลลัพธ์ค่าต่ำสุด และสูงสุดของ input โดยใช้ฟังก์ชั่น min() , max()

input : 4 6 5 9 8 output : 4 9

input : 34 56 23 65 12 output : 12 65
*/
#include <stdio.h>
int min(int num[]) {
    int min = num[0];
    for (int i = 1; i < 5; i++) {
        if (num[i] < min) {
            min = num[i];
        }
    }
    return min;
}

int max(int num[]) {
    int max = num[0];
    for (int i = 1; i < 5; i++) {
        if (num[i] > max) {
            max = num[i];
        }
    }
    return max;
}

int main(void) {
  int num[5];
  for (int i = 0; i < 5; i++) {
      scanf("%d", &num[i]);
  }
  
  printf("%d %d",min(num) ,max(num));
  
  return 0;
}