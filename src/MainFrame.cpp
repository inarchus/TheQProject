#include "MainFrame.h"
#include "QButton.h"

#include <Windows.h>

LPCWSTR QMainFrame::WNDCLASSNAME = L"MainFrameWindowClass";
ATOM QMainFrame::MAIN_CLASS_REGISTERED = 0;

LRESULT CALLBACK MainFrameCallbackProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	QMainFrame * qmf = (QMainFrame *)GetWindowLong(hWnd, GWL_USERDATA);

	if (qmf && qmf->p_general_windows_proc)
	{
		return qmf->p_general_windows_proc(hWnd, uMsg, wParam, lParam);
	}
	switch (uMsg)
	{
		case WM_COMMAND:
		{
			switch(HIWORD(wParam))
			{
				case BN_CLICKED:
				{
					
					if (qmf)
					{

						QButton * p_qb = (QButton *)qmf->FindChildByHWND((HWND)lParam);
						if (p_qb)
						{
							HWND find_hwnd = p_qb->GetHWND();
							QButtonEvent qbe;
							p_qb->SendEvent(qbe);
						}
					}
					break;
				}
			}
			break;
		}
		case WM_KEYDOWN:
		{
			
			MessageBox(NULL, L"", L"", MB_OK);
			break;
		}
		case WM_DESTROY:
		{
			PostQuitMessage(int(hWnd));
			break;
		}
		default:
		{
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		}
	}
	return 0L;
}

QMainFrame::QMainFrame(LPWSTR new_title)
	: p_general_windows_proc(NULL)
{
	title_string = new_title;
		
	if (!MAIN_CLASS_REGISTERED)
	{
		WNDCLASS wc;
		ZeroMemory(&wc, sizeof(WNDCLASS));
		wc.hbrBackground = CreateSolidBrush(RGB(0, 0, 0));
		wc.hCursor = LoadCursor(NULL, L"IDC_ARROW");
		wc.hIcon = LoadIcon(NULL, L"IDI_APPLICATION");
		wc.hInstance = GetModuleHandle(NULL);
		wc.lpfnWndProc = MainFrameCallbackProc;
		wc.lpszClassName = WNDCLASSNAME;
		MAIN_CLASS_REGISTERED = RegisterClass(&wc);
	}
}


QMainFrame::~QMainFrame()
{
	if (hWindow)
	{
		DestroyWindow(hWindow);
	}	
}

HWND QMainFrame::CreateFrame()
{
	hWindow = CreateWindow(QMainFrame::WNDCLASSNAME, title_string , WS_OVERLAPPEDWINDOW | WS_VISIBLE, position.GetX(), position.GetY(), size.GetX(), size.GetY(), NULL, NULL, GetModuleHandle(NULL), (LPVOID) this);
	SetWindowLong(hWindow, GWL_USERDATA, (LONG)this);
	return hWindow;
}

int QMainFrame::RunMainLoop()
{
	MSG message;
	while (GetMessage(&message, NULL, NULL, NULL))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	}

	return message.wParam;
}

LRESULT QMainFrame::SetWindowProcedure(LRESULT(*CALLBACK p_procedure)(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam))
{
	p_general_windows_proc = p_procedure;
	return 0L;
}
