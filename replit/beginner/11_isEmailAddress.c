/*
ให้นักศึกษาเขียนโปรแกรมรับ string 1 ชุดแล้วตรวจสอบว่าเป็น email address ที่ถูกต้องหรือไม่ ตัวอย่าง input : thanunchai.th@kmitl.ac.th output : email address

input : thanunchai.kmitl.ac.th output : not email address
*/
#include <stdio.h>
#include<string.h>

int main(void) {
  char input[50];
  int mail = 0;
  scanf("%s",&input);
  
  for (int i = 0; input[i] != '\0'; i++) {
    if (input[i] == '@') {
      mail = 1;
      break;
    }
  }
  
  if (mail == 1){
    printf("email address");
  }
  else
  {
    printf("not email address");
  }
  
  return 0;
}