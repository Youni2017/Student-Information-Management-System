#pragma once

// mychange 对话框 Dialog

class mychange : public CDialogEx
{
	DECLARE_DYNAMIC(mychange)

public:
	mychange(CWnd* pParent = nullptr);   // 标准构造函数 Standard constructor
	virtual ~mychange();

	// 对话框数据 Dialog data
#ifdef AFX_DESIGN_TIME
	enum { IDD = change };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持 DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	CString old_name;      // 旧姓名 Old name
	CString new_name;      // 新姓名 New name
	CString name;          // 当前姓名 Current name
	CString new_grade;     // 新年级 New grade
	CString new_class;     // 新班级 New class
	UINT new_math;         // 新数学成绩 New math grade
	UINT new_program;      // 新程序设计成绩 New programming grade
	UINT new_lishan;       // 新力学成绩 New mechanics grade
	UINT new_number;       // 新学号 New student number

	afx_msg void OnBnClickedButton1(); // 确认按钮事件处理 Confirm button handler
	afx_msg void OnBnClickedCancel();  // 取消按钮事件处理 Cancel button handler
	afx_msg void OnEnChangeEdit10();   // 编辑框内容改变处理 Edit box content change handler

	int cao;             // 操作类型 Operation type
	BOOL FA;             // 操作标志 Operation flag
};
