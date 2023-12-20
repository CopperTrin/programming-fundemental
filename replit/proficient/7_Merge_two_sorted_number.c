/*
  เขียนโปรแกรมรับ input เป็นชุดตัวเลขเรียงลำดับจากน้อยไปมา 2 ชุด แล้วแสดงผลเป็นชุดตัวเลขที่เรียงลำดับจากน้อยไปมาก ของตัวเลขภายใน input ทั้งสองชุด

input : 
3 8 14 23 56
1 2 9 18 22 89
output : 
1 2 3 8 9 14 18 22 23 56 89 
  */

#include <stdio.h>

int main(void) {
 int a[10] = {0}, b[10] = {0},index_a=0,index_b=0;
  char enter;

  while((enter = getchar()) != '\n')
    {
      ungetc(enter, stdin);
      scanf("%d",&a[index_a]);
      index_a++;
    }

  while((enter = getchar()) != '\n')
    {
      ungetc(enter, stdin);
      scanf("%d",&b[index_b]);
      index_b++;
    }


  for(int i = 0; i <= 100;i++)
    {
      for(int j = 0; j < 10;j++)
        {
          if(a[j] == i) printf("%d ", a[j]);
          if(b[j] == i) printf("%d ", b[j]);
        }
    }
  
 return 0;
}