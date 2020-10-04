
// Calculate_atomDlg.h: 头文件
//

#pragma once

//////////防止变成WIN95风格！！！ 
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#include"Calculate_molecule.h"
#include"integration.h"
#include"CLoginDlg.h"
#include"Leisure.h"
// CCalculateatomDlg 对话框
class CCalculateatomDlg : public CDialogEx
{
// 构造
public:
	CCalculateatomDlg(CWnd* pParent = nullptr);	// 标准构造函数
	CMenu m_Menu;
	Calculate_molecule Dialog1;
	Leisure Dialog0;
	integration Dialog2;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATE_ATOM_DIALOG };
#endif
public:
	INT PriorityLevel(char op);
	BOOL IsOpr(char c);
	CString InfixToSuffix(CString szIn);
	CString minusjudge(CString a);
	double SuffixToResult(CString szSuffix);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	CEdit m_edit;
	CString m_str;
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton34();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton31();
	afx_msg void OnBnClickedButton26();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton27();
	afx_msg void OnBnClickedButton21();
	afx_msg void OnBnClickedButton28();
	afx_msg void OnBnClickedButton22();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton32();
	afx_msg void OnBnClickedButton23();
	afx_msg void OnBnClickedButton15();
	afx_msg void OnBnClickedButton17();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton16();
	afx_msg void OnBnClickedButton18();
	afx_msg void OnBnClickedButton19();
	afx_msg void OnBnClickedButton20();
	afx_msg void OnBnClickedButton24();
	afx_msg void OnBnClickedButton25();
	afx_msg void OnBnClickedButton29();
	afx_msg void OnHelpInstructions();
	afx_msg void OnEditCopy32775();
	afx_msg void OnModeMoleculemode();
	afx_msg void OnModeLeisuremode();
	afx_msg void OnContactus();
	afx_msg void On32785();
	afx_msg void OnModeDrawmode();
};
