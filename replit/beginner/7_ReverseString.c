/*
ให้นักศึกษาเขียนโปรแกรมรับ input string แล้วแสดงผลเป็น reverse string

ตัวอย่าง Input : ABCDEFGH Output : HGFEDCBA
*/
#include <stdio.h>
#include<string.h>

int main(void) {
  char input[20];
  scanf("%[^\n]", &input);
  for(int i = strlen(input); i >= 0; i = i-1){
    printf("%c", input[i]);
  }
  
  return 0;
}