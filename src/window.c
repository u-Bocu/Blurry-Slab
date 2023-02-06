//
// Created by mremond on 05/02/2023.
//

#include "window.h"

HWND SlbCreateWindow(LPCWSTR wclass_name) {

    WNDCLASSW wc = {};

    HMODULE hInstance = GetModuleHandleW(NULL); // Default module handle

    wc.lpfnWndProc = SlbDefaultWindowProc; // Default window procedure
    wc.hInstance = hInstance;
    wc.lpszClassName = wclass_name;

    RegisterClassW(&wc);

    // Create the window

    HWND hwnd = CreateWindowExW(
            0,                  // Optional window styles
            wclass_name,      // Window class name
            wclass_name,    // Window name
            WS_OVERLAPPEDWINDOW,  // Window style

            // Size and position
            CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

            NULL,     // Parent Window
            NULL,        // Menu
            hInstance, // Instance Handle
            NULL        // Additional application data
    );

    return hwnd;
}

void SlbResizeWindow(HWND hwnd, UINT flag, int width, int height) {
    LPRECT rect = {0};

    GetWindowRect(hwnd, rect);

    SetWindowPos(hwnd,
                 HWND_TOP,
                 rect->left, rect->top,

                 width, height,
                 0);
}


LRESULT CALLBACK SlbDefaultWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_SIZE: {
            int width = LOWORD(lParam);  // Macro to get the low-order word.
            int height = HIWORD(lParam); // Macro to get the high-order word.

            // Respond to the message:
            SlbResizeWindow(hwnd, (UINT) wParam, width, height);
        }
            return 0;

        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);

            FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 1));

            EndPaint(hwnd, &ps);
        }
            return 0;

        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        default:
            return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}