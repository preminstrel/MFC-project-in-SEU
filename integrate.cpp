// integrate.cpp: 实现文件
//

#include "pch.h"
#include "Calculate_atom.h"
#include "integrate.h"
#include "afxdialogex.h"


// integrate 对话框

IMPLEMENT_DYNAMIC(integrate, CDialogEx)

integrate::integrate(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

integrate::~integrate()
{
}

void integrate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(integrate, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &integrate::OnBnClickedButton1)
END_MESSAGE_MAP()


// integrate 消息处理程序


void integrate::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
}
