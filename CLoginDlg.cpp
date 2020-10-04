// CLoginDlg.cpp: 实现文件
//

#include "pch.h"
#include "Calculate_atom.h"
#include "CLoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG12, pParent)
	, m_InUser(_T(""))
	, m_InPassword(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_InUser);
	DDX_Text(pDX, IDC_EDIT2, m_InPassword);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序

    
void CLoginDlg::OnBnClickedButton1()
{
	this->UpdateData(true);
	if (this->m_InUser.IsEmpty() || this->m_InPassword.IsEmpty())
	{
		MessageBox(_T("用户名或密码不能为空，请重新输入！"), _T("用户登录信息"), MB_ICONINFORMATION);
		return;
	}
	else if (this->m_InUser == "1" && this->m_InPassword == "1")
	{
		CDialogEx::OnOK();
	}
	else if (this->m_InUser == "孙寒石" && this->m_InPassword == "Sun20001225")
	{
		CDialogEx::OnOK();
	}
	else if (this->m_InUser == "张扬" && this->m_InPassword == "123456")
	{
		CDialogEx::OnOK();
	}
	else if (this->m_InUser == "陶星宇" && this->m_InPassword == "123456")
	{
		CDialogEx::OnOK();
	}
	else if (this->m_InUser == "车旭明" && this->m_InPassword == "123456")
	{
		CDialogEx::OnOK();
	}
	else if (this->m_InUser == "韦伟" && this->m_InPassword == "0904")
	{
		CDialogEx::OnOK();
	}
	else
	{
		MessageBox(_T("用户名或密码不正确，请重新输入！"), _T("登录失败"), MB_ICONERROR);
		return;
	}

     
}

/*
void CLoginDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 在此处添加消息处理程序代码
					   // 不为绘图消息调用 CDialogEx::OnPaint()
	CRect   rect;
	GetClientRect(&rect);
	CDC   dcMem;
	dcMem.CreateCompatibleDC(&dc);
	CBitmap   bmpBackground;
	bmpBackground.LoadBitmap(IDB_BITMAP1);   
																	 

	BITMAP   bitmap;
	bmpBackground.GetBitmap(&bitmap);
	CBitmap* pbmpOld = dcMem.SelectObject(&bmpBackground);
	dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0,
		bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);
}
*/