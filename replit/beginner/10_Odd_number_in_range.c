/*
ให้นักศึกษาเขียนโปรแกรมรับ input เป็นตัวเลข 2 ตัวแล้วแสดงผลเลขคี่ระหว่างตัวเลขทั้ง 2 ตัว
*/
#include <stdio.h>

int main(void) {
  int a,b;
  scanf("%d",&a);
  scanf("%d",&b);
  for (int i = a; i <= b; i++)
  {
    if (i % 2 == 0){
      continue;
    }else{
      printf("%d\n", i);
    }
      
  }
  return 0;
}