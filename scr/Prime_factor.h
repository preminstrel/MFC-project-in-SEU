#pragma once


// Prime_factor 对话框

class Prime_factor : public CDialogEx
{
	DECLARE_DYNAMIC(Prime_factor)

public:
	Prime_factor(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Prime_factor();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG10 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString n;
	afx_msg void OnBnClickedButton1();
};
