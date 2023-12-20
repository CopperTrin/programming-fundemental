/*
ให้นักศึกษาเขียนโปรแกรมรับ input เป็นตัวเลข 3 ตัวแล้วแสดงผลค่าเฉลี่ยของตัวเลขทั้งสามตัว

ตัวอย่าง input : 1 2 3 output : 2

input : 10 15 38 output : 21
*/
#include <stdio.h>

int main(void) {
  int a,b,c,d;
  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&c);
  d = (a+b+c) / 3;
  printf("%d", d);
  return 0;
}