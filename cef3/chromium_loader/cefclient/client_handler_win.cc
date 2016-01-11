// Copyright (c) 2011 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include "cefclient/client_handler.h"

#include <string>
#include <windows.h>
#include <shlobj.h> 

#include "include/cef_browser.h"
#include "include/cef_frame.h"
#include "cefclient/resource.h"
#include "chromium_loader/jni_tools.h"

namespace client {
void ClientHandler::OnAddressChange(CefRefPtr<CefBrowser> browser,
                                    CefRefPtr<CefFrame> frame,
                                    const CefString& url) {
  CEF_REQUIRE_UI_THREAD();
/*
  if (GetBrowserId() == browser->GetIdentifier() && frame->IsMain()) {
    // Set the edit window text
    SetWindowText(edit_handle_, std::wstring(url).c_str());
  }
*/
}

void ClientHandler::OnTitleChange(CefRefPtr<CefBrowser> browser,
                                  const CefString& title) {
  CEF_REQUIRE_UI_THREAD();

  // Set the frame window title bar
  CefWindowHandle hwnd = browser->GetHost()->GetWindowHandle();
  if (GetBrowserId() == browser->GetIdentifier()) {
    // Send title to java side.
    set_title(std::string(title).c_str(), browser->GetHost()->GetClient()->id);
  } else
    SetWindowText(GetAncestor(hwnd, GA_ROOT), std::wstring(title).c_str());
}

void ClientHandler::SetLoading(bool isLoading) {
  send_load(id, isLoading);
}

void ClientHandler::SetNavState(bool canGoBack, bool canGoForward) {
  // ignored
}

}  // namespace client
