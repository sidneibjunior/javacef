// Copyright (c) 2014 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.

#include <gtk/gtk.h>
#include <libgen.h>
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#undef Success  // Definition conflicts with cef_message_router.h

#include <string>

#include "cefclient/client_handler.h"
#include "include/cef_browser.h"
#include "include/cef_frame.h"
#include "cefclient/cefclient.h"
#include "chromium_loader/jni_tools.h"

namespace client {

void ClientHandler::OnAddressChange(CefRefPtr<CefBrowser> browser,
                                    CefRefPtr<CefFrame> frame,
                                    const CefString& url) {
  CEF_REQUIRE_UI_THREAD();

  if (GetBrowserId() == browser->GetIdentifier() && frame->IsMain()) {
      // Set the edit window text
    /*std::string urlStr(url);
    gtk_entry_set_text(GTK_ENTRY(edit_handle_), urlStr.c_str());*/
  }
}

void ClientHandler::OnTitleChange(CefRefPtr<CefBrowser> browser,
                                  const CefString& title) {
  CEF_REQUIRE_UI_THREAD();

  std::string titleStr(title);
  if (GetBrowserId() == browser->GetIdentifier()) {
    if (id != browser->GetHost()->GetClient()->id)
      fprintf(stderr, "ClientHandler::OnTitleChange id is not the same\n");

    // Send title to java side if the browser is not closed.
    if (id != -1)
      set_title(std::string(title).c_str(), id);
  } else {
    GtkWidget* window = gtk_widget_get_ancestor(
        GTK_WIDGET(browser->GetHost()->GetWindowHandle()),
        GTK_TYPE_WINDOW);
    gtk_window_set_title(GTK_WINDOW(window), titleStr.c_str());
  }
}

void ClientHandler::SetLoading(bool isLoading) {
  if (id != -1)
    send_load(id, isLoading);
}

void ClientHandler::SetNavState(bool canGoBack, bool canGoForward) {
  // Do nothing.
}

}  // namespace client
