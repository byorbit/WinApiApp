#include <windows.h>
#include <stdio.h>
#include "functions.h"

#define ID_LISTBOX1	100
#define ID_BUTTON1	101
#define ID_LISTBOX2	102
#define ID_BUTTON2	103
#define ID_STATIC	104



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hListBox1, hListBox2, hButton1, hButton2, hButton3, hButton4, hButton5, hStatic;

	switch (message) {
	case WM_CREATE:
		hListBox1 = CreateWindow("listbox", "",	WS_CHILD | WS_VISIBLE | LBS_STANDARD | LBS_EXTENDEDSEL | LBS_MULTIPLESEL,
			100, 100, 100, 200,	hWnd,(HMENU)ID_LISTBOX1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		
		hButton1 = CreateWindow("button", ">>>",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			220, 100, 50, 25, hWnd, (HMENU)ID_BUTTON1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);

		hListBox2 = CreateWindow("listbox", "",	WS_CHILD | WS_VISIBLE | LBS_STANDARD | LBS_EXTENDEDSEL | LBS_MULTIPLESEL,
			300, 100, 100, 200, hWnd, (HMENU)ID_LISTBOX2, ((LPCREATESTRUCT)lParam)->hInstance, NULL);

		hButton2 = CreateWindow("button", "<<<", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			220, 275, 50, 25, hWnd, (HMENU)ID_BUTTON2, ((LPCREATESTRUCT)lParam)->hInstance, NULL);

		hButton3 = CreateWindow("button", "Start",	WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 100, 100, 100, hWnd, (HMENU)100,((LPCREATESTRUCT)lParam)->hInstance, NULL);

		hButton4 = CreateWindow("button", "Standby",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			500, 100, 100, 100, hWnd, (HMENU)100,((LPCREATESTRUCT)lParam)->hInstance, NULL);

		hButton5 = CreateWindow("button", "STOP",WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			600, 100, 100, 100, hWnd, (HMENU)100,((LPCREATESTRUCT)lParam)->hInstance, NULL);

		hStatic = CreateWindow("static", "", WS_CHILD | WS_VISIBLE,
			400, 200, 300, 100, hWnd, (HMENU)ID_STATIC,	((LPCREATESTRUCT)lParam)->hInstance, NULL);

		//AddCity(hListBox1);
		SendMessage(hListBox1, LB_DIR, DDL_DIRECTORY, (LPARAM) "c:\\windows\\*.*");

		break;
	case WM_COMMAND:
		/*
		if (LOWORD(wParam) == ID_BUTTON1 && HIWORD(wParam) == BN_CLICKED)
			OnButtonClicked(hListBox1, hListBox2);
		else if((LOWORD(wParam) == ID_BUTTON2 && HIWORD(wParam) == BN_CLICKED))
			OnButtonClicked(hListBox2, hListBox1);
		break;
		*/

		if (LOWORD(wParam) == ID_LISTBOX1)
			switch (HIWORD(wParam)) {
				case LBN_DBLCLK:
					OnListBoxDblClk(hListBox1);
					break;

				case LBN_SELCHANGE:
					OnListBoxSelChange(hListBox1, hStatic);
					break;
				}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
