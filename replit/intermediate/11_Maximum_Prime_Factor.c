/*
เขียนโปรแกรมรับ input เป็นตัวเลข 1 ตัวแล้วแสดงผล ตัวประกอบที่มีค่ามากที่สุด (maximum prime factor)

input : 21 output : 7

input : 1110 output : 37
*/
#include <stdio.h>

int main(void) {
  int num, most = 0;
  scanf("%d", &num);
  
  for (int i = 2; i < num; i++) {
    if (num % i == 0) {
      int isPrime = 1;
      for (int j = 2; j < i; j++) {
        if (i % j == 0) {
          isPrime = 0;
          break;
        }
      }
      if (isPrime == 1) {
        most = i;
      }
    }
  }
  
  printf("%d", most);
  return 0;
}