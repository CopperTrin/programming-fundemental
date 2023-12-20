/*
Palindrome คือ string ที่สามารถอ่านจากหน้าไปหลัง หรือหลังไปหน้าแล้วได้ผลลัพธ์เหมือนกัน เช่น ATOYOTA , ABBA , TESTSET เป็นต้น

ให้นักศึกษาเขียนโปรแกรมรับ String 1 ตัวแล้วแสดงผลว่าเป็น Palindrome หรือไม่ เช่น input : ABBA output : Palindrome

input : ABC output : Not Palindrome
*/
#include <stdio.h>
#include <string.h>

int palindrome(char str[20]) {
    int i;
    int len = strlen(str);
    int check_palindrome = 1;

    for (i = 0; i <= len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            check_palindrome = 0;
            break;
        }
    }

    if (check_palindrome == 1) {
        printf("Palindrome");
    } else {
        printf("Not Palindrome");
    }
}

int main() {
    char input_str[20];
    scanf("%s", input_str);

    palindrome(input_str);
    return 0;
}