// managementSystemDlg.cpp: Implementation file 实现文件
//

#include "stdafx.h"
#include "managementSystem.h"
#include "managementSystemDlg.h"
#include "afxdialogex.h"
#include "mymenu.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
// Dialog for the "About" menu item in the application.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据 Dialog data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持 DDX/DDV support

	// 实现 Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmanagementSystemDlg 对话框 Dialog

CmanagementSystemDlg::CmanagementSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_WUJIEKD_DIALOG, pParent)
	, zhanghao(_T(""))  // 账户账号
	, mima(_T(""))      // 密码
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmanagementSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, zhanghao);
	DDX_Text(pDX, IDC_EDIT1, mima);
}

BEGIN_MESSAGE_MAP(CmanagementSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CmanagementSystemDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT2, &CmanagementSystemDlg::OnEnChangeEdit2)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CmanagementSystemDlg 消息处理程序 Message Handlers

BOOL CmanagementSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	// Add the "About..." menu item to the system menu.

	// IDM_ABOUTBOX 必须在系统命令范围内。
	// IDM_ABOUTBOX must be within the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。
	// Set the icon for this dialog. When the main window is not a dialog, the framework does this automatically.
	SetIcon(m_hIcon, TRUE);			// 设置大图标 Set large icon
	SetIcon(m_hIcon, FALSE);		// 设置小图标 Set small icon

	// TODO: 在此添加额外的初始化代码 Add additional initialization code here
	SetWindowText("学生成绩管理系统"); // 设置窗口标题
	SetDlgItemText(IDC_EDIT2, "输入账户"); // 设置账号输入框默认提示
	SetDlgItemText(IDC_EDIT1, "输入密码"); // 设置密码输入框默认提示

	return FALSE;  // 返回 FALSE 以便退出对话框 Return FALSE to exit the dialog
}

void CmanagementSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码来绘制图标。
// If the dialog has a minimize button, this code is needed to draw the icon.

void CmanagementSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文 Device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中 Center the icon in the client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标 Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else // 设置背景图 Set the background image
	{
		CPaintDC dc(this);
		CRect rect;
		GetClientRect(&rect);
		CDC dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap bmpBackground;
		bmpBackground.LoadBitmap(IDB_BITMAP1); // 加载背景图片 Load background image
		BITMAP bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap* pbmpOld = dcMem.SelectObject(&bmpBackground);
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
	}
}

// 当用户拖动最小化窗口时系统调用此函数取得光标显示。
// When the user drags the minimized window, the system calls this function to get the cursor to display.
HCURSOR CmanagementSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 按下“确定”按钮事件处理 Press "OK" button event handler
void CmanagementSystemDlg::OnBnClickedOk()
{
	UpdateData(TRUE); // 同步控件数据与变量 Synchronize control data with variables

	CString zhang = zhanghao; // 账户字符串
	CString mi = mima;        // 密码字符串
	if (zhang == "youni" && mi == "123") // 验证账户和密码 Validate account and password
	{
		ShowWindow(SW_HIDE); // 隐藏当前窗口 Hide current window
		mymenu dlgs;         // 创建新窗口类 Create new window class
		dlgs.DoModal();      // 显示对话框 Show dialog
	}
	else if (zhang.IsEmpty() || mi.IsEmpty()) // 检查输入不能为空 Check if inputs are empty
	{
		MessageBox("账号或密码不能为空", "提醒");
		return;
	}
	else // 其他情况显示错误提示 Display error message
	{
		MessageBox("账号或密码错误，还有三次机会~", "提醒");
		return;
	}
	UpdateData(FALSE); // 更新控件显示 Update control display
	CDialogEx::OnOK();
}

// 编辑框内容改变处理函数 Edit box content change handler
void CmanagementSystemDlg::OnEnChangeEdit2()
{
	OnSetFocus((CWnd*)IDC_EDIT2); // 设置焦点 Set focus
}

// 鼠标左键点击事件处理 Mouse left button click event handler
void CmanagementSystemDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDialogEx::OnLButtonDown(nFlags, point);
}

// 预处理消息函数 Pre-process message function
BOOL CmanagementSystemDlg::PreTranslateMessage(MSG* pMsg)
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT1); // 获取密码编辑框控件指针 Get password edit control pointer
	CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2); // 获取账户编辑框控件指针 Get account edit control pointer
	CString s = (CString)"";
	if (pMsg->message == WM_LBUTTONDOWN) // 检测鼠标左键按下事件 Detect left mouse button down event
	{
		UpdateData(TRUE);
		if (pMsg->hwnd == pEdit->GetSafeHwnd()) // 如果指向密码框 If the pointer is at the password box
		{
			pEdit->SetWindowText(_T("")); // 清空输入框 Clear input box
			pEdit->SetPasswordChar('*');  // 设置密码框为星号 Display password as asterisks
		}
		else if (pMsg->hwnd == pEdit2->GetSafeHwnd()) // 如果指向账号框 If the pointer is at the account box
		{
			pEdit2->SetWindowText("");
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
