// managementSystem.h: Main header file for the PROJECT_NAME application. PROJECT_NAME 应用程序的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
#error "Include 'stdafx.h' before including this file to generate a PCH file. 在包含此文件之前包含“stdafx.h”以生成 PCH 文件。"
#endif

#include "resource.h"		// Main symbols 主符号


// CmanagementSystemApp:
// For the implementation of this class, see managementSystem.cpp. 有关此类的实现，请参阅 managementSystem.cpp
//

class CmanagementSystemApp : public CWinApp
{
public:
	CmanagementSystemApp();

	// 重写 Overrides
public:
	virtual BOOL InitInstance();

	// 实现 Implementation

	DECLARE_MESSAGE_MAP()
};

extern CmanagementSystemApp theApp;
