//#define RGB(r, g, b) ((COLORREF)(((BYTE)(r) | ((WORD)(g) << 8)) | ((DWORD)(BYTE)(b)) << 16))
#include <Windows.h>
#include <Windowsx.h>
#include <tchar.h>
#include <iostream>


const int x = 750;
const int y = 750;

LRESULT CALLBACK HelloWordWndProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)

{
	HWND hWnd;
	WNDCLASS WndClass;
	MSG Msg;
	TCHAR szClassName[] = _T("MainWindow");
	TCHAR szTitel[] = _T("Мирсонов Лаб.1");

	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = HelloWordWndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(205, 133, 63));
	WndClass.lpszMenuName = NULL;
	WndClass.lpszClassName = szClassName;

	if (!RegisterClass(&WndClass))
	{
		MessageBox(NULL, _T("Cannot register class"), _T("Error"), MB_OK);
		return 0;
	}

	hWnd = CreateWindow(szClassName, szTitel, WS_OVERLAPPEDWINDOW, x,y,x,y, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		MessageBox(NULL, _T("Cannot create window"), _T("Error"), MB_OK);
		return 0;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&Msg, NULL, 0, 0))
	{		
		DispatchMessage(&Msg);
	}
	return Msg.wParam;
}

/*LRESULT CALLBACK MyWndProc(HWND hWnd,UINT msg, WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	switch (msg)
	{
	case WM_CREATE:
		hdc = GetDC(hWnd);
		CreateWindow(L"Button", L"Жмы мене", WS_CHILD | WS_VISIBLE, 10, 10, 100, 50, hWnd,  (HMENU)1001, GetModuleHandle(NULL), nullptr);

		return 0;
	case WM_RBUTTONDOWN:
		Ellipse(hdc, 500, 250, 500, 250);
		return 0;
	case WM_COMMAND:
		TextOut(hdc, 100, 100, L"Строка", 6);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}*/


LRESULT CALLBACK HelloWordWndProc(HWND hWnd, UINT Message, UINT wParam, LONG lParam)
{
	static int left, bott, Flag=0;
	bool crea = false;
	HDC hDC;
	TCHAR szText[] = _T("Мирсонов Вячеслав, группа РТ5-41Б");
	PAINTSTRUCT PaintStruct;
	RECT Rect;
	HFONT hFont;
	TCHAR szTitel1[] = _T("Мирсонов Лаб.1");
	switch (Message)
	{	
	case WM_LBUTTONDOWN:
//		Flag = 1;
		InvalidateRect(hWnd,&Rect,FALSE);
		break;
	case WM_PAINT:	
		if (Flag%2 == 1)
		{
			hDC = BeginPaint(hWnd, &PaintStruct);
			GetClientRect(hWnd, &Rect);
			SetTextColor(hDC, RGB(rand()%255 + 0, rand() % 255 + 0, rand() % 255 + 0));
			SetBkColor(hDC, RGB(205, 133, 63));
			hFont = CreateFont(0, 0, -450, -450, 0, 0, 0, 0,
				DEFAULT_CHARSET,
				0, 0, 0, 0,
				L"Arial Bold");
			SelectObject(hDC, hFont);
			TextOut(hDC, 20, 450, szText, 34);
			EndPaint(hWnd, &PaintStruct);
		}
		if (Flag%2 == 0 && Flag != 0)
		{
			hDC = BeginPaint(hWnd, &PaintStruct);
			GetClientRect(hWnd, &Rect);
			SetTextColor(hDC, RGB(205, 133, 63));
			SetBkColor(hDC, RGB(205, 133, 63));
			hFont = CreateFont(0, 0, -450, -450, 0, 0, 0, 0,
				DEFAULT_CHARSET,
				0, 0, 0, 0,
				L"Arial Bold");
			SelectObject(hDC, hFont);
			TextOut(hDC, 20, 450, szText, 34);
			EndPaint(hWnd, &PaintStruct);
		}
		break;

	case WM_RBUTTONDOWN:
		ShowWindow(hWnd,SW_MINIMIZE);
		Flag++;
		InvalidateRect(hWnd, &Rect, FALSE);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, Message, wParam, lParam);
}
