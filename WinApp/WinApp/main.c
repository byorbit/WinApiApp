#include <windows.h>
#include <stdio.h>
#define ID_LISTBOX1	100
#define ID_BUTTON1	101
#define ID_LISTBOX2	102
#define ID_BUTTON2	103

LRESULT CALLBACK WndProc(HWND hWnd, UINT message,
	WPARAM wParam, LPARAM lParam);
void AddCity(HWND hListBox);
void OnButtonClicked(HWND hListBox1, HWND hListBox2);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int
	nCmdShow)
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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hListBox1, hListBox2, hButton1, hButton2, hButton3, hButton4, hButton5;

	switch (message) {
	case WM_CREATE:
		hListBox1
			=
			CreateWindow("listbox",
				"",
				WS_CHILD | WS_VISIBLE | LBS_STANDARD | LBS_EXTENDEDSEL | LBS_MULTIPLESEL,
				100, 100, 100, 200,
				hWnd,
				(HMENU)
				ID_LISTBOX1, ((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hButton1
			=
			CreateWindow("button",
				">>>",
				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
				220, 100, 50, 25, hWnd,
				(HMENU)
				ID_BUTTON1,
				((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hListBox2 =	CreateWindow("listbox",	"",
				WS_CHILD | WS_VISIBLE | LBS_STANDARD | LBS_EXTENDEDSEL | LBS_MULTIPLESEL,
				300, 100, 100, 200,	hWnd,(HMENU)ID_LISTBOX2,
				((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hButton2 = CreateWindow("button", "<<<",
				WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
				220, 275, 50, 25, hWnd,(HMENU)ID_BUTTON2,
				((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hButton3 = CreateWindow("button", "Start",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 100, 100, 100, hWnd, (HMENU)100,
			((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hButton4 = CreateWindow("button", "Standby",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			500, 100, 100, 100, hWnd, (HMENU)100,
			((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hButton5 = CreateWindow("button", "STOP",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			600, 100, 100, 100, hWnd, (HMENU)100,
			((LPCREATESTRUCT)lParam)->hInstance, NULL);

		AddCity(hListBox1);
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == ID_BUTTON1 && HIWORD(wParam) == BN_CLICKED)
			OnButtonClicked(hListBox1, hListBox2);
		else if ((LOWORD(wParam) == ID_BUTTON2 && HIWORD(wParam) == BN_CLICKED))
			OnButtonClicked(hListBox2, hListBox1);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}
void AddCity(HWND hListBox)
{
	char *cities[] = { "Kars", "Adana", "Adýyaman", "Afyon", "Aðrý", "Amasya", "Ankara", "Antalya",
		"Artvin", "Aydýn", "Balýkesir", "Bilecik", "Edirne", "Eskiþehir", "Kýrþehir", "Viranþehir", NULL };
	int i;
	for (i = 0; cities[i] != NULL; ++i)
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)cities[i]);
}
void OnButtonClicked(HWND hListBox1, HWND hListBox2)
{
	int index;
	char text[30];
	index = SendMessage(hListBox1, LB_GETCURSEL, 0, 0);
	if (SendMessage(hListBox1, LB_GETCOUNT, 0, 0) == 0) {
		MessageBox(NULL, "eleman bulunamadý", "Message", MB_OK);
		return;
	}
	SendMessage(hListBox1, LB_GETTEXT, index, (LPARAM)text);
	SendMessage(hListBox1, LB_DELETESTRING, index, 0);
	SendMessage(hListBox2, LB_ADDSTRING, 0, (LPARAM)text);
}


/*#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int
	nCmdShow)
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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND hButton, hButton1, hButton2, hButton3, hButton4, hButton5;
	static HWND hListBox1, hListBox2, hButtonLB1, hButtonLB2;

	switch (message) {
	case WM_CREATE:
		hListBox1 = CreateWindow("listbox", "",
			WS_CHILD | WS_VISIBLE | LBS_STANDARD | LBS_EXTENDEDSEL | LBS_MULTIPLESEL,
			500, 100, 100, 200, hWnd, (HMENU)ID_LISTBOX1,
			((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hButtonLB1 = CreateWindow("button", "List",
		WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		500, 300, 100, 30, hWnd, (HMENU)ID_BUTTONLB1,
		((LPCREATESTRUCT)lParam)->hInstance, NULL);

		hListBox2 = CreateWindow("listbox", "",
			WS_CHILD | WS_VISIBLE | LBS_STANDARD | LBS_EXTENDEDSEL | LBS_MULTIPLESEL,
			600, 100, 100, 200, hWnd, (HMENU)ID_LISTBOX2,
			((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hButtonLB2 = CreateWindow("button", "List",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			600, 300, 100, 30, hWnd, (HMENU)ID_BUTTONLB2,
			((LPCREATESTRUCT)lParam)->hInstance, NULL);







		hButton = CreateWindow("button", "Start",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			100, 100, 100, 100, hWnd, (HMENU)100,
			((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hButton1 = CreateWindow("button", "Standby",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			200, 100, 100, 100, hWnd, (HMENU)100,
			((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hButton2 = CreateWindow("button", "STOP",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			300, 100, 100, 100, hWnd, (HMENU)100,
			((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hButton3 = CreateWindow("button", "MENU",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			400, 100, 100, 100, hWnd, (HMENU)100,
			((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hButton4 = CreateWindow("button", "ZERO",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			100, 200, 100, 100, hWnd, (HMENU)100,
			((LPCREATESTRUCT)lParam)->hInstance, NULL);
		hButton5 = CreateWindow("button", "RANGE",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			100, 300, 100, 100, hWnd, (HMENU)100,
			((LPCREATESTRUCT)lParam)->hInstance, NULL);
		
		AddCity(hListBox1);
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == ID_BUTTONLB1 && HIWORD(wParam) == BN_CLICKED)
			OnButtonClicked(hListBox1, hListBox2);
		else if ((LOWORD(wParam) == ID_BUTTONLB2 && HIWORD(wParam) == BN_CLICKED))
			OnButtonClicked(hListBox2, hListBox1);

		else if (GetDlgCtrlID(hButton) == wParam) 
			SendMessage(hWnd, WM_USER, 0, 0);
	/*case WM_USER:
		MessageBox(hButton, "Butona týklandý", "Message", MB_OK);
		
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void AddCity(HWND hListBox) {
	char *cities[] = { "Ankara","Ýstanbul","Samsun","Çankýrý","Çorum","Yozgat","Bursa","Tokat","Sinop","Maraþ","Antep","Kocaeli", NULL};
	int i;

	for (i = 0; cities[i] != NULL; ++i)
		SendMessage(hListBox, LB_ADDSTRING, 0, (LPARAM)cities[i]);
}

void OnButtonClicked(HWND hListBox1, HWND hListBox2){
	char text[SIZE];
	int index;
	
	index = SendMessage(hListBox1, LB_GETCURSEL, 0, 0);
	if (SendMessage(hListBox1, LB_GETCOUNT, 0, 0) == 0) {
		MessageBox(NULL, "Eleman Bulunamadý!!", "Message", MB_OK);
		return;
	}

	SendMessage(hListBox1, LB_GETTEXT, index, (LPARAM)text);
	SendMessage(hListBox1, LB_DELETESTRING, index, 0);
	SendMessage(hListBox2, LB_ADDSTRING, 0, (LPARAM)text);

	MessageBox(NULL, text, "List Box Index", MB_OK);


} */