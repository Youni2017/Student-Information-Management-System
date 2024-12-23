// kedafinds.cpp: Implementation file 实现文件
//

#include "stdafx.h"
#include "managementSystem.h"
#include "myfinds.h"
#include "afxdialogex.h"

// myfinds 对话框 Dialog

IMPLEMENT_DYNAMIC(myfinds, CDialogEx)

myfinds::myfinds(CWnd* pParent /*=nullptr*/)
	: CDialogEx(find_s, pParent)
	, a(0)            // 查找方式 Find method
	, b(_T(""))       // 查找内容 Search content
{
	FA = FALSE; // 初始化标志 Initialization flag
}

myfinds::~myfinds()
{
}

void myfinds::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, b);    // 绑定编辑框与变量 Bind edit box with variable
	DDX_Radio(pDX, IDC_RADIO1, a); // 绑定单选按钮与变量 Bind radio button with variable
}

BEGIN_MESSAGE_MAP(myfinds, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &myfinds::OnBnClickedButton1) // 确认按钮事件处理 Confirm button handler
	ON_BN_CLICKED(IDCANCEL, &myfinds::OnBnClickedCancel)    // 取消按钮事件处理 Cancel button handler
	ON_WM_PAINT()                                           // 背景绘制 Paint handler
END_MESSAGE_MAP()

// myfinds 消息处理程序 Message handlers

void myfinds::OnBnClickedButton1()
{
	// 确认查找 Confirm search
	CDialogEx::OnOK(); // TODO: 在此添加控件通知处理程序代码 Add control notification handler code here
}

void myfinds::OnBnClickedCancel()
{
	// 取消操作 Cancel operation
	FA = TRUE; // 设置标志 Set flag
	// TODO: 在此添加控件通知处理程序代码 Add control notification handler code here
	CDialogEx::OnCancel();
}

void myfinds::OnPaint()
{
	// 自定义背景绘制 Custom background drawing
	CPaintDC dc(this); // 绘图上下文 Device context for drawing
	CRect rect;
	GetClientRect(&rect); // 获取客户区尺寸 Get client area dimensions
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc); // 创建兼容的 DC Create compatible DC
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP2); // 加载背景图片 Load background image
	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap* pbmpOld = dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

	// TODO: 在此处添加消息处理程序代码 Add message handler code here
	// 不为绘图消息调用 CDialogEx::OnPaint() Do not call CDialogEx::OnPaint() for painting messages
}
