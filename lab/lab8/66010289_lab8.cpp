#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h> // เพิ่มไลบรารีนี้เพื่อใช้ฟังก์ชันสุ่ม
#define scount 80
#define screen_x 80
#define screen_y 25
HANDLE rHnd;
HANDLE wHnd;
CHAR_INFO consoleBuffer[screen_x * screen_y];
DWORD fdwMode;
COORD bufferSize = { screen_x,screen_y };
COORD characterPos = { 0,0 };
SMALL_RECT windowSize = { 0,0,screen_x - 1,screen_y - 1 };
COORD star[scount];
COORD shipPos = { 0, 0 }; 
WORD shipColor = 7; 
int starHitCount = 0;

void setConsoleSize(int width, int height) {
    wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
    SetConsoleScreenBufferSize(wHnd, bufferSize);
}

void clear_buffer() {
    for (int y = 0; y < screen_y; ++y) {
        for (int x = 0; x < screen_x; ++x) {
            consoleBuffer[x + screen_x * y].Char.AsciiChar = ' ';
            consoleBuffer[x + screen_x * y].Attributes = 7;
        }
    }
}

void fill_buffer_to_console() {
    WriteConsoleOutputA(wHnd, consoleBuffer, bufferSize, characterPos, &windowSize);
}

void init_star() {
    for (int i = 0; i < scount; i++) {
        star[i] = { (rand() % screen_x), (rand() % screen_y) };
    }
}

void star_fall() {
    int i;
    for (i = 0; i < scount; i++) {
        if (star[i].Y >= screen_y - 1) {
            star[i] = { (rand() % screen_x), 1 };
        }
        else {
            star[i] = { star[i].X, star[i].Y + 1 };
        }
    }
}

void fill_star_to_buffer() {
    for (int i = 0; i < scount; i++) {
        consoleBuffer[star[i].X + screen_x * star[i].Y].Char.AsciiChar = '*';
        consoleBuffer[star[i].X + screen_x * star[i].Y].Attributes = 7;
    }
}

void fill_ship_to_buffer() {
    
    consoleBuffer[shipPos.X + screen_x * shipPos.Y].Char.AsciiChar = 'A';
    consoleBuffer[shipPos.X + screen_x * shipPos.Y].Attributes = shipColor;
}

int setMode() {
    rHnd = GetStdHandle(STD_INPUT_HANDLE);
    fdwMode = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT |
        ENABLE_MOUSE_INPUT;
    SetConsoleMode(rHnd, fdwMode);
    return 0;
}

int main() {
    bool play = true;
    DWORD numEvents = 0;
    DWORD numEventsRead = 0;
    setConsoleSize(screen_x, screen_y);
    setMode();
    init_star();

    while (play) {
        GetNumberOfConsoleInputEvents(rHnd, &numEvents);
        if (numEvents != 0) {
            INPUT_RECORD* eventBuffer = new INPUT_RECORD[numEvents];
            ReadConsoleInput(rHnd, eventBuffer, numEvents, &numEventsRead);
            for (DWORD i = 0; i < numEventsRead; ++i) {
                if (eventBuffer[i].EventType == KEY_EVENT &&
                    eventBuffer[i].Event.KeyEvent.bKeyDown == true) {
                    if (eventBuffer[i].Event.KeyEvent.wVirtualKeyCode == VK_ESCAPE) {
                        play = false;
                    }
                    else if (eventBuffer[i].Event.KeyEvent.uChar.AsciiChar == 'c') {
                        
                        shipColor = rand() % 255;
                    }
                }
                else if (eventBuffer[i].EventType == MOUSE_EVENT) {
                    int posx = eventBuffer[i].Event.MouseEvent.dwMousePosition.X;
                    int posy = eventBuffer[i].Event.MouseEvent.dwMousePosition.Y;
                    if (eventBuffer[i].Event.MouseEvent.dwButtonState &
                        FROM_LEFT_1ST_BUTTON_PRESSED) {
                    }
                    else if (eventBuffer[i].Event.MouseEvent.dwButtonState &
                        RIGHTMOST_BUTTON_PRESSED) {
                    }
                    else if (eventBuffer[i].Event.MouseEvent.dwEventFlags & MOUSE_MOVED) {
                        shipPos.X = posx;
                        shipPos.Y = posy;
                    }
                }
            }
            delete[] eventBuffer;
        }




        star_fall();
        clear_buffer();
        fill_star_to_buffer();
        fill_ship_to_buffer(); 
        fill_buffer_to_console();

        
        for (int i = 0; i < scount; i++) {
            if (star[i].X == shipPos.X && star[i].Y == shipPos.Y) {
                starHitCount++;
                star[i] = { (rand() % screen_x), 1 };
            }
        }

        if (starHitCount >= 10) {
            play = false;
        }

        Sleep(100);
    }
    return 0;
}