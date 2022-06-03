#pragma once


// multiple_equations 对话框

class multiple_equations : public CDialogEx
{
	DECLARE_DYNAMIC(multiple_equations)

public:
	multiple_equations(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~multiple_equations();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CString A;
	CString B;
	CString C;
	CString D;
	afx_msg void OnLbnSelchangeList1();
};
