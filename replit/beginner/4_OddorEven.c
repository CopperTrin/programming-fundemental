/*
ให้นักศึกษาเขียนโปรแกรมรับ input เป็นตัวเลข 1 ตัวแล้วแสดงผลว่าตัวเลขดังกล่าวเป็นเลขคู่ (Even) หรือเลขคี่ (Odd)
*/
#include <stdio.h>

int main(void) {
  int a;
  scanf("%d", &a);
  if (a % 2 == 0)
  {
    printf("Even");
  }else{
    printf("Odd");
  }
  return 0;
}