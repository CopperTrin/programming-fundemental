/*
ให้นักศึกษาเขียนโปรแกรมรับ Input เป็นตัวเลขฐาน 10 แล้วแสดงผลเป็นเลขฐาน 2

ตัวอย่าง input : 22 output : 10110

input : 10 output : 1010
*/
#include <stdio.h>
#include<string.h>

int main(void) {
  int num;
  int array[10];
  int i = 0; 
  scanf("%d", &num);
  while (num != 0){
    array[i] = (num % 2);
    num = num/2;
    i++;
    
  }
  for (int j = i-1; j >= 0; j--){
    printf("%d", array[j]);
  }
  
  return 0;
}