#pragma once


// Draw_dlg 对话框

class Draw_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(Draw_dlg)

public:
	Draw_dlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Draw_dlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG11 };
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	
};
