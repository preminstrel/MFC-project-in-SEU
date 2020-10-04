#pragma once


// Matrix_Cal 对话框

class Matrix_Cal : public CDialogEx
{
	DECLARE_DYNAMIC(Matrix_Cal)

public:
	Matrix_Cal(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Matrix_Cal();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString a11;
	CString a12;
	CString a21;
	CString a22;
	CString b21;
	CString b11;
	CString b12;
	CString b22;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton12();
};
