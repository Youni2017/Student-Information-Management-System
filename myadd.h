#pragma once

// add 对话框 Dialog

class myadd : public CDialogEx
{
	DECLARE_DYNAMIC(myadd)

public:
	myadd(CWnd* pParent = nullptr);   // 标准构造函数 Standard constructor
	virtual ~myadd();

	// 对话框数据 Dialog data
#ifdef AFX_DESIGN_TIME
	enum { IDD = add };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持 DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	CString name;       // 姓名 Name
	CString grade;      // 年级 Grade
	CString classs;     // 班级 Class
	int xing;           // 性别 Gender

	UINT number;        // 学号 Student number

	CString m_set;      // 手动增加字段 Manually added field
	BOOL FA;            // 标志变量 Flag variable
	UINT program;       // 程序设计成绩 Programming grade
	UINT math;          // 数学成绩 Math grade
	UINT lishan;        // 力学成绩 Mechanics grade

	afx_msg void OnBnClickedCancel(); // 取消按钮事件处理 Cancel button event handler
	virtual BOOL OnInitDialog();      // 初始化对话框 Initialize dialog
	afx_msg void OnBnClickedOk();     // 确认按钮事件处理 OK button event handler
	afx_msg void OnPaint();           // 绘制背景 Paint handler
	afx_msg void OnEnChangeEdit1();   // 编辑框内容变化处理 Edit box content change handler
};
