/*
  เขียนโปรแกรมรับ input เป็น string 1 ตัวที่ประกอบด้วยคำหลายๆ คำ คั่นด้วยช่องว่าง แล้วแสดงผลลัพธ์เป็น string ที่มีการสลับลำดับคำจากหลังมาหน้า

input : abc def ghi jkl
outupt : jkl ghi def abc
*/

#include <stdio.h>

int main(void) {
 char input[100],output[10][10]={'\0'};
  int index_input=0,output_x=0,output_y=0,count=0,start=0;

  fgets(input, sizeof(input), stdin);
  for(int i = 0;i < sizeof(input);i++)
    {
     if(input[i] != ' ' && input[i] != '\n')
      {
        output[output_x][output_y] = input[i];
        output_y += 1;
      }
      else if(input[i] == ' ')
      {
        output_x++;
        output_y = 0;
      }
    }
  
    for (int i = output_x ; i >= 0 ; i--) 
    {
      printf ("%s ",output[i]);
    }
  
  return 0;
}