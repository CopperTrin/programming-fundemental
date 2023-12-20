#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    //Get Input
    char text[100];
    scanf("%s", text);
    char text_num[100];
    int index_text_num= 0;

    //Process
    //ลูปตามความยาว text
    for (int i = 0; i < strlen(text); i++) 
    {   
        //ถ้าเป็นตัวเลข 0 > 9 ให้เพิ่มเข้าไปใน text_num
        if (text[i] >= '0' && text[i] <= '9') 
        {
            text_num[index_text_num] = text[i]; //#1
            //printf("%s %d \n",text_num ,index_text_num);
            index_text_num += 1;
        }
        //ถ้าเป็นตัวอักษรแล้วมีแล้วมี text_num ให้แปลง text_num เป็น int และ printf ออกมาจำนวนตาม text_num
        else if (index_text_num > 0)
        {
            text_num[index_text_num] = '\0'; //ปิดว่า text_num สมบูรณ์แล้ว
            int num = atoi(text_num)+1;  //#2
            printf("%d\n", num);
            for (int j = 0 ; j < num;j++)
             {
                //printf("%c", text[i]);
             }
             index_text_num = 1; //#3
        }
         //ถ้าเป็นตัวอักษร ไม่มี text_num ให้ printf ได้เลย
        else //#4
        {
            //printf("%c", text[i]);
        }
    }
    return 0;
}