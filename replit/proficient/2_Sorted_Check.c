/*
ให้นักศึกษาเขียนโปรแกรมรับจำนวนเต็ม 5 จำนวน เก็บใน array แล้วตรวจว่าลำดับตัวเลขที่รับมามีการเรียงจากน้อยไปมากหรือไม่

input : 2 4 5 6 7 output : Ascending order

input : 2 8 5 3 7 output : Not ascending order
*/
#include <stdio.h>

int main(void) {
  int num[5];
  int input,i;
  int true = 1;
  for (i = 0 ; i < 5 ; i++){
    scanf("%d", &num[i]);
  }
  for (i = 0 ; i < 4 ; i++){
    if ( num[i] > num[i+1]){
      printf("Not ascending order");
      true = 0;
      break;
    }
  }
  if(true == 1){
    printf("Ascending order");
  }
  
  return 0;
}