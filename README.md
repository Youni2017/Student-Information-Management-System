# Student Information Management System

This system is designed to manage student information, including adding, deleting, modifying, saving, importing, and finding student details. It features a user-friendly interface with several key functionalities. The program is implemented using classes and variables to handle different tasks. Below are detailed descriptions of the variables, major functions, and usage of the system.

## 1. Data Dictionary

| Variable | Type      | Description              | Purpose                         | Remarks                      |
|----------|-----------|--------------------------|---------------------------------|------------------------------|
| zhanghao | CString   | A CString variable       | Stores the account input        |                              |
| mima     | CString   | A CString variable       | Stores the password input       |                              |
| dlgs     | mymenu    | A `mymenu` class variable| Sets the second menu interface  |                              |
| m_list   | CListCtrl | A `CListCtrl` variable   | Displays student information    |                              |
| m_edit   | CEdit     | A `CEdit` variable       | Shows the number of students    |                              |
| adds     | myadd     | A `myadd` class variable | Adds student information        |                              |
| changes  | mychange  | A `mychange` class variable | Modifies student information |                              |
| deletes  | mydelete  | A `mydelete` class variable | Deletes student information |                              |
| saves    | mysave    | A `mysave` class variable | Saves student information    |                              |
| imports  | myimport  | A `myimport` class variable | Imports student information |                              |
| finds    | myfinds   | A `myfinds` class variable | Finds student information    |                              |
| name     | CString   | A CString variable       | Stores the added student's name (in `myadd` class) | |
| grade    | CString   | A CString variable       | Stores the added student's grade (in `myadd` class) | |
| classs   | CString   | A CString variable       | Stores the added student's class (in `myadd` class) | |
| xing     | int       | An integer variable      | Stores the student's gender (in `myadd` class) | |
| number   | UINT      | An unsigned integer variable | Stores the student ID (in `myadd` class) | |
| program  | UINT      | An unsigned integer variable | Stores the C++ score (in `myadd` class) | |
| math     | UINT      | An unsigned integer variable | Stores the Advanced Math score (in `myadd` class) | |
| physical | UINT      | An unsigned integer variable | Stores the Physics score (in `myadd` class) | |
| a        | int       | An integer variable      | Stores selected checkbox info (in `mydelete` class) | |
| b        | CString   | A CString variable       | Stores input data (in `mydelete` class) | |
| a        | int       | An integer variable      | Stores selected checkbox info (in `myfind` class) | |
| b        | CString   | A CString variable       | Stores input data (in `myfind` class) | |
| i        | UINT      | An unsigned integer variable | Stores current row for search data (in `mymenu::find_q()` function) | |
| FA       | BOOL      | A Boolean variable       | Indicates if original data should be deleted on import (in `myimport` class) | |
| old_name | CString   | A CString variable       | Stores the old student name (in `mychange` class) | |
| new_name | CString   | A CString variable       | Stores the new student name (in `mychange` class) | |
| new_grade| CString   | A CString variable       | Stores the new student grade (in `mychange` class) | |
| new_class| CString   | A CString variable       | Stores the new student class (in `mychange` class) | |
| new_math | UINT      | An unsigned integer variable | Stores the new Advanced Math score (in `mychange` class) | |
| new_program | UINT   | An unsigned integer variable | Stores the new C++ score (in `mychange` class) | |
| new_physical | UINT  | An unsigned integer variable | Stores the new Physics score (in `mychange` class) | |
| new_number | UINT    | An unsigned integer variable | Stores the new student ID (in `mychange` class) | |

## 2. Main Function-Level Features

### Account Login Interface
- **Purpose:** Displays the login interface with two input fields (Edit control) and a button (Button control).
- **Functions:**
  - `BOOL CmanagementSystemDlg::OnInitDialog()` - Sets up the account login interface with the title "Student Grade Management System." Shows placeholders "Enter Account" and "Enter Password" in input fields.
  - `void CmanagementSystemDlg::OnPaint()` - Sets the background image of the login interface.
  - `void CmanagementSystemDlg::OnBnClickedOk()` - Verifies account and password input upon clicking the login button. Proceeds to the menu interface if correct; otherwise, shows an error message.
  - `void CmanagementSystemDlg::PreTranslateMessage(MSG* pMsg)` - Resets input fields to "Enter Account" and "Enter Password" if they are left empty.

### Menu System Interface
- **Purpose:** Displays the main menu interface with a list control, a group box, and eight buttons.
- **Functions:**
  - `BOOL mymenu::OnInitDialog()` - Sets the title and styles for the menu interface and its table contents.
  - `void mymenu::OnPaint()` - Sets the background for the menu interface.

### Validation Functions
- **Purpose:** Checks for data input validity.
- **Functions:**
  - `BOOL mymenu::nodata()` - Verifies if there is data in the list.
  - `BOOL mymenu::empty()` - Confirms if name, grade, and class fields are filled.
  - `BOOL mymenu::checkgrade()` - Checks if scores meet the required input format.
  - `BOOL mymenu::checknumber(char(&c)[15])` - Checks if the student ID is already in use.
  - `BOOL mymenu::checkxingbie()` - Confirms if gender is selected.

### Adding Student Information
- **Function:** `void mymenu::OnBnClickedButton1()` - Adds student details (name, gender, age, class, ID, and scores) to the system and displays them in the list.

### Deleting Student Information
- **Functions:**
  - `void mymenu::OnBnClickedButton2()` - Associated with the delete button, performs deletion based on selection.
  - `void mymenu::deletenull()` - Deletes all student information from the system.
  - `void mymenu::delete_q()` - Deletes a specific student’s information based on name or ID.

### Saving Student Information
- **Function:** `void mymenu::OnBnClickedButton3()` - Saves student information to a file, with options for file name and format.

### Finding Student Information
- **Functions:**
  - `void mymenu::OnBnClickedButton4()` - Associated with the find button to search for student information.
  - `void mymenu::find_q()` - Finds a student’s information by name or ID.
  - `void mymenu::reset(UINT a)` - Moves found student info to the top of the list.

### Importing Student Information
- **Functions:**
  - `void mymenu::OnBnClickedButton5()` - Imports student information from a file, with options to clear existing data or merge.
  - `void mymenu::importtt()` - Gets the file path for importing.
  - `UINT mymenu::importt()` - Imports the data, returning 1 if successful, otherwise 0.

### Modifying Student Information
- **Functions:**
  - `void mymenu::OnBnClickedButton6()` - Associated with the modify button to update student information.
  - `void mymenu::findcheck()` - Finds a student for modification.
  - `void mymenu::changename()` - Modifies the student's name.
  - `void mymenu::settext(int line)` - Updates specific information based on the line number, skipping fields left blank.

### Sorting Student Information
- **Function:** `void mymenu::OnBnClickedButton7()` - Sorts student information by ID based on selected criteria.
  - `void mymenu::resort()` - Sorts students by ID.

---
