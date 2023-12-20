/*
เขียนโปรแกรม รับ input เป็น string 2 ชุด (text,keyword) แล้วให้แสดงผลตำแหน่งของ keyword ใน text โดยใช้ Boyer-Moore Algorithm ในกรณีที่พบ keyword ใน text ให้แสดงผลตำแหน่งของ keyword ใน text ในกรณีที่ไม่พบ ให้แสดงผล "keyword not found." ในกรณีที่พบ keyword ใน text มากกว่า 1 ตัวให้แสดงผลตำแหน่งทุกตัว

ตัวอย่าง input 1 : This is a long string containing the word 'example'. input 2 : example output : 32

input 1 : This is a long string without the keyword. input 2 : missing output : keyword not found.

input 1 : This is an example of a sentence with multiple example occurrences. input 2 : example output : 10 39
*/
#include <stdio.h>
#include <string.h>

#define MAX 256

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char text[1000];
    char keyword[100];

   
    gets(text);

    
    gets(keyword);

    int m = strlen(keyword);
    int n = strlen(text);

    int badchar[MAX];

    for (int i = 0; i < MAX; i++) {
        badchar[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        badchar[(int)keyword[i]] = i;
    }

    int s = 0;
    int found = 0;

    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && keyword[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            printf("%d ", s);
            s += (s + m < n) ? m - badchar[text[s + m]] : 1;
            found = 1;
        } else {
            s += max(1, j - badchar[text[s + j]]);
        }
    }

    if (found == 0) {
        printf("Keyword not found.");
    }
    printf("\n");

    return 0;
}
