#include<stdio.h>
#include<windows.h>
#include<time.h>
#include<conio.h>
void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void draw_ship(int x, int y)
{
	gotoxy(x, y); printf(" <-0-> ");
}
void draw_bullet(int x, int y)
{
	gotoxy(x, y); printf("^");
}
void clear_bullet(int x, int y)
{
	gotoxy(x, y); printf(" ");
}
void draw_star(int x, int y)
{
	gotoxy(x, y); printf("*");
}
void clear_star(int x, int y)
{
	gotoxy(x, y); printf(" ");
}
char cursor(int x, int y) 
{
	HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
	char buf[2]; COORD c = { x,y }; DWORD num_read;
	if (
		!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))

		return '\0';
	else
		return buf[0];

}
void update_point(int x, int y,int point)
{
	gotoxy(x, y); printf("point : %d ", point);
}
int main()
{
	srand(time(NULL));
	char ch = '.';
	int x = 38, y = 20;
	int bx, by, i;
	int bullet = 0;
	int hit_star = 0;
	int point = 0;
	draw_ship(x, y);
	for (int i = 0; i < 20; i++)
	{
		draw_star(rand() % 61 + 10, rand() % 4 + 2);
	}
	do {
		update_point(0, 0, point);
		if (_kbhit()) {
			ch = _getch();
			if (ch == 'a') { draw_ship(--x, y); }
			if (ch == 's') { draw_ship(++x, y); }
			if (bullet != 1 && ch == ' ') { bullet = 1; bx = x + 3; by = y - 1; Beep(700, 100); }
			fflush(stdin);
		}
		if (bullet == 1) {

			clear_bullet(bx, by);
			if (by == 2 || hit_star == 1) { bullet = 0; hit_star = 0;}
			else {
				if (cursor(bx, by - 1) == '*')
				{
					clear_star(bx, by - 1);
					clear_bullet(bx, by);
					Beep(700, 100);
					hit_star = 1;
					point += 1;
					draw_star(rand() % 61 + 10, rand() % 4 + 2);
				}
				else
				{
					draw_bullet(bx, --by);
				}
			}
				

		}
		Sleep(100);
	} while (ch != 'x');
	return 0;
}