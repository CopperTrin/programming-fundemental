/*
ให้นักศึกษาเขียนโปรแกรมรับ input เป็นตัวเลข 2 ตัวแล้วแสดงผลลัพธ์คือตัวเลขที่มีค่ามากกว่า
*/
#include <stdio.h>

int main(void) {
  int a,b;
  scanf("%d", &a);
  scanf("%d", &b);
  if (a > b){
    printf("%d",a);
  }else{
    printf("%d",b);
  }
  return 0;
}