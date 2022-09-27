#include <iostream>
#include <windows.h>

using namespace std;

void wait(int time);
void leave();
void pressKey(BYTE key);
void LogTime();

int main()
{
    cout << "Jem3i has started the work!!!" << endl;
    cout << "Work started at: ";
    LogTime();
    while(true) {
        leave();
        POINT cursorPos;
        GetCursorPos(&cursorPos);
        leave();
        SetCursorPos(cursorPos.x+1, cursorPos.y+1);
        leave();
        Sleep(10);
        leave();
        SetCursorPos(cursorPos.x-1, cursorPos.y-1);
        leave();
        Sleep(10);
        leave();
        SetCursorPos(cursorPos.x, cursorPos.y);
        pressKey(VK_CONTROL);
        leave();
        cout << "Jem3i worked a little bit @ ";
        LogTime();
        cout << "\nYou can quit Jem3i by pressing ESC key" << endl;
        leave();
        wait(30); // wait 30 seconds
        leave();
    }
    return 0;
}

void wait(int time) {
    for(int i=0; i<time*10; i++) {
        Sleep(100);
        leave();
    }
}


void leave() {
    if(GetAsyncKeyState(VK_ESCAPE) & 0x01) {
        cout << "Thank you for using Jem3i.... Bye Bye." << endl;
        ExitProcess(0);
    }
}

void pressKey(BYTE key) {
    // Simulate a key press
     keybd_event( key,
                  0x45,
                  KEYEVENTF_EXTENDEDKEY | 0,
                  0 );

    // Simulate a key release
     keybd_event( key,
                  0x45,
                  KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP,
                  0);
}

void LogTime() {
    SYSTEMTIME lt;
    GetLocalTime(&lt);
    string hh = to_string(lt.wHour);
    string mm = to_string(lt.wMinute);
    string ss = to_string(lt.wSecond);
    if(lt.wHour<10) hh = "0" + hh;
    if(lt.wMinute<10) mm = "0" + mm;
    if(lt.wSecond<10) ss = "0" + ss;
    cout << hh << ":" << mm << ":" << ss;
}
