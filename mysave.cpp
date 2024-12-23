// kedasave.cpp: 实现文件 (Implementation file)
//

#include "stdafx.h"
#include "managementSystem.h"
#include "mysave.h"
#include "afxdialogex.h"


// kedasave 对话框 (Dialog for save functionality)

IMPLEMENT_DYNAMIC(mysave, CDialogEx)

mysave::mysave(CWnd* pParent /*=nullptr*/) // 标准构造函数 (Standard constructor)
	: CDialogEx(save, pParent)
{

}

mysave::~mysave() // 析构函数 (Destructor)
{
}

void mysave::DoDataExchange(CDataExchange* pDX) // 数据交换函数 (Data exchange function)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(mysave, CDialogEx) // 消息映射 (Message map)
	ON_BN_CLICKED(IDC_BUTTON1, &mysave::OnBnClickedButton1) // 保存按钮点击事件 (Save button click event)
	ON_BN_CLICKED(IDCANCEL, &mysave::OnBnClickedCancel)     // 取消按钮点击事件 (Cancel button click event)
END_MESSAGE_MAP()


// kedasave 消息处理程序 (Message handlers)

void mysave::OnBnClickedButton1() // 保存按钮响应 (Save button response)
{
	CDialogEx::OnOK(); // 关闭对话框并返回确认状态 (Close dialog with OK status)
	// TODO: 在此添加控件通知处理程序代码 (Add control notification handler code here)
}


void mysave::OnBnClickedCancel() // 取消按钮响应 (Cancel button response)
{
	// TODO: 在此添加控件通知处理程序代码 (Add control notification handler code here)
	CDialogEx::OnCancel(); // 关闭对话框并返回取消状态 (Close dialog with Cancel status)
}
