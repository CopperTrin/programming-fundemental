#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy(int x, int y) {
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setcursor(bool visible) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}

void setcolor(int fg, int bg) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void erase_ship(int x, int y) {
    gotoxy(x, y); printf("       ");
    setcolor(2, 4);
}

void draw_ship(int x, int y) {
    gotoxy(x, y); printf(" <-0-> ");
    setcolor(2, 0);
}

void erase_bullet(int x, int y) {
    gotoxy(x, y); printf("     ");
}

void draw_bullet(int x, int y) {
    gotoxy(x, y); printf("  |   ");
}

int main() {
    setcursor(0);
    setcolor(2, 4);
    char ch = '.';
    int x = 38, y = 20;
    int bulletX[5], bulletY[5];
    int bulletCount = 0;
    int left = 0;
    int right = 0;
    int fire = 0;

    draw_ship(x, y);

    do {
        if (_kbhit()) {
            ch = _getch();
            if (ch == 'a') { left = 1, right = 0; }
            if (ch == 'd') { left = 0, right = 1; }
            if (ch == 's') { left = 0, right = 0; }
            if (ch == ' ') {
                if (bulletCount < 5) {
                    bulletX[bulletCount] = x;
                    bulletY[bulletCount] = y - 1;
                    bulletCount++;
                    fire = 1;
                }
                fflush(stdin);
            }
        }

        if (left == 1 || right == 1 || fire == 1)
        {
            if (left == 1 && x > 0) { erase_ship(x, y); draw_ship(--x, y); }
            if (right == 1 && x < 73) { erase_ship(x, y); draw_ship(++x, y); }
        }
        for (int i = 0; i < bulletCount; i++)
        {
            erase_bullet(bulletX[i], bulletY[i]);
            if (bulletY[i] > 0) {
                draw_bullet(bulletX[i], --bulletY[i]);
            }
            else
            {
                for (int j = i; j < bulletCount - 1; j++)
                {
                    bulletX[j] = bulletX[j + 1];
                    bulletY[j] = bulletY[j + 1];
                }
                bulletCount--;
            }
        }
        Sleep(100);
    } while (ch != 'x');

    return 0;
}