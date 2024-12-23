#pragma once

// mydelete 对话框 Dialog

class mydelete : public CDialogEx
{
	DECLARE_DYNAMIC(mydelete)

public:
	mydelete(CWnd* pParent = nullptr);   // 标准构造函数 Standard constructor
	virtual ~mydelete();

	// 对话框数据 Dialog data
#ifdef AFX_DESIGN_TIME
	enum { IDD = delete_ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持 DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	CString b;          // 删除目标 Delete target
	int a;              // 操作选项 Operation option
	BOOL FA;            // 操作标志 Operation flag

	afx_msg void OnBnClickedButton2(); // 确认按钮事件处理 Confirm button handler
	afx_msg void OnBnClickedCancel();  // 取消按钮事件处理 Cancel button handler
	afx_msg void OnPaint();            // 背景绘制 Paint handler
};
