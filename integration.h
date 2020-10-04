#pragma once


// integration 对话框

class integration : public CDialogEx
{
	DECLARE_DYNAMIC(integration)

public:
	integration(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~integration();
	
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString integrate_input;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	CString integrate_input_2;
	afx_msg void OnEnChangeEdit3();
	CString integrate_input_min;
	BOOL m_r1;
	BOOL m_r2;
	BOOL m_r3;
	BOOL m_r4;
	BOOL m_r5;
	BOOL m_r6;
	int m_model;
	afx_msg void OnBnClickedRadio1();
};
