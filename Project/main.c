#include <windows.h>
#include "HeaderGreat.h"
#include "headerDialog.h"
#include "headerMainWin.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hpi, LPSTR cmdline, int ss) {
	(void)hpi;
	(void)cmdline;
    WNDCLASS wc; 
    wc.style = 0;
    wc.lpfnWndProc = MainWinProc;
    wc.cbClsExtra = wc.cbWndExtra = 0;
    wc.hInstance = hInst;
    wc.hIcon = LoadIcon(hInst, "Ex4_Icon");
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = CreateSolidBrush(RGB(170, 30, 100));
    wc.lpszMenuName = "Ex4_Menu";
    wc.lpszClassName = "Example MainWnd Class";
    if (!RegisterClass(&wc)) 
        return FALSE;
    HWND hMainWnd = CreateWindow(
        "Example MainWnd Class",
        "DROP TAKE HOLD",
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, 800, 700,
        NULL, NULL, hInst, NULL);
    if (!hMainWnd)
        return FALSE;

    ShowWindow(hMainWnd, ss); 
    UpdateWindow(hMainWnd);
	
    MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) { 
		if (!IsDialogMessage(hMainWnd, &msg)) {
        TranslateMessage(&msg); 
        DispatchMessage(&msg);
		}
	}
    return msg.wParam;
}