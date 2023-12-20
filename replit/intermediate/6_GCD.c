/*
จงเขียนโปรแกรมรับ input เป็นตัวเลข 2 ตัวแล้วแสดงผลค่า ห.ร.ม ของตัวเลขทั้งสอง

Test Case 1: input : Number 1: 12 Number 2: 18 Expected Output: GCD = 6

Test Case 2: input : Number 1: 25 Number 2: 5 Expected Output: GCD = 5
*/
#include <stdio.h>

int main(void) {
  int least,most,a,b,GCD = 0;
  scanf("%d", &a);
  scanf("%d", &b);
  
  if (a>b){
    most = a;
    least =b;
  }else{
    most = b;
    least = a;
  }
  int i = 1;
  while(i <= least){
    if(least % i == 0 && most % i == 0){
      GCD = i;
    }
    i += 1;
  }

  printf("%d", GCD);
  return 0;
}