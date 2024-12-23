// kedaimport.cpp: Implementation file 实现文件
//

#include "stdafx.h"
#include "managementSystem.h"
#include "myimport.h"
#include "afxdialogex.h"

// myimport 对话框 Dialog

IMPLEMENT_DYNAMIC(myimport, CDialogEx)

myimport::myimport(CWnd* pParent /*=nullptr*/)
	: CDialogEx(import, pParent)
{
	FA = FALSE; // 初始化标志 Initialization flag
}

myimport::~myimport()
{
}

void myimport::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(myimport, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &myimport::OnBnClickedButton1) // 确认按钮事件处理 Confirm button handler
	ON_BN_CLICKED(IDC_BUTTON2, &myimport::OnBnClickedButton2) // 导入按钮事件处理 Import button handler
	ON_BN_CLICKED(IDCANCEL, &myimport::OnBnClickedCancel)     // 取消按钮事件处理 Cancel button handler
	ON_WM_PAINT()                                            // 背景绘制 Paint handler
END_MESSAGE_MAP()

// myimport 消息处理程序 Message handlers

void myimport::OnBnClickedButton1()
{
	// 确认操作 Confirm operation
	FA = TRUE; // 设置标志 Set flag
	CDialogEx::OnOK();
	// TODO: 在此添加控件通知处理程序代码 Add control notification handler code here
}

void myimport::OnBnClickedButton2()
{
	// 执行导入操作 Perform import operation
	CDialogEx::OnOK();
	// TODO: 在此添加控件通知处理程序代码 Add control notification handler code here
}

void myimport::OnBnClickedCancel()
{
	// 取消操作 Cancel operation
	CDialogEx::OnCancel();
	// TODO: 在此添加控件通知处理程序代码 Add control notification handler code here
}

void myimport::OnPaint()
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

	// TODO: 在此处添加消息处理程序代码 Add control notification handler code here
	// 不为绘图消息调用 CDialogEx::OnPaint() Do not call CDialogEx::OnPaint() for painting messages
}
