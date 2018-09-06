/* Created by ByOrbit */

#include <windows.h>
#include <stdio.h>
#include "callback.h"
#include "functions.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {

	WNDCLASS wndClass;
	HWND hWnd;
	MSG message;
	if (!hPrevInstance) {
		wndClass.style = CS_HREDRAW | CS_VREDRAW;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;
		wndClass.hInstance = hInstance;
		wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndClass.lpszMenuName = NULL;
		wndClass.lpszClassName = "Generic";
		wndClass.lpfnWndProc = (WNDPROC)WndProc;
		if (!RegisterClass(&wndClass))
			return -1;
	}

	hWnd = CreateWindow("Generic", "Generic App",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		NULL,
		NULL,
		hInstance,
		NULL);
	if (!hWnd)
		return -1;

	ShowWindow(hWnd, SW_RESTORE);
	UpdateWindow(hWnd);

	while (GetMessage(&message, 0, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return (message.wParam);
}



