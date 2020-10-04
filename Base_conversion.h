#pragma once


// Base_conversion 对话框

class Base_conversion : public CDialogEx
{
	DECLARE_DYNAMIC(Base_conversion)

public:
	Base_conversion(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Base_conversion();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnModeLeisuremode();
	CString base10;
	CString base16;
	CString base2;
	CString base32;
	CString base8;
	CString base36;
	afx_msg void OnBnClickedButton1();
};
