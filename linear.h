#pragma once


// linear 对话框

class linear : public CDialogEx
{
	DECLARE_DYNAMIC(linear)

public:
	linear(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~linear();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString coefficient_11;
	CString coefficient_12;
	CString coefficient_13;
	CString coefficient_14;
	CString coefficient_15;
	CString coefficient_21;
	CString coefficient_22;
	CString coefficient_23;
	CString coefficient_24;
	CString coefficient_25;
	CString coefficient_31;
	CString coefficient_32;
	CString coefficient_33;
	CString coefficient_34;
	CString coefficient_35;
	CString coefficient_41;
	CString coefficient_42;
	CString coefficient_43;
	CString coefficient_44;
	CString coefficient_45;
	afx_msg void OnBnClickedButton2();
};
