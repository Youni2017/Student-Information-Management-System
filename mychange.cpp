// mychange.cpp: Implementation file 实现文件
//

#include "stdafx.h"
#include "managementSystem.h"
#include "mychange.h"
#include "afxdialogex.h"


// mychange 对话框 Dialog

IMPLEMENT_DYNAMIC(mychange, CDialogEx)

mychange::mychange(CWnd* pParent /*=nullptr*/)
	: CDialogEx(change, pParent)
	, old_name(_T(""))   // 旧姓名 Old name
	, new_name(_T(""))   // 新姓名 New name
	, name(_T(""))       // 当前姓名 Current name
	, new_grade(_T(""))  // 新年级 New grade
	, new_class(_T(""))  // 新班级 New class
	, new_math(0)        // 新数学成绩 New math grade
	, new_program(0)     // 新程序设计成绩 New programming grade
	, new_lishan(0)      // 新力学成绩 New mechanics grade
	, new_number(0)      // 新学号 New student number
	, cao(0)             // 操作类型 Operation type
{
	FA = FALSE; // 初始化标志 Initialization flag
}

mychange::~mychange()
{
}

void mychange::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, old_name);    // 绑定旧姓名 Bind old name
	DDX_Text(pDX, IDC_EDIT7, new_name);    // 绑定新姓名 Bind new name
	DDX_Text(pDX, IDC_EDIT10, name);       // 绑定当前姓名 Bind current name
	DDX_Text(pDX, IDC_EDIT5, new_grade);   // 绑定新年级 Bind new grade
	DDX_Text(pDX, IDC_EDIT9, new_class);   // 绑定新班级 Bind new class
	DDX_Text(pDX, IDC_EDIT11, new_math);   // 绑定新数学成绩 Bind new math grade
	DDX_Text(pDX, IDC_EDIT3, new_program); // 绑定新程序设计成绩 Bind new programming grade
	DDX_Text(pDX, IDC_EDIT8, new_lishan);  // 绑定新力学成绩 Bind new mechanics grade
	DDX_Text(pDX, IDC_EDIT1, new_number);  // 绑定新学号 Bind new student number
	DDX_Radio(pDX, IDC_RADIO2, cao);       // 绑定操作类型 Bind operation type
}

BEGIN_MESSAGE_MAP(mychange, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &mychange::OnBnClickedButton1) // 确认按钮事件处理 Confirm button handler
	ON_BN_CLICKED(IDCANCEL, &mychange::OnBnClickedCancel)     // 取消按钮事件处理 Cancel button handler
	ON_EN_CHANGE(IDC_EDIT10, &mychange::OnEnChangeEdit10)     // 编辑框内容改变处理 Edit box content change handler
END_MESSAGE_MAP()


// mychange 消息处理程序 Message handlers

void mychange::OnBnClickedButton1()
{
	// 确认修改 Confirm changes
	CDialogEx::OnOK(); // TODO: 在此添加控件通知处理程序代码 Add control notification handler code here
}

void mychange::OnBnClickedCancel()
{
	// 取消修改 Cancel changes
	FA = TRUE; // 设置标志 Set flag
	// TODO: 在此添加控件通知处理程序代码 Add control notification handler code here
	CDialogEx::OnCancel();
}

void mychange::OnEnChangeEdit10()
{
	// TODO: 如果该控件是 RICHEDIT 控件，它将不发送此通知，
	// 除非重写 CDialogEx::OnInitDialog() 并调用
	// CRichEditCtrl().SetEventMask()，将 ENM_CHANGE 标志“或”运算到掩码中。
	// If this is a RICHEDIT control, it will not send this notification
	// unless you override CDialogEx::OnInitDialog() and call
	// CRichEditCtrl().SetEventMask(), ORing the ENM_CHANGE flag into the mask.

	// TODO: 在此添加控件通知处理程序代码 Add control notification handler code here
}
