#include <windows.h>
#include "HeaderGreat.h"
#include "headerDialog.h"

static int dialogX = 0;
static int dialogY = 0;
static const int OFFSET = 20;
static HFONT hFont;

BOOL CALLBACK MsgDialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    (void)lParam;
    switch (uMsg) {
    case WM_INITDIALOG:
        ShowWindow(hwndDlg, SW_SHOW);
        return TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) {
            DestroyWindow(hwndDlg);
            return TRUE;
        }
        break;
    case WM_CLOSE:
        DestroyWindow(hwndDlg);
        return TRUE;
    }
    return FALSE;
}

void CreateOffsetDialog(HINSTANCE hInstance, LPCSTR lpTemplate, HWND hWndParent, DLGPROC lpDialogFunc) {
    RECT rect;
    GetWindowRect(hWndParent, &rect);  
    int baseX = rect.left + 10;       
    int baseY = rect.top + 50;         

    HWND hDlg = CreateDialog(hInstance, lpTemplate, hWndParent, lpDialogFunc);
    if (hDlg) {
        SetWindowPos(hDlg, NULL, baseX + dialogX, baseY + dialogY, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
        dialogX += OFFSET;  
        dialogY += OFFSET;  
        if (baseX + dialogX + 200 > rect.right) {  
            dialogX = 0; 
            dialogY += OFFSET;  
        }
        if (baseY + dialogY + 100 > rect.bottom) {  
            dialogX = 0;  
            dialogY = 0;
        }
    }
}

LRESULT CALLBACK MainWinProc(HWND hw, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
    case WM_CREATE:
        hFont = CreateFont(
            32, 50, -25, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
            OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
            DEFAULT_PITCH | FF_DONTCARE, "Impact");
        HWND hButton1 = CreateWindow("button", "TAKE", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE | SS_CENTER,
            250, 200, 300, 60, hw, (HMENU)ID_MYBUTTON, NULL, NULL); 
        HWND hButton2 = CreateWindow("button", "DROP", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE,
            250, 275, 300, 60, hw, (HMENU)ID_BUTTON2, NULL, NULL); 
        HWND hButton3 = CreateWindow("button", "HOLD", WS_CHILD | BS_PUSHBUTTON | WS_VISIBLE, 
            250, 350, 300, 60, hw, (HMENU)ID_BUTTON3, NULL, NULL); 
        SendMessage(hButton1, WM_SETFONT, (WPARAM)hFont, TRUE);
        SendMessage(hButton2, WM_SETFONT, (WPARAM)hFont, TRUE);
        SendMessage(hButton3, WM_SETFONT, (WPARAM)hFont, TRUE);
        return 0;
    case WM_SETCURSOR: {
        HWND hButton1 = GetDlgItem(hw, ID_MYBUTTON);
        HWND hButton2 = GetDlgItem(hw, ID_BUTTON2);
        HWND hButton3 = GetDlgItem(hw, ID_BUTTON3);
        if ((HWND)wp == hButton1 || (HWND)wp == hButton2 || (HWND)wp == hButton3) {
            SetCursor(LoadCursor(NULL, IDC_HAND));
            return TRUE;
        }
        return DefWindowProc(hw, msg, wp, lp);
    }
    case WM_COMMAND:
    if (HIWORD(wp) == 0) {
        char buf[256];
        switch (LOWORD(wp)) {
        case ID_MYBUTTON:
            CreateOffsetDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(101), hw, MsgDialogProc);
            break;
        case ID_BUTTON2:
            CreateOffsetDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(102), hw, MsgDialogProc);
            break;
        case ID_BUTTON3:
            CreateOffsetDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(103), hw, MsgDialogProc);
            break;
        case 4: 
            CreateOffsetDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(104), hw, MsgDialogProc);
            break;
        case 5:
            CreateOffsetDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(105), hw, MsgDialogProc);
            break;
        case 6: 
            CreateOffsetDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(106), hw, MsgDialogProc);
            break;
        case 7: 
            CreateOffsetDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(107), hw, MsgDialogProc);
            break;
        case 9:
            CreateOffsetDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(108), hw, MsgDialogProc);
            break;
        case 10: 
            CreateOffsetDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(109), hw, MsgDialogProc);
            break;
        case 11: 
            CreateOffsetDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(110), hw, MsgDialogProc);
            break;
        case 12:
            CreateOffsetDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(111), hw, MsgDialogProc);
            break;
        case 13: 
            CreateOffsetDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(112), hw, MsgDialogProc);
            break;
        case 14:
            CreateOffsetDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(113), hw, MsgDialogProc);
            break;
        case 8: 
            PostQuitMessage(0);
            break;
        case 15:
            if (DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_DIALOG1), hw, DialogProc) == -1) {
                wsprintf(buf, "Failed to open About dialog! Error code: %d", GetLastError());
                MessageBox(hw, buf, "Error", MB_OK | MB_ICONERROR);
            }
            break;
        default:
            wsprintf(buf, "Command code: %d", LOWORD(wp));
            CreateOffsetDialog(GetModuleHandle(NULL), MAKEINTRESOURCE(104), hw, MsgDialogProc);
        }
    }
    return 0;
    case WM_DESTROY:
	dialogX = 0;
	dialogY = 0;
        DeleteObject(hFont);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hw, msg, wp, lp);
}