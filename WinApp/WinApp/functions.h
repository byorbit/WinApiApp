#pragma once

#ifndef _FUNCTIONS_H_

#define _FUNCTIONS_H_

#include <windows.h>
#include <stdio.h>

void AddCity(HWND hListBox);
void OnButtonClicked(HWND hListBox1, HWND hListBox2);

void OnListBoxDblClk(HWND hListBox);

void OnListBoxSelChange(HWND hListBox, HWND hStatic);


#endif
