#pragma once

#include<Windows.h>

#include <vector>
using namespace std;

#include "QFrame.h"

LRESULT CALLBACK MainFrameCallbackProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class QMainFrame : public QFrame
{
	public:
		QMainFrame(LPWSTR new_title = L"Main Frame Window V 0.01");
		HWND CreateFrame();
		int RunMainLoop();
		~QMainFrame();
		LRESULT SetWindowProcedure(LRESULT(*p_procedure)(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam));
	private:
		friend LRESULT CALLBACK MainFrameCallbackProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

		LRESULT(*p_general_windows_proc) (HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
		static LPCWSTR WNDCLASSNAME;
		static ATOM MAIN_CLASS_REGISTERED;
};


