// Base_conversion.cpp: 实现文件
//

#include "pch.h"
#include "Calculate_atom.h"
#include "Base_conversion.h"
#include "afxdialogex.h"


// Base_conversion 对话框

IMPLEMENT_DYNAMIC(Base_conversion, CDialogEx)

Base_conversion::Base_conversion(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG5, pParent)
	, base10(_T(""))
	, base16(_T(""))
	, base2(_T(""))
	, base32(_T(""))
	, base8(_T(""))
	, base36(_T(""))
{

}

Base_conversion::~Base_conversion()
{
}

void Base_conversion::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, base10);
	DDX_Text(pDX, IDC_EDIT5, base16);
	DDX_Text(pDX, IDC_EDIT2, base2);
	DDX_Text(pDX, IDC_EDIT6, base32);
	DDX_Text(pDX, IDC_EDIT4, base8);
	DDX_Text(pDX, IDC_EDIT7, base36);
}


BEGIN_MESSAGE_MAP(Base_conversion, CDialogEx)
	//ON_COMMAND(ID_MODE_LEISUREMODE, &Base_conversion::OnModeLeisuremode)
	ON_BN_CLICKED(IDC_BUTTON1, &Base_conversion::OnBnClickedButton1)
END_MESSAGE_MAP()


// Base_conversion 消息处理程序





void Base_conversion::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int k;
	char m[1000];
	if (base10)
	{
		k = int(atof(base10));
		_itoa_s(k,m,2);
		base2 = CString(m);
		_itoa_s(k, m, 16);
		base16 = CString(m);
		_itoa_s(k, m, 32);
		base32 = CString(m); 
		_itoa_s(k, m, 8);
		base8 = CString(m);
		_itoa_s(k, m, 36);
		base36 = CString(m);
	}
	UpdateData(FALSE);
}
