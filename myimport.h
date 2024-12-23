#pragma once

// myimport 对话框 Dialog

class myimport : public CDialogEx
{
	DECLARE_DYNAMIC(myimport)

public:
	myimport(CWnd* pParent = nullptr);   // 标准构造函数 Standard constructor
	virtual ~myimport();

	// 对话框数据 Dialog data
#ifdef AFX_DESIGN_TIME
	enum { IDD = import };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持 DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedButton1(); // 确认按钮事件处理 Confirm button handler
	BOOL FA;                           // 操作标志 Operation flag
	afx_msg void OnBnClickedButton2(); // 导入按钮事件处理 Import button handler
	afx_msg void OnBnClickedCancel();  // 取消按钮事件处理 Cancel button handler
	afx_msg void OnPaint();            // 背景绘制 Paint handler
};
