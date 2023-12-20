/*
ให้นักศึกษาเขียนโปรแกรมรับ input เป็น string จำนวน 2 ชุด (long_string, sub_string) แล้วทำการค้นหาว่ามี sub_string อยู่ที่ตำแหน่ง (index) ใดใน long_string ถ้าไม่พบ ให้แสดงตำแหน่งเป็น -1

Test Case 1: String: "Hello World" Substring: "Hello" Expected Output: Substring found at index 0

Test Case 2: String: "OpenAI is amazing" Substring: "is" Expected Output: Substring found at index 7
*/
#include <stdio.h>

int main(void) {
    int i = 0, j = 0, count = -1 , k = 0;
    char long_string[100], sub_string[100];
    

    scanf("%99[^\n]", long_string); 
    getchar(); 

 
    scanf("%99[^\n]", sub_string);
    getchar(); 

    while (long_string[i] != '\0') {
        k = i;
        j = 0;
        while (long_string[k] == sub_string[j] && sub_string[j] != '\0') {
            k++;
            j++;
        }
        if (sub_string[j] == '\0') {
            count = i;
            break;
        }
        i++;
    }

    printf("%d\n", count);

    return 0;
}