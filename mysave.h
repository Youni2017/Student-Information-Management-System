#pragma once

// mysave 对话框 (Dialog for save functionality)

class mysave : public CDialogEx
{
	DECLARE_DYNAMIC(mysave)

public:
	mysave(CWnd* pParent = nullptr);   // 标准构造函数 (Standard constructor)
	virtual ~mysave();                 // 析构函数 (Destructor)

	// 对话框数据 (Dialog data)
#ifdef AFX_DESIGN_TIME
	enum { IDD = save }; // 对话框资源 ID (Dialog resource ID)
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持 (DDX/DDV support)

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButton1(); // 保存按钮响应函数 (Save button event handler)
	afx_msg void OnBnClickedCancel();  // 取消按钮响应函数 (Cancel button event handler)
};
