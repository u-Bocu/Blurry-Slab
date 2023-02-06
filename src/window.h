//
// Created by mremond on 05/02/2023.
//

#ifndef BLURRY_SLAB_WINDOW_H
#define BLURRY_SLAB_WINDOW_H

#include <windef.h>
#include <winuser.h>
#include <libloaderapi.h>

HWND SlbCreateWindow(LPCWSTR wclass_name);

void SlbResizeWindow(HWND hwnd, UINT flag, int width, int height);


LRESULT CALLBACK SlbDefaultWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

#endif //BLURRY_SLAB_WINDOW_H
