#include <Windows.h>
#include <io.h>
#include "functions.h"

void AddCity(HWND hListBox)
{
	char *cities[] = { "Kars", "Adana", "Adiyaman", "Afyon", "Agri", "Amasya", "Ankara", "Antalya",
		"Artvin", "Aydin", "Balikesir", "Bilecik", "Edirne", "Eskisehir", "Kirsehir", NULL };
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
		MessageBox(NULL, "Eleman bulunamadi!", "Message", MB_OK);
		return;
	}
	SendMessage(hListBox1, LB_GETTEXT, index, (LPARAM)text);
	SendMessage(hListBox1, LB_DELETESTRING, index, 0);
	SendMessage(hListBox2, LB_ADDSTRING, 0, (LPARAM)text);
}

void OnListBoxDblClk(HWND hListBox)
{
	int index = SendMessage(hListBox, LB_GETCURSEL, 0, 0);
	char fileName[256];
	struct _finddata_t fd;
	char fileInfo[1000];
	SendMessage(hListBox, LB_GETTEXT, index, (LPARAM)fileName);
	if (!_findfirst(fileName, &fd)) {
		MessageBox(NULL, "Cannot get file info!..", "Error", MB_OK);
		return;
	}
	sprintf(fileInfo, "File Name: %s\nFile Size: %ld", fd.name, fd.size);
	MessageBox(NULL, fileInfo, "File Info", MB_OK);
}

void OnListBoxSelChange(HWND hListBox, HWND hStatic)
{
	int index = SendMessage(hListBox, LB_GETCURSEL, 0, 0);
	char fileName[256];
	struct _finddata_t fd;
	char fileInfo[1000];
	long handle;

	SendMessage(hListBox, LB_GETTEXT, index, (LPARAM)fileName);
	if (!(handle = _findfirst(fileName, &fd))) {
		MessageBox(NULL, "Cannot get file info!..", "Error", MB_OK);
		return;
	}

	sprintf(fileInfo, "File Name: %s\nFile Size: %ld", fd.name, fd.size);
	SetWindowText(hStatic, fileInfo);
	_findclose(handle);
}
