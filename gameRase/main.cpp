
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#include "Helper.h"
#include "GameLogic.h"

HHOOK _hook;
KBDLLHOOKSTRUCT kbdStruct;
GameLogic newGame;

LRESULT __stdcall HookCallback(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode >= 0)
	{
		
		if (wParam == WM_KEYDOWN)
		{
			printf("oo0");
			kbdStruct = *((KBDLLHOOKSTRUCT*)lParam);
			
			switch (kbdStruct.vkCode)
			{
			case VK_UP:
				newGame.increaseSpeed();
				break;
			case VK_DOWN:
				newGame.decreaseSpeed();
				break;
			case VK_LEFT:
				printf("oo");
				newGame.shiftLeft();
				break;
			case VK_RIGHT:
				newGame.shiftRight();
				break;
			case VK_RETURN:
				newGame.pause();
			case VK_ESCAPE:
				return 0;
			default:
				break;
			}

		}
	}

return CallNextHookEx(_hook, nCode, wParam, lParam);
}

void SetHook()
{
	if (!(_hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookCallback, NULL, 0)))
	{
		printf("Ooops. You have problems with hook.");
	}
}

void ReleaseHook()
{
	UnhookWindowsHookEx(_hook);
}

void main()
{
	SetHook();
	
	newGame.printGame();
	//MSG msg;
	//while (GetMessage(&msg, NULL, 0, 0))
	//{
	//
	//}
	ReleaseHook();
}



