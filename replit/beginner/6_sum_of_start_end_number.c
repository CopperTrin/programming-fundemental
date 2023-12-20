/*
ให้นักศึกษาเขียนโปรแกรมโดยรับ input เป็นตัวเลข 2 ตัวแล้วแสดงผลรวมของตัวเลขตั้งแต่ตัวแรกจนถึงตัวสุดท้าย

ตัวอย่าง input : 1 5 output : 15
*/
#include <stdio.h>

int main(void) {
  int a,b,sum = 0;
  scanf("%d",&a);
  scanf("%d",&b);
  for(int i = a; i <= b; i++){
    sum += i;
  }
  printf("%d\n",sum);
  return 0;
}