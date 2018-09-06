#pragma once

#ifndef _CALLBACK_H_

#define _CALLBACK_H_

#include <windows.h>
#include <stdio.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

#endif