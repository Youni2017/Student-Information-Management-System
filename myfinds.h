#pragma once

// myfinds 对话框 Dialog

class myfinds : public CDialogEx
{
	DECLARE_DYNAMIC(myfinds)

public:
	myfinds(CWnd* pParent = nullptr);   // 标准构造函数 Standard constructor
	virtual ~myfinds();

	// 对话框数据 Dialog data
#ifdef AFX_DESIGN_TIME
	enum { IDD = find_s };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持 DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButton1(); // 确认按钮事件处理 Confirm button handler
	afx_msg void OnBnClickedCancel();  // 取消按钮事件处理 Cancel button handler

	CString b;             // 查找内容 Search content
	BOOL FA;               // 操作标志 Operation flag
	CString filenaem = "../keda.txt"; // 文件路径 File path
	int a;                 // 查找方式 Search method

	afx_msg void OnPaint(); // 背景绘制 Paint handler
};
