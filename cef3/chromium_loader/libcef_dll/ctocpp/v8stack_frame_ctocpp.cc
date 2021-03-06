// Copyright (c) 2015 The Chromium Embedded Framework Authors. All rights
// reserved. Use of this source code is governed by a BSD-style license that
// can be found in the LICENSE file.
//
// ---------------------------------------------------------------------------
//
// This file was generated by the CEF translator tool. If making changes by
// hand only do so within the body of existing method and function
// implementations. See the translator.README.txt file in the tools directory
// for more information.
//

#include "libcef_dll/ctocpp/v8stack_frame_ctocpp.h"


// VIRTUAL METHODS - Body may be edited by hand.

bool CefV8StackFrameCToCpp::IsValid() {
  if (CEF_MEMBER_MISSING(struct_, is_valid))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->is_valid(struct_);

  // Return type: bool
  return _retval?true:false;
}

CefString CefV8StackFrameCToCpp::GetScriptName() {
  if (CEF_MEMBER_MISSING(struct_, get_script_name))
    return CefString();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = struct_->get_script_name(struct_);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

CefString CefV8StackFrameCToCpp::GetScriptNameOrSourceURL() {
  if (CEF_MEMBER_MISSING(struct_, get_script_name_or_source_url))
    return CefString();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = struct_->get_script_name_or_source_url(
      struct_);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

CefString CefV8StackFrameCToCpp::GetFunctionName() {
  if (CEF_MEMBER_MISSING(struct_, get_function_name))
    return CefString();

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  cef_string_userfree_t _retval = struct_->get_function_name(struct_);

  // Return type: string
  CefString _retvalStr;
  _retvalStr.AttachToUserFree(_retval);
  return _retvalStr;
}

int CefV8StackFrameCToCpp::GetLineNumber() {
  if (CEF_MEMBER_MISSING(struct_, get_line_number))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->get_line_number(struct_);

  // Return type: simple
  return _retval;
}

int CefV8StackFrameCToCpp::GetColumn() {
  if (CEF_MEMBER_MISSING(struct_, get_column))
    return 0;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->get_column(struct_);

  // Return type: simple
  return _retval;
}

bool CefV8StackFrameCToCpp::IsEval() {
  if (CEF_MEMBER_MISSING(struct_, is_eval))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->is_eval(struct_);

  // Return type: bool
  return _retval?true:false;
}

bool CefV8StackFrameCToCpp::IsConstructor() {
  if (CEF_MEMBER_MISSING(struct_, is_constructor))
    return false;

  // AUTO-GENERATED CONTENT - DELETE THIS COMMENT BEFORE MODIFYING

  // Execute
  int _retval = struct_->is_constructor(struct_);

  // Return type: bool
  return _retval?true:false;
}


#ifndef NDEBUG
template<> base::AtomicRefCount CefCToCpp<CefV8StackFrameCToCpp,
    CefV8StackFrame, cef_v8stack_frame_t>::DebugObjCt = 0;
#endif

