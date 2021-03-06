// Copyright (c) 2015 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "cefclient/util_win.h"

#include "include/base/cef_logging.h"
#include "include/internal/cef_types.h"

namespace client {

void SetUserDataPtr(HWND hWnd, void* ptr) {
  SetLastError(ERROR_SUCCESS);
  LONG_PTR result = ::SetWindowLongPtr(
      hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(ptr));
  CHECK(result != 0 || GetLastError() == ERROR_SUCCESS);
}

WNDPROC SetWndProcPtr(HWND hWnd, WNDPROC wndProc) {
  WNDPROC old =
      reinterpret_cast<WNDPROC>(::GetWindowLongPtr(hWnd, GWLP_WNDPROC));
  CHECK(old != NULL);
  LONG_PTR result = ::SetWindowLongPtr(
      hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(wndProc));
  CHECK(result != 0 || GetLastError() == ERROR_SUCCESS);
  return old;
}

int GetCefMouseModifiers(WPARAM wparam) {
  int modifiers = 0;
  if (wparam & MK_CONTROL)
    modifiers |= EVENTFLAG_CONTROL_DOWN;
  if (wparam & MK_SHIFT)
    modifiers |= EVENTFLAG_SHIFT_DOWN;
  if (IsKeyDown(VK_MENU))
    modifiers |= EVENTFLAG_ALT_DOWN;
  if (wparam & MK_LBUTTON)
    modifiers |= EVENTFLAG_LEFT_MOUSE_BUTTON;
  if (wparam & MK_MBUTTON)
    modifiers |= EVENTFLAG_MIDDLE_MOUSE_BUTTON;
  if (wparam & MK_RBUTTON)
    modifiers |= EVENTFLAG_RIGHT_MOUSE_BUTTON;

  // Low bit set from GetKeyState indicates "toggled".
  if (::GetKeyState(VK_NUMLOCK) & 1)
    modifiers |= EVENTFLAG_NUM_LOCK_ON;
  if (::GetKeyState(VK_CAPITAL) & 1)
    modifiers |= EVENTFLAG_CAPS_LOCK_ON;
  return modifiers;
}

int GetCefKeyboardModifiers(WPARAM wparam, LPARAM lparam) {
  int modifiers = 0;
  if (IsKeyDown(VK_SHIFT))
    modifiers |= EVENTFLAG_SHIFT_DOWN;
  if (IsKeyDown(VK_CONTROL))
    modifiers |= EVENTFLAG_CONTROL_DOWN;
  if (IsKeyDown(VK_MENU))
    modifiers |= EVENTFLAG_ALT_DOWN;

  // Low bit set from GetKeyState indicates "toggled".
  if (::GetKeyState(VK_NUMLOCK) & 1)
    modifiers |= EVENTFLAG_NUM_LOCK_ON;
  if (::GetKeyState(VK_CAPITAL) & 1)
    modifiers |= EVENTFLAG_CAPS_LOCK_ON;

  switch (wparam) {
  case VK_RETURN:
    if ((lparam >> 16) & KF_EXTENDED)
      modifiers |= EVENTFLAG_IS_KEY_PAD;
    break;
  case VK_INSERT:
  case VK_DELETE:
  case VK_HOME:
  case VK_END:
  case VK_PRIOR:
  case VK_NEXT:
  case VK_UP:
  case VK_DOWN:
  case VK_LEFT:
  case VK_RIGHT:
    if (!((lparam >> 16) & KF_EXTENDED))
      modifiers |= EVENTFLAG_IS_KEY_PAD;
    break;
  case VK_NUMLOCK:
  case VK_NUMPAD0:
  case VK_NUMPAD1:
  case VK_NUMPAD2:
  case VK_NUMPAD3:
  case VK_NUMPAD4:
  case VK_NUMPAD5:
  case VK_NUMPAD6:
  case VK_NUMPAD7:
  case VK_NUMPAD8:
  case VK_NUMPAD9:
  case VK_DIVIDE:
  case VK_MULTIPLY:
  case VK_SUBTRACT:
  case VK_ADD:
  case VK_DECIMAL:
  case VK_CLEAR:
    modifiers |= EVENTFLAG_IS_KEY_PAD;
    break;
  case VK_SHIFT:
    if (IsKeyDown(VK_LSHIFT))
      modifiers |= EVENTFLAG_IS_LEFT;
    else if (IsKeyDown(VK_RSHIFT))
      modifiers |= EVENTFLAG_IS_RIGHT;
    break;
  case VK_CONTROL:
    if (IsKeyDown(VK_LCONTROL))
      modifiers |= EVENTFLAG_IS_LEFT;
    else if (IsKeyDown(VK_RCONTROL))
      modifiers |= EVENTFLAG_IS_RIGHT;
    break;
  case VK_MENU:
    if (IsKeyDown(VK_LMENU))
      modifiers |= EVENTFLAG_IS_LEFT;
    else if (IsKeyDown(VK_RMENU))
      modifiers |= EVENTFLAG_IS_RIGHT;
    break;
  case VK_LWIN:
    modifiers |= EVENTFLAG_IS_LEFT;
    break;
  case VK_RWIN:
    modifiers |= EVENTFLAG_IS_RIGHT;
    break;
  }
  return modifiers;
}

bool IsKeyDown(WPARAM wparam) {
  return (GetKeyState(wparam) & 0x8000) != 0;
}

}  // namespace client
