#pragma once


// Complex_cal 对话框

class Complex_cal : public CDialogEx
{
	DECLARE_DYNAMIC(Complex_cal)

public:
	Complex_cal(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Complex_cal();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString r1;
	CString r2;
	afx_msg void OnEnChangeEdit2();
	CString i1;
	CString i2;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
};
