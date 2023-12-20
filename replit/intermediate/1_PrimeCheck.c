/*
ให้นักศึกษาเขียนโปรแกรมรับ Input เป็นตัวเลข 1 ตัวแล้วตรวจสอบว่าตัวเลขที่ได้รับมาเป็นตัวเลขจำนวนเฉพาะหรือไม่

ตัวอย่าง input : 13 output : Prime number

input : 56 output : Not prime number
*/
#include <stdio.h>

int main(void) {
  int a;
  int prime = 1;
  scanf("%d", &a);
  for (int i = 2; i < a; i++) {
    if (a % i == 0){
      prime = 0;
    }
  }
  if (prime == 1){
    printf("Prime number");
  }else{
    printf("Not prime number");
  }
    
  return 0;
}