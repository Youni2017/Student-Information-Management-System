#pragma once

#include"myadd.h"
#include"mychange.h"
#include"mydelete.h"
#include"mysave.h"
#include"myimport.h"
#include"myfinds.h"
#include"point.h"

using namespace std;

// mymenu 对话框 (Dialog for the main menu interface)

class mymenu : public CDialogEx
{
	DECLARE_DYNAMIC(mymenu)

public:
	mymenu(CWnd* pParent = nullptr);   // 标准构造函数 (Standard constructor)
	virtual ~mymenu();

	// 对话框数据 (Dialog data)
#ifdef AFX_DESIGN_TIME
	enum { IDD = menu };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持 (DDX/DDV support)

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList2(NMHDR* pNMHDR, LRESULT* pResult); // 列表项变化事件响应 (List item change event)
	CListCtrl m_list;                 // 用于显示学生信息的列表控件 (List control to display student info)
	CEdit m_edit;                     // 用于编辑单元格内容的编辑框 (Edit control for cell editing)
	virtual BOOL OnInitDialog();      // 初始化对话框 (Initialize dialog box)
	afx_msg void OnPaint();           // 绘制背景图像 (Paint event for background image)
	afx_msg void OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult); // 双击列表响应事件 (Double-click list item event)
	afx_msg void OnKillfocusEdit2();  // 编辑框失去焦点事件 (Edit box loses focus event)
	virtual void OnOK();              // 禁用回车退出功能 (Override OnOK to disable accidental exits)

	// 按钮点击事件响应函数 (Button click event handler functions)
	afx_msg void OnBnClickedButton1(); // 添加按钮 (Add button)
	afx_msg void OnBnClickedButton2(); // 删除按钮 (Delete button)
	afx_msg void OnBnClickedButton3(); // 保存按钮 (Save button)
	afx_msg void OnBnClickedButton4(); // 查找按钮 (Search button)
	afx_msg void OnBnClickedButton5(); // 导入按钮 (Import button)
	afx_msg void OnBnClickedButton6(); // 修改按钮 (Modify button)
	afx_msg void OnBnClickedButton7(); // 排序按钮 (Sort button)
	afx_msg void OnBnClickedButton8(); // 退出按钮 (Exit button)

	//——————————————————————————以下函数和变量为自己添加！——————————————————————————————————
	// (The following functions and variables are added for custom functionality.)

private:
	myadd  adds;                         // 添加功能的类实例 (Instance for add functionality)
	mychange changes;                    // 修改功能的类实例 (Instance for modify functionality)
	mydelete deletes;                    // 删除功能的类实例 (Instance for delete functionality)
	mysave saves;                        // 保存功能的类实例 (Instance for save functionality)
	myimport imports;                    // 导入功能的类实例 (Instance for import functionality)
	myfinds finds;                       // 查找功能的类实例 (Instance for search functionality)

public:
	// 数据相关变量 (Data-related variables)
	UINT m_line;                 // 列表框的行数 (Number of rows in the list)
	UINT m_index;                // 用于循环计数的索引 (Index for loops)
	UINT m_indexmax;             // 列数，固定为8 (Number of columns, fixed to 8)
	BOOL judge;                  // 判断操作结果的标志 (Flag to judge operation success)
	BOOL check;                  // 数据完整性检查标志 (Flag for data completeness check)
	CString filename;            // 文件名 (Filename for save/load operations)
	UINT m_stusum;               // 学生总数 (Total number of students)
	UINT m_Row;                  // 当前操作的行索引 (Current row index)
	UINT m_Col;                  // 当前操作的列索引 (Current column index)

	// 数据验证函数 (Data validation functions)
	BOOL nodata();               // 判断列表是否为空 (Check if the list is empty)
	BOOL empty();                // 检查是否存在未填写的数据 (Check for incomplete data)
	BOOL checkgrade();           // 检查成绩是否超出范围 (Check if scores are out of range)
	BOOL checknumber(char(&c)[15]); // 检查学号是否重复 (Check if student ID is duplicated)
	BOOL checkxingbie();         // 检查性别是否已选择 (Check if gender is selected)

	// 删除功能函数 (Delete functionality functions)
	void deletenull();           // 删除所有数据 (Delete all data)
	void delete_q();             // 删除单条或多条数据 (Delete one or multiple records)

	// 查找功能函数 (Search functionality functions)
	void find_q();               // 查找学生信息 (Search for student information)
	void reset(UINT a);          // 将查找到的学生移动到列表框第一行 (Move found student to the first row)

	// 导入功能函数 (Import functionality functions)
	void importtt();             // 显示导入对话框并获取文件 (Show import dialog and get file)
	UINT importt();              // 解析并填充导入数据 (Parse and fill imported data)

	// 修改功能函数 (Modify functionality functions)
	void findcheck();            // 根据名字查找并更新学生信息 (Find and update student info by name)
	void settext(int line);      // 更新指定行的学生数据 (Update student data in a specific row)
	BOOL checknum();             // 检查成绩是否超出范围 (Check if scores are valid)
	void changename();           // 修改学生名字 (Modify student name)

	// 排序功能函数 (Sorting functionality functions)
	void resort();               // 排序列表数据 (Sort the list data)

	// 自定义列表项绘制 (Custom list item drawing)
	afx_msg void OnCustomdrawList2(NMHDR* pNMHDR, LRESULT* pResult);
	//afx_msg void OnEnChangeEdit2(); // 编辑事件 (Edit event)
};
