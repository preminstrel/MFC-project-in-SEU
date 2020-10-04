#pragma once


// Leisure 对话框

class Leisure : public CDialogEx
{
	DECLARE_DYNAMIC(Leisure)

public:
	Leisure(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Leisure();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG13 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
