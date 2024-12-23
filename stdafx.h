// stdafx.h : 标准系统包含文件的包含文件 (Standard system include file)
// 或是经常使用但不常更改的特定于项目的包含文件
// (Or project-specific include file that is frequently used but rarely changed)

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // 从 Windows 头中排除极少使用的内容 (Exclude rarely-used stuff from Windows headers)
#endif

#include "targetver.h"           // 定义目标版本的头文件 (Header file to define the target version)

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // 某些 CString 构造函数将是显式的 (Some CString constructors will be explicit)

// 关闭 MFC 对某些常见但经常可放心忽略的警告消息的隐藏
// (Disable MFC's hiding of certain common but often safely ignorable warning messages)
#define _AFX_ALL_WARNINGS

// MFC 核心组件和标准组件 (MFC core and standard components)
#include <afxwin.h>

// MFC 扩展 (MFC extensions)
#include <afxext.h>

// MFC 自动化类 (MFC automation classes)
#include <afxdisp.h>

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC 对 Internet Explorer 4 公共控件的支持 (Support for IE 4 common controls)
#endif

#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>             // MFC 对 Windows 公共控件的支持 (Support for Windows common controls)
#endif // _AFX_NO_AFXCMN_SUPPORT

// 功能区和控件条的 MFC 支持 (MFC support for ribbons and control bars)
#include <afxcontrolbars.h>

// 多余的控件条包含可以去重 (Redundant afxcontrolbars.h includes can be removed)
#include <afxcontrolbars.h>
#include <afxcontrolbars.h>
#include <afxcontrolbars.h>
#include <afxcontrolbars.h>
#include <afxcontrolbars.h>
#include <afxcontrolbars.h>
#include <afxcontrolbars.h>
#include <afxcontrolbars.h>
#include <afxcontrolbars.h>

// UNICODE 支持的依赖性声明 (Dependency declaration for UNICODE support)
#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif
