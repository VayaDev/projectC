#include <windows.h>
#include "HeaderGreat.h"

static HFONT hDlgFont,hDlgF;

BOOL CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	(void)lParam;
    switch (uMsg) {
    case WM_INITDIALOG:
	hDlgFont = CreateFont(
            16, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE, "Arial");  
	hDlgF = CreateFont(
            32, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE, "Impact");  	
		SendDlgItemMessage(hwndDlg, 16, WM_SETFONT, (WPARAM)hDlgF, TRUE);
        SendDlgItemMessage(hwndDlg, 17, WM_SETFONT, (WPARAM)hDlgFont, TRUE);
        SendDlgItemMessage(hwndDlg, 18, WM_SETFONT, (WPARAM)hDlgFont, TRUE);
        SendDlgItemMessage(hwndDlg, 19, WM_SETFONT, (WPARAM)hDlgFont, TRUE);
        return TRUE;	
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
            EndDialog(hwndDlg, LOWORD(wParam));
            return TRUE;
        }
        break;
    case WM_CLOSE:
        EndDialog(hwndDlg, IDCANCEL);
        return TRUE;
    }
    return FALSE;
}