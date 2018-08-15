#include <windows.h>
#define ID_CHILD	100

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK WndChildProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdParam, int nCmdShow)
{
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
	if (!hPrevInstance) {
		wndClass.style = CS_HREDRAW | CS_VREDRAW;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;
		wndClass.hInstance = hInstance;
		wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndClass.lpszMenuName = NULL;
		wndClass.lpszClassName = "SampleChild";
		wndClass.lpfnWndProc = (WNDPROC)WndChildProc;
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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam,
	LPARAM lParam)
{
	static HWND s_hWndChild;
	switch (message) {
	case WM_CREATE:
		s_hWndChild = CreateWindow("SampleChild", "Generic App",
			WS_CHILD | WS_VISIBLE | WS_BORDER | WS_CAPTION | WS_THICKFRAME,
			100, 100, 100, 100, hWnd,
			(HMENU)ID_CHILD,
			((LPCREATESTRUCT)lParam)->hInstance, NULL);
		if (!s_hWndChild)
			return -1;
		break;
	case WM_LBUTTONDOWN:
		SendMessage(s_hWndChild, WM_USER, 0, 0);
		break;
	case WM_USER:
		MessageBox(hWnd, "Message From Child!..", "Message", MB_OK);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
LRESULT CALLBACK WndChildProc(HWND hWnd, UINT message, WPARAM wParam,
	LPARAM lParam)
{
	switch (message) {
	case WM_USER:
		MessageBox(hWnd, "Message From Parent!..", "Message", MB_OK);
		break;
	case WM_LBUTTONDOWN:
		SendMessage(GetParent(hWnd), WM_USER, 0, 0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
