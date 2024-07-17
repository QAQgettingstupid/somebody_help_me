#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
      
    HWND hwnd; // HWND->視窗類別
    hwnd = FindWindow(L"Notepad", L"AUA.txt - 記事本"); // "UnityWndClass"->類名 "崩壞：星穹鐵道"->窗口名稱

    if (hwnd) {
        cout << "找到窗口！\n";
        for (int i = 0; i < 20; i++) {
            SetForegroundWindow(hwnd);

            // 設置輸入結構
            INPUT input = { 0 };
            input.type = INPUT_KEYBOARD;
            input.ki.wVk = 0x57; // W 鍵的虛擬鍵碼

            SendInput(1, &input, sizeof(INPUT));
            input.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP 代表釋放鍵
            SendInput(1, &input, sizeof(INPUT));
    
        }
    }
    else
        cout << "未找到窗口！\n";

    return 0;
}

