#pragma once


// Time_Conversion 对话框

class Time_Conversion : public CDialogEx
{
	DECLARE_DYNAMIC(Time_Conversion)

public:
	Time_Conversion(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Time_Conversion();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CString h1;
	CString m1;
	CString s1;
	CString h2;
	CString m2;
	CString s2;
	void Time_Conversion::basiccon(CString a, CString b, CString c);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
};
