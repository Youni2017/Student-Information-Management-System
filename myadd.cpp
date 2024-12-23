// myadd.cpp: Implementation file 实现文件
//

#include "stdafx.h"
#include "managementSystem.h"
#include "myadd.h"
#include "afxdialogex.h"


// myadd 对话框 Dialog

IMPLEMENT_DYNAMIC(myadd, CDialogEx)

myadd::myadd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(add, pParent)
	, name(_T(""))      // 姓名 Name
	, grade(_T(""))     // 年级 Grade
	, classs(_T(""))    // 班级 Class
	, xing(0)           // 性别 Gender
	, program(0)        // 程序设计成绩 Programming grade
	, math(0)           // 数学成绩 Math grade
	, lishan(0)         // 力学成绩 Mechanics grade
{
	FA = FALSE; // 初始化标志 Initialization flag
}

myadd::~myadd()
{
}

void myadd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);      // 绑定编辑框与变量 Bind edit box with variable
	DDX_Text(pDX, IDC_EDIT3, grade);
	DDX_Text(pDX, IDC_EDIT2, classs);
	DDX_Radio(pDX, IDC_RADIO1, xing);
	DDX_Text(pDX, IDC_EDIT4, number);
	DDX_Text(pDX, IDC_EDIT5, program);
	DDX_Text(pDX, IDC_EDIT6, math);
	DDX_Text(pDX, IDC_EDIT7, lishan);
}

BEGIN_MESSAGE_MAP(myadd, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &myadd::OnBnClickedCancel) // 取消按钮 Cancel button
	ON_BN_CLICKED(IDC_OK, &myadd::OnBnClickedOk)      // 确认按钮 OK button
	ON_WM_PAINT()                                     // 绘制背景 Paint background
	ON_EN_CHANGE(IDC_EDIT1, &myadd::OnEnChangeEdit1)  // 编辑框内容改变处理 Edit box content change handler
END_MESSAGE_MAP()


// myadd 消息处理程序 Message handlers

void myadd::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码 Add control notification handler code here
	FA = TRUE; // 设置标志 Set flag
	CDialogEx::OnCancel(); // 调用父类取消函数 Call parent class cancel function
}

BOOL myadd::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 初始化数据 Initialization
	name = "";
	grade = "";
	classs = "";
	number = 0;
	xing = 0;
	program = 0;
	math = 0;
	lishan = 0;

	// 设置焦点到第一个输入框 Set focus to the first input field
	GetDlgItem(IDC_EDIT1)->SetFocus();

	// TODO: 在此添加额外的初始化代码 Add additional initialization code here

	return TRUE;  // 返回 TRUE，除非将焦点设置到控件 Return TRUE unless focus is set to a control
	// 异常: OCX 属性页应返回 FALSE Exception: OCX property pages should return FALSE
}

void myadd::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码 Add control notification handler code here
	CDialogEx::OnOK();
}

void myadd::OnPaint()
{
	// 自定义背景绘制 Custom background drawing
	CPaintDC dc(this); // 绘图上下文 Drawing context
	CRect rect;
	GetClientRect(&rect); // 获取客户区大小 Get client area size
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc); // 创建兼容 DC Create compatible DC
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP2); // 加载背景图片 Load background image
	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap* pbmpOld = dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

	// TODO: 在此处添加消息处理程序代码 Add message handler code here
	// 不为绘图消息调用 CDialogEx::OnPaint() Do not call CDialogEx::OnPaint() for painting messages
}

void myadd::OnEnChangeEdit1()
{
	// TODO: 如果该控件是 RICHEDIT 控件，它将不发送此通知，
	// 除非重写 CDialogEx::OnInitDialog() 函数并调用
	// CRichEditCtrl().SetEventMask()，同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// If this is a RICHEDIT control, it will not send this notification
	// unless you override CDialogEx::OnInitDialog() and call
	// CRichEditCtrl().SetEventMask(), with the ENM_CHANGE flag ORed into the mask.

	// TODO: 在此添加控件通知处理程序代码 Add control notification handler code here
}
