#pragma once


// integrate 对话框

class integrate : public CDialogEx
{
	DECLARE_DYNAMIC(integrate)

public:
	integrate(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~integrate();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
