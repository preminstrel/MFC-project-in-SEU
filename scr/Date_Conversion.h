#pragma once


// Date_Conversion 对话框

class Date_Conversion : public CDialogEx
{
	DECLARE_DYNAMIC(Date_Conversion)

public:
	Date_Conversion(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Date_Conversion();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	bool IsLeapYear(int year);
	CString y1;
	CString m1;
	CString d1;
	CString y2;
	CString m2;
	CString d2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
};
