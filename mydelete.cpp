// kedadelete.cpp: Implementation file 实现文件
//

#include "stdafx.h"
#include "managementSystem.h"
#include "mydelete.h"
#include "afxdialogex.h"

// mydelete 对话框 Dialog

IMPLEMENT_DYNAMIC(mydelete, CDialogEx)

mydelete::mydelete(CWnd* pParent /*=nullptr*/)
	: CDialogEx(delete_, pParent)
	, b(_T(""))  // 删除目标 Delete target
	, a(0)       // 操作选项 Operation option
{
	FA = FALSE; // 初始化标志 Initialization flag
}

mydelete::~mydelete()
{
}

void mydelete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, b);    // 绑定编辑框与变量 Bind edit box to variable
	DDX_Radio(pDX, IDC_RADIO1, a); // 绑定单选按钮与变量 Bind radio button to variable
}

BEGIN_MESSAGE_MAP(mydelete, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &mydelete::OnBnClickedButton2) // 确认按钮事件处理 Confirm button handler
	ON_BN_CLICKED(IDCANCEL, &mydelete::OnBnClickedCancel)    // 取消按钮事件处理 Cancel button handler
	ON_WM_PAINT()                                            // 背景绘制 Paint handler
END_MESSAGE_MAP()

// mydelete 消息处理程序 Message handlers

void mydelete::OnBnClickedButton2()
{
	// 确认删除 Confirm delete
	CDialogEx::OnOK(); // TODO: 在此添加控件通知处理程序代码 Add control notification handler code here
}

void mydelete::OnBnClickedCancel()
{
	// 取消操作 Cancel operation
	FA = TRUE; // 设置标志 Set flag
	// TODO: 在此添加控件通知处理程序代码 Add control notification handler code here
	CDialogEx::OnCancel();
}

void mydelete::OnPaint()
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
