/*
ให้นักศึกษาเขียนโปรแกรมรับ Input เป็นหมายเลขบัตรประจำตัวประชาชน 13 หลัก แล้วโปรแกรมแสดงผลการตรวจสอบว่าเป็นหมายเลขบัตรประชาชน 13 หลักที่มีรูปแบบถูกต้องหรือไม่

ตัวอย่าง input : 1234567890121 output : PersonalID

input : 9876543210981 output : Not PersonalID
*/
#include <stdio.h>

int main(void) {
 char personal_id[13];
  int check = 1,personal_id_value[13], x = 0, y = 13;
  
  scanf("%s", personal_id);
      if(personal_id[0] < '1' && personal_id[0] > '8' )
      {
        check = 0;
      }
  for (int i = 0 ; i < 13 ; i++)
    {
      personal_id_value[i] = personal_id[i] - 48;
    }


    for (int i = 0; i < 12 ; i++)
      {
        x += personal_id_value[i] * y;
        y--;
      }

    if(personal_id_value[12] != (11 - (x%11)) % 10) check = 0;
      
      
  if(check) printf("PersonalID");
  else printf("Not PersonalID");
  return 0;
}
