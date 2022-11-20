#pragma once
#include <windows.h>
#include <tchar.h>
#include <time.h>
#include "resource.h"
#include <windowsX.h>

HWND hlist, hbutton, hedit, hbar1, hbar2, hbar3;

static int count = rand() % (20 - 10) + 10;

int sum = 0;
int ave = 0;
int proi = 0;
TCHAR buff[10];

void Close(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

BOOL InitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	hlist = GetDlgItem(hwnd, IDC_LIST1);
	hbutton = GetDlgItem(hwnd, IDC_BUTTON1);
	hedit = GetDlgItem(hwnd, IDC_EDIT1);
	hbar1 = GetDlgItem(hwnd, IDC_RADIO1);
	hbar2 = GetDlgItem(hwnd, IDC_RADIO2);
	hbar3 = GetDlgItem(hwnd, IDC_RADIO3);
	for (int i = 0; i < count;i++)
	{
		int buf = rand() % (-10 - 10) - 10;
		if (buf != 0)
		{
			buff[10];
			wsprintf(buff, TEXT("%d"), buf);
			SendMessage(hlist, LB_ADDSTRING, 0, LPARAM(buff));
		}
	}
	return TRUE;
}

void Command(HWND hwnd, UINT message, HWND hwndCtl, UINT codeNotify)
{
	switch (message)
	{
	case IDC_BUTTON1:
		LRESULT result = SendDlgItemMessage(hwnd, IDC_RADIO1, BM_GETCHECK, 0, 0);
		if (result == BST_CHECKED)
		{
			for (int i = 0; i < count; i++)
			{
				sum += buff[i];
			}
			SendMessage(hedit, WM_SET, 0, sum);
		}
	}
}

BOOL CALLBACK DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, Close);
		HANDLE_MSG(hwnd, WM_INITDIALOG, InitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, Command);
	}
	return FALSE;
}