// wujiekdDlg.h: Header file 头文件
//

#pragma once

// CmanagementSystemDlg 对话框 Dialog
class CmanagementSystemDlg : public CDialogEx
{
	// 构造 Construction
public:
	CmanagementSystemDlg(CWnd* pParent = nullptr);	// 标准构造函数 Standard constructor

	// 对话框数据 Dialog data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WUJIEKD_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持 DDX/DDV support

	// 实现 Implementation
protected:
	HICON m_hIcon; // 图标 Icon

	// 生成的消息映射函数 Generated message mapping functions
	virtual BOOL OnInitDialog();                        // 初始化对话框 Initialize dialog
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam); // 系统命令处理 System command handler
	afx_msg void OnPaint();                             // 绘制对话框 Paint handler
	afx_msg HCURSOR OnQueryDragIcon();                  // 拖动图标查询 Drag icon query
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedOk();                       // 点击“确定”按钮事件处理 On "OK" button click handler
	CString zhanghao;                                   // 账户字段 Account field
	CString mima;                                       // 密码字段 Password field
	afx_msg void OnEnChangeEdit2();                     // 编辑框内容变化处理 Edit box content change handler
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point); // 鼠标左键点击事件处理 Left mouse button click handler
	virtual BOOL PreTranslateMessage(MSG* pMsg);        // 消息预处理函数 Message pre-processor
};
