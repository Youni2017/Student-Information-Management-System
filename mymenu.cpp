// kedamenu.cpp: 实现文件 Implementation file
//

#include "stdafx.h"
#include "managementSystem.h"
#include "mymenu.h"
#include "afxdialogex.h"
#include "managementSystemdlg.h"
#include <algorithm> // 引入快排 Import quicksort

using namespace std;

// kedamenu 对话框 Dialog

IMPLEMENT_DYNAMIC(mymenu, CDialogEx)

mymenu::mymenu(CWnd* pParent /*=nullptr*/)
	: CDialogEx(menu, pParent)
	, m_stusum(0) // 初始化学生总数 Initialize total students
{
	m_index = 0;    // 当前列索引 Current column index
	m_line = 0;     // 当前行数 Current row count
	m_indexmax = 8; // 最大列数 Maximum column count
	judge = FALSE;  // 判断标志 Flag for conditions
	check = TRUE;   // 检查标志 Validation flag
	filename = "";  // 文件路径 File path
}

mymenu::~mymenu()
{
}

void mymenu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_list); // 绑定列表控件 Bind list control
	DDX_Text(pDX, IDC_EDIT1, m_stusum); // 绑定学生总数 Bind total students
}

BEGIN_MESSAGE_MAP(mymenu, CDialogEx)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &mymenu::OnLvnItemchangedList2)
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON1, &mymenu::OnBnClickedButton1) // 添加按钮 Add button
	ON_BN_CLICKED(IDC_BUTTON2, &mymenu::OnBnClickedButton2) // 删除按钮 Delete button
	ON_BN_CLICKED(IDC_BUTTON3, &mymenu::OnBnClickedButton3) // 保存按钮 Save button
	ON_BN_CLICKED(IDC_BUTTON4, &mymenu::OnBnClickedButton4) // 查找按钮 Search button
	ON_BN_CLICKED(IDC_BUTTON5, &mymenu::OnBnClickedButton5) // 导入按钮 Import button
	ON_BN_CLICKED(IDC_BUTTON6, &mymenu::OnBnClickedButton6) // 修改按钮 Modify button
	ON_BN_CLICKED(IDC_BUTTON7, &mymenu::OnBnClickedButton7) // 排序按钮 Sort button
	ON_BN_CLICKED(IDC_BUTTON8, &mymenu::OnBnClickedButton8) // 退出按钮 Exit button
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, &mymenu::OnDblclkList2) // 双击响应 Double-click response
	ON_EN_KILLFOCUS(IDC_EDIT2, &mymenu::OnKillfocusEdit2)   // 失去焦点响应 Lost focus response
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST2, &mymenu::OnCustomdrawList2) // 自定义绘制 Custom draw
END_MESSAGE_MAP()

// kedamenu 消息处理程序 Message handlers

void mymenu::OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码 Add your control notification handler code here
	*pResult = 0;
}

BOOL mymenu::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 添加额外的初始化 Add additional initialization
	CString str = "学生成绩管理系统           用户：youni";
	SetWindowText(str);

	// 设置表格的风格 Set table style
	CRect rect;
	CListCtrl* pmyListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST2);

	// 设置报表模式 Set report mode
	LONG dwStyle = GetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE);
	SetWindowLong(pmyListCtrl->m_hWnd, GWL_STYLE, dwStyle | LVS_REPORT);

	// 设置整行选择和网格线风格 Set full row select and gridline style
	LONG styles = pmyListCtrl->GetExtendedStyle();
	pmyListCtrl->SetExtendedStyle(styles | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_NOSCROLL);

	// 设置列 Set columns
	m_list.InsertColumn(0, "学号", LVCFMT_CENTER, 100); // Student ID
	m_list.InsertColumn(1, "学号", LVCFMT_CENTER, 100);
	m_list.InsertColumn(2, "姓名", LVCFMT_CENTER, 70); // Name
	m_list.InsertColumn(3, "性别", LVCFMT_CENTER, 70); // Gender
	m_list.InsertColumn(4, "年级", LVCFMT_CENTER, 70); // Grade
	m_list.InsertColumn(5, "班别", LVCFMT_CENTER, 70); // Class
	m_list.InsertColumn(6, "c++程序设计", LVCFMT_CENTER, 90); // Programming
	m_list.InsertColumn(7, "高等数学", LVCFMT_CENTER, 90);    // Math
	m_list.InsertColumn(8, "大学物理", LVCFMT_CENTER, 90);    // Physics
	m_list.DeleteColumn(0); // 删除第一列 Delete the first column

	importt(); // 导入文件数据 Import file data
	m_stusum = m_line; // 更新学生总数 Update student count
	UpdateData(FALSE); // 更新控件显示 Update control display
	GetDlgItem(IDC_EDIT1)->EnableWindow(FALSE);

	return TRUE; // Return TRUE unless you set the focus to a control
}

// ————————————————————————————————关键，多个控件会用到它！———————————————————————————————
// Essential function used by multiple controls

BOOL mymenu::nodata() // 判断列表中是否有数据 Check if the list contains data
{
	if (m_list.GetItemText(0, 0) != "")
	{
		return TRUE;
	}
	return FALSE;
}

// ——————————————————————————————————添加功能 Add Functionality————————————————————————————————

BOOL mymenu::empty() // 判定数据是否存在没填的 Check if any data fields are empty
{
	if (adds.name == "" || adds.grade == "" || adds.classs == "" || adds.number == 0)
	{
		MessageBox("数据框有空,请填写"); // Some fields are empty, please fill in
		return FALSE;
	}
	return TRUE;
}

BOOL mymenu::checkgrade() // 检查分数是否在规定范围以内 Check if scores are within the valid range
{
	if (adds.program > 100 || adds.math > 100 || adds.lishan > 100)
	{
		MessageBox("分数大于指定最大分数"); // Scores exceed the maximum allowed
		return FALSE;
	}
	return TRUE;
}

BOOL mymenu::checknumber(char(&c)[15]) // 检测学号是否相等 Check if student numbers are unique
{
	_itoa_s(adds.number, c, 10);
	for (UINT i = 0; i < m_line; i++)
	{
		CString ID;
		ID += c;
		if (ID == m_list.GetItemText(i, 0))
		{
			char cid[100];
			_itoa_s(i + 1, cid, 10);
			CString s = "学号与第"; // Student number matches with
			s += cid;
			s += "个同学相同，请重新输入"; // another student, please re-enter
			MessageBox(s);
			return FALSE;
		}
	}
	return TRUE;
}

BOOL mymenu::checkxingbie() // 检查是否已选性别 Check if gender is selected
{
	if (adds.xing == 0)
	{
		adds.m_set = "男"; // Male
		return TRUE;
	}
	else if (adds.xing == 1)
	{
		adds.m_set = "女"; // Female
		return TRUE;
	}
	else
	{
		MessageBox("请选择性别"); // Please select gender
		return FALSE;
	}
}

void mymenu::OnBnClickedButton1() // 将数据加载至列表框 Add data to list box
{
	while (1)
	{
		adds.xing = -1;

		if (adds.DoModal() == IDOK && empty() && adds.FA == FALSE && checkgrade())
		{
			char c[15];

			if (checknumber(c) && checkxingbie())
			{
				char c1[5], c2[5], c3[5];
				_itoa_s(adds.program, c1, 10); // 将分数转为字符串 Convert scores to string
				_itoa_s(adds.math, c2, 10);
				_itoa_s(adds.lishan, c3, 10);

				// 插入新数据 Insert new data
				m_list.InsertItem(0, c);
				m_list.SetItemText(0, ++m_index, adds.name);
				m_list.SetItemText(0, ++m_index, adds.m_set);
				m_list.SetItemText(0, ++m_index, adds.grade);
				m_list.SetItemText(0, ++m_index, adds.classs);
				m_list.SetItemText(0, ++m_index, c1);
				m_list.SetItemText(0, ++m_index, c2);
				m_list.SetItemText(0, ++m_index, c3);

				m_line++; // 更新行数 Update row count
				m_stusum = m_line;
				UpdateData(FALSE);
				m_index = 0;

				// 重置字段 Reset fields
				adds.name = "";
				adds.grade = "";
				adds.classs = "";
				adds.number = 0;
				adds.program = 0;
				adds.math = 0;
				adds.lishan = 0;
			}
		}
		if (adds.FA == TRUE)
		{
			adds.FA = FALSE;
			break;
		}
	}
}
// ——————————————————————————————————删除功能 Delete Functionality————————————————————————————————

void mymenu::deletenull() // 删除列表框的所有数据 Delete all data in the list box
{
	m_list.DeleteAllItems(); // 删除所有项 Delete all items
	m_line = 0; // 行数清零 Reset line count
	m_stusum = m_line;
	UpdateData(FALSE); // 更新控件显示 Update controls
}

void mymenu::delete_q() // 删除单个数据+调用上面函数删除所有数据 Delete individual data + call deletenull for complete deletion
{
	if (deletes.a == 0 && deletes.b != "") // 按姓名查找删除 Search by name
	{
		for (UINT i = 0; i < m_line; i++)
		{
			CString s = m_list.GetItemText(i, 1); // 获取第i行第1列的内容 Get content from row i, column 1
			if (deletes.b == s)
			{
				m_list.DeleteItem(i); // 删除该行 Delete this row
				m_line--; // 行数减少 Decrease line count
				deletes.b = ""; // 清除查找条件 Clear search condition
				judge = TRUE;
				m_stusum = m_line;
				UpdateData(FALSE);
				MessageBox("删除成功"); // Deletion successful
				break;
			}
		}
		if (judge == FALSE)
			MessageBox("没有此名字的学生"); // No student found with this name
	}
	else if (deletes.a == 1 && deletes.b != "") // 按学号查找删除 Search by student ID
	{
		for (UINT i = 0; i < m_line; i++)
		{
			CString s = m_list.GetItemText(i, 0); // 获取第i行第0列的内容 Get content from row i, column 0
			if (deletes.b == s)
			{
				m_list.DeleteItem(i); // 删除该行 Delete this row
				m_line--;
				deletes.b = "";
				judge = TRUE;
				m_stusum = m_line;
				UpdateData(FALSE);
				MessageBox("删除成功"); // Deletion successful
				break;
			}
		}
		if (judge == FALSE)
			MessageBox("没有此学号的学生"); // No student found with this ID
	}
	else if (deletes.a == 2) // 全部删除 Delete all
	{
		deletenull();
	}
	else
	{
		MessageBox("请输入一项数据删除"); // Please enter data to delete
	}
}

void mymenu::OnBnClickedButton2() // 删除按钮响应 Delete button response
{
	if (!nodata())
	{
		MessageBox("列表中没有数据~"); // No data in the list
	}
	while (nodata())
	{
		if (deletes.DoModal() == IDOK)
		{
			delete_q();
		}
		if (deletes.FA == TRUE || !nodata())
		{
			deletes.FA = FALSE;
			break;
		}
	}
}

// ——————————————————————————————————保存功能 Save Functionality————————————————————————————————

void mymenu::OnBnClickedButton3()
{
	BOOL jdg = FALSE;

	CFileDialog filesaves(FALSE); // FALSE表示另存为对话框 FALSE indicates Save As dialog
	filesaves.m_ofn.lpstrTitle = "选择文件并保存"; // Dialog title
	filesaves.m_ofn.lpstrFilter = "TXT文件(*.txt)\0*.txt\0doc文档(*.doc)\0*.doc\0所有文件(*.*)\0*.*\0\0"; // File types
	if (filesaves.DoModal() == IDOK) // 如果按下保存按钮 If Save button is clicked
	{
		filename = filesaves.GetPathName(); // 获取文件路径 Get file path
	}

	if (nodata()) // 检查列表是否有数据 Check if there is data in the list
	{
		CFile file;
		file.Open(filename, CFile::modeWrite | CFile::modeCreate); // 打开文件 Open file in write mode

		CString header[] = { "学号\t", "姓名\t", "性别\t", "年级\t", "班别\t", "程序设计\t", "高等数学\t", "大学物理\t\r\n" };
		for (auto& col : header)
			file.Write(col, col.GetLength()); // 写入列名 Write column headers

		for (UINT i = 0; i < m_line; i++)
		{
			for (UINT j = 0; j <= m_indexmax; j++)
			{
				CString s = m_list.GetItemText(i, j);
				file.Write(s, s.GetLength()); // 写入每行内容 Write row content
				if (j < m_indexmax)
					file.Write("\t", 1); // 用制表符分隔 Use tab to separate
			}
			file.Write("\r\n", 2); // 换行符 End of line
		}
		file.Close();
		MessageBox("数据保存成功"); // Data saved successfully
	}
	else
	{
		MessageBox("列表中没有数据，请先添加"); // No data in the list, please add first
	}
}

// ——————————————————————————————————查找功能 Search Functionality————————————————————————————————

void mymenu::reset(UINT i) // 将查找的学生信息移动到第一行 Move searched student info to the first row
{
	CString data[8];
	for (int j = 0; j <= m_indexmax; j++)
		data[j] = m_list.GetItemText(i, j);

	m_list.DeleteItem(i); // 删除原位置数据 Delete data from original position
	m_list.InsertItem(0, data[0]); // 插入到第一行 Insert to the first row
	for (int j = 1; j <= m_indexmax; j++)
		m_list.SetItemText(0, j, data[j]); // 设置其他列内容 Set other columns
}

void mymenu::find_q() // 查找功能 Search functionality
{
	if (finds.a == 0 && finds.b != "") // 按姓名查找 Search by name
	{
		for (UINT i = 0; i < m_line; i++)
		{
			CString s = m_list.GetItemText(i, 1);
			if (finds.b == s)
			{
				reset(i);
				finds.b = "";
				judge = TRUE;
				MessageBox("查找成功"); // Search successful
				break;
			}
		}
		if (!judge)
			MessageBox("没有找到该姓名的学生"); // No student found with this name
	}
	else if (finds.a == 1 && finds.b != "") // 按学号查找 Search by ID
	{
		for (UINT i = 0; i < m_line; i++)
		{
			CString s = m_list.GetItemText(i, 0);
			if (finds.b == s)
			{
				reset(i);
				finds.b = "";
				judge = TRUE;
				MessageBox("查找成功"); // Search successful
				break;
			}
		}
		if (!judge)
			MessageBox("没有找到该学号的学生"); // No student found with this ID
	}
	else
	{
		MessageBox("请输入搜索条件"); // Please enter search criteria
	}
}

void mymenu::OnBnClickedButton4() // 查找按钮响应 Search button response
{
	if (!nodata())
	{
		MessageBox("列表中没有数据~"); // No data in the list
	}
	while (nodata())
	{
		if (finds.DoModal() == IDOK)
		{
			find_q();
		}
		if (finds.FA == TRUE)
		{
			finds.FA = FALSE;
			break;
		}
	}
}
// ——————————————————————————————————导入功能 Import Functionality————————————————————————————————

void mymenu::OnBnClickedButton5() // 导入按钮响应 Import button response
{
	myimport dlg; // 导入对话框 Import dialog
	if (dlg.DoModal() == IDOK && dlg.FA == FALSE)
	{
		importtt(); // 导入函数 Import function
	}
	else if (dlg.FA == TRUE)
	{
		dlg.FA = FALSE;
		int line = m_list.GetItemCount();
		for (int i = 0; i < line; i++)
		{
			m_list.DeleteItem(0); // 删除当前列表内容 Delete current list content
			m_line--;
		}
		m_stusum = m_line;
		UpdateData(FALSE);
		importtt();
	}
}

void mymenu::importtt() // 获取需要导入的学生信息文件的地址 Get file address for importing student data
{
	MessageBox("请导入学生信息!"); // Prompt user to import student data
	CFileDialog filedlg(TRUE); // 打开文件对话框 Open file dialog
	filedlg.m_ofn.lpstrTitle = "请选择文件并导入"; // Title for the dialog
	filedlg.m_ofn.lpstrFilter = "TXT文件(*.txt)\0*.txt\0doc文档(*.doc)\0*.doc\0所有文件(*.*)\0*.*\0\0"; // Supported file formats
	if (IDOK == filedlg.DoModal()) // If file is selected
	{
		finds.filenaem = filedlg.GetPathName(); // Get file path
		UINT num = importt();
		if (num != 0)
			MessageBox("导入信息成功"); // Import successful
	}
}

UINT mymenu::importt() // 导入文件内容并填充列表框 Import file content and populate list box
{
	BOOL jdg = FALSE;
	CFile file1;
	file1.Open(finds.filenaem, file1.modeRead); // 打开文件 Open file for reading
	CString s;
	static int num = 0;
	UINT index = 0;
	for (int i = 0; i < file1.GetLength(); i++) // 遍历文件内容 Iterate through file content
	{
		char c[1];
		file1.Read(c, 1); // 逐字节读取 Read byte by byte
		if (s.Right(1) != "\t")
		{
			s += c[0];
		}
		else
		{
			if (s != "学号\t" && s != "姓名\t" && s != "性别\t" && s != "年级\t" && s != "班别\t" && s != "程序设计\t" && s != "高等数学\t" && s != "大学物理\t")
			{
				if (index > m_indexmax)
				{
					index = 0;
					m_line++;
				}
				if (index != 0)
				{
					m_list.SetItemText(m_line, index, s.Left(strlen(s) - 1));
					jdg = TRUE;
					index++;
				}
				else
				{
					if (m_line == 0)
					{
						s = s.Left(strlen(s) - 1);
						s = s.Right(strlen(s) - 1);
						m_list.InsertItem(m_line, s);
					}
					else
					{
						s = s.Left(strlen(s) - 1);
						s = s.Right(strlen(s) - 1);
						m_list.InsertItem(m_line, s);
					}
					index++;
				}
			}
			s = "";
			num = 1;
		}
	}
	file1.Close();
	if (jdg)
		m_line++;
	m_stusum = m_line;
	UpdateData(FALSE);
	return num;
}

// ——————————————————————————————————修改功能 Modify Functionality————————————————————————————————

BOOL mymenu::checknum() // 检查成绩是否超出范围 Check if scores are out of range
{
	if (changes.new_program > 100 || changes.new_math > 100 || changes.new_lishan > 100)
	{
		MessageBox("成绩输入不合法"); // Invalid score input
		return FALSE;
	}
	return TRUE;
}

void mymenu::settext(int line) // 将新的信息更新到列表框 Update new information in the list box
{
	char c[20] = "0";
	char c1[5], c2[5], c3[5];
	_itoa_s(changes.new_program, c1, 10);
	_itoa_s(changes.new_math, c2, 10);
	_itoa_s(changes.new_lishan, c3, 10);
	if (changes.new_number != 0)
	{
		_itoa_s(changes.new_number, c, 10);
		m_list.SetItemText(line, 0, c);
	}
	if (changes.new_grade != "")
		m_list.SetItemText(line, 3, changes.new_grade);
	if (changes.new_class != "")
		m_list.SetItemText(line, 4, changes.new_class);
	if (checknum())
	{
		m_list.SetItemText(line, 5, c1);
		m_list.SetItemText(line, 6, c2);
		m_list.SetItemText(line, 7, c3);
	}
}

void mymenu::findcheck() // 根据名字查找并更新学生信息 Find and update student information by name
{
	BOOL f = FALSE;
	if (changes.name != "")
	{
		for (UINT i = 0; i < m_line; i++)
		{
			if (changes.name == m_list.GetItemText(i, 1))
			{
				settext(i);
				f = TRUE;
			}
			if (f)
			{
				MessageBox("成功修改"); // Modification successful
				break;
			}
		}
		if (!f)
		{
			MessageBox("查找的人名字可能不符,请检查"); // Name mismatch, please check
		}
	}
	else
	{
		MessageBox("请输入修改同学的新旧姓名"); // Please enter the old and new names for modification
	}
}

void mymenu::changename() // 修改名字 Modify name only
{
	BOOL f = FALSE;
	for (UINT i = 0; i < m_line; i++)
	{
		if (changes.old_name == m_list.GetItemText(i, 1))
		{
			m_list.SetItemText(i, 1, changes.new_name);
			f = TRUE;
		}
		if (f)
		{
			MessageBox("成功修改"); // Modification successful
			break;
		}
	}
}

void mymenu::OnBnClickedButton6() // 修改按钮响应 Modify button response
{
	while (nodata())
	{
		changes.old_name = "";
		changes.new_name = "";
		changes.new_number = 0;
		changes.new_program = 0;
		changes.new_math = 0;
		changes.new_lishan = 0;
		changes.new_class = "";
		changes.new_grade = "";

		if (changes.DoModal() == IDOK)
		{
			UpdateData(TRUE);
			if (changes.cao == 0 && changes.old_name != "")
			{
				changename();
			}
			else if (changes.cao == 1 && changes.name != "")
			{
				findcheck();
			}
			else
			{
				MessageBox("请输入该学生的姓名"); // Please enter the student's name
			}
		}
		if (changes.FA == TRUE)
		{
			deletes.FA = FALSE;
			break;
		}
	}
	if (!nodata())
	{
		MessageBox("信息为空,请先添加信息"); // No data available, please add information first
	}
}

// ——————————————————————————————————排序功能 Sort Functionality————————————————————————————————

BOOL cmp(point pt1, point pt2) // 快速排序的比较函数 Comparison function for quicksort
{
	return pt1.y < pt2.y;
}

void mymenu::resort() // 排序函数 Sorting function
{
	point* keda = new point[m_line]; // 动态数组存储当前列表内容 Dynamic array to store list content

	for (UINT i = 0; i < m_line; i++)
	{
		CString a = m_list.GetItemText(i, 0);
		UINT AA = _ttoi(a); // 将字符串转为整数 Convert string to integer
		keda[i].x = i;      // 存储行数 Store row number
		keda[i].y = AA;     // 存储学号 Store student ID
	}
	sort(keda, keda + m_line, cmp); // 使用快排 Sort using quicksort

	for (int i = 0; i < m_line; i++)
	{
		CString a = m_list.GetItemText(keda[i].x, 0);
		m_list.InsertItem(i + m_line, a); // 插入新位置 Insert at new position
		for (UINT j = 1; j < 8; j++)
		{
			CString a = m_list.GetItemText(keda[i].x, j);
			m_list.SetItemText(i + m_line, j, a);
		}
	}
	for (int i = 0; i < m_line; i++) // 删除旧数据 Delete old data
	{
		m_list.DeleteItem(0);
	}
	delete[] keda; // 防止内存泄漏 Prevent memory leak
}

void mymenu::OnBnClickedButton7() // 排序按钮响应 Sort button response
{
	if (!nodata())
	{
		MessageBox("信息为空,请先添加信息"); // No data available, please add first
	}
	else
		resort();
}
// ——————————————————————————————————退出功能 Exit Functionality————————————————————————————————

void mymenu::OnBnClickedButton8() // 退出按钮响应 Exit button response
{
	if (MessageBox("请确认保存学生信息再退出！", "警告", MB_ICONEXCLAMATION | MB_OKCANCEL) == IDCANCEL)
	{
		CDialog::OnClose(); // 如果取消，保持窗口打开 If canceled, keep the dialog open
	}
	else
	{
		CDialogEx::OnCancel(); // 否则退出 Otherwise, exit the dialog
	}
}

// ——————————————————————————————————背景图片设置 Background Image Setup————————————————————————————————

void mymenu::OnPaint() // 设置背景 Set background image
{
	CPaintDC dc(this); // 绘图设备上下文 Drawing device context
	CRect rect;
	GetClientRect(&rect);
	CDC dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP2); // 加载背景图片 Load background image
	BITMAP bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap* pbmpOld = dcMem.SelectObject(&bmpBackground);

	// 将背景图片拉伸至窗口大小 Stretch the background image to fit the window
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

	// 不为绘图消息调用父类 OnPaint() Don't call parent class OnPaint for paint messages
}

// —————————————————————————双击列表框数据修改功能 Edit on Double-Click————————————————————————

void mymenu::OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult) // 双击列表项响应 Double-click response
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	CRect rc;
	m_Row = pNMListView->iItem; // 获取点击行 Get the clicked row
	m_Col = pNMListView->iSubItem; // 获取点击列 Get the clicked column

	if (pNMListView->iSubItem != -1)
	{
		m_list.GetSubItemRect(m_Row, m_Col, LVIR_LABEL, rc); // 获取单元格的矩形区域 Get the rectangle of the cell
		m_edit.SetParent(&m_list); // 设置父窗口为列表框 Set parent window to the list box
		m_edit.MoveWindow(rc); // 将编辑框移动到单元格位置 Move the edit box to the cell position
		m_edit.SetWindowText(m_list.GetItemText(m_Row, m_Col)); // 设置当前单元格的文本 Set the current cell's text
		m_edit.ShowWindow(SW_SHOW); // 显示编辑框 Show the edit box
		m_edit.SetFocus();
		m_edit.ShowCaret();
		m_edit.SetSel(-1);
	}
	*pResult = 0;
}

void mymenu::OnKillfocusEdit2() // 当编辑框失去焦点时保存数据 Save data when edit box loses focus
{
	CString tem;
	m_edit.GetWindowText(tem); // 获取编辑框内容 Get the content of the edit box
	m_list.SetItemText(m_Row, m_Col, tem); // 将内容写入列表框 Write the content into the list box
	m_edit.ShowWindow(SW_HIDE); // 隐藏编辑框 Hide the edit box
}

// —————————————————————————————————防止意外退出功能 Prevent Accidental Exits————————————————————————————————

void mymenu::OnOK() // 重载 OnOK 阻止回车键意外关闭窗口 Override OnOK to prevent accidental exits
{
	// 空函数，什么也不做 Empty function, does nothing
}

// —————————————————————————列表框自定义绘制功能 Custom Draw for List Box————————————————————————

void mymenu::OnCustomdrawList2(NMHDR* pNMHDR, LRESULT* pResult) // 列表框自定义绘制 Custom drawing for list box
{
	LPNMTVCUSTOMDRAW pNMCD = reinterpret_cast<LPNMTVCUSTOMDRAW>(pNMHDR);
	NMCUSTOMDRAW nmCustomDraw = pNMCD->nmcd;
	switch (nmCustomDraw.dwDrawStage)
	{
	case CDDS_ITEMPREPAINT: // 在每个项绘制前的阶段 Before each item's drawing
	{
		if (COLOR_RED == nmCustomDraw.lItemlParam) // 设置红色背景 Set red background
		{
			pNMCD->clrTextBk = RGB(255, 0, 0); // 背景颜色 Background color
			pNMCD->clrText = RGB(255, 255, 255); // 文本颜色 Text color
		}
		else if (COLOR_DEFAULT == nmCustomDraw.lItemlParam) // 默认颜色 Default color
		{
			pNMCD->clrTextBk = RGB(255, 255, 255);
			pNMCD->clrText = RGB(0, 0, 0);
		}
		break;
	}
	default:
		break;
	}
	*pResult = 0;
	*pResult |= CDRF_NOTIFYPOSTPAINT;
	*pResult |= CDRF_NOTIFYITEMDRAW;
}
