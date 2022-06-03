// Leisure.cpp: 实现文件
//

#include "pch.h"
#include "Calculate_atom.h"
#include "Leisure.h"
#include "afxdialogex.h"


// Leisure 对话框

IMPLEMENT_DYNAMIC(Leisure, CDialogEx)

Leisure::Leisure(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG13, pParent)
{

}

Leisure::~Leisure()
{
}

void Leisure::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Leisure, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Leisure::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Leisure::OnBnClickedButton2)
END_MESSAGE_MAP()


// Leisure 消息处理程序


void Leisure::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(NULL, "open", "Mine.exe", NULL, NULL, SW_SHOWNORMAL);
}


void Leisure::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(NULL, "open", "test.exe", NULL, NULL, SW_SHOWNORMAL);
}
