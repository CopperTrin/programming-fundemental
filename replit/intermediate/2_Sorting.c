/*
ให้นักศึกษาเขียนโปรแกรมรับ Input เป็นตัวเลข 5 ตัวเก็บไว้ใน Array แล้วแสดงผลตัวเลขแบบเรียงลำดับจากน้อยไปหามาก

input : 6 9 4 3 8 output : 3 4 6 8 9
*/
#include <stdio.h>

int main(void) {
 int num[5];
 int i, j, temp;
  for (int i = 0; i < 5; i++) {
      scanf("%d", &num[i]);
  }

  
  for (i = 0; i < 5; i++){
    for (j = 0; j < 5-i-1; j++){
      if (num[j] > num[j+1]){
        temp = num[j];
        num[j] = num[j+1];
        num[j+1] = temp;
      }
    }
  }   
  for (i = 0; i < 5; i++) {
        printf("%d ", num[i]);
    }

}