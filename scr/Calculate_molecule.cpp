// Calculate_molecule.cpp: 实现文件
//

#include "pch.h"
#include "Calculate_atom.h"
#include "Calculate_molecule.h"
#include "afxdialogex.h"
#include"integration.h"
#include"linear.h"
#include"multiple_equations.h"
#include"Base_conversion.h"
#include"Complex_cal.h"
#include"Matrix_Cal.h"
#include"Time_Conversion.h"
#include"Date_Conversion.h"
#include"Prime_factor.h"
#include"Draw_dlg.h"
integration Dialog2;
linear Dialog3;
multiple_equations Dialog4;
Base_conversion Dialog5;
Complex_cal Dialog6;
Matrix_Cal Dialog7;
Time_Conversion Dialog8;
Date_Conversion Dialog9;
Prime_factor Dialog10;
Draw_dlg Dialog11;
// Calculate_molecule 对话框
//Dialog2.Create(IDD_DIALOG2, this);
//Dialog2.SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOSIZE);
//Dialog2.ShowWindow(SW_HIDE);
IMPLEMENT_DYNAMIC(Calculate_molecule, CDialog)

Calculate_molecule::Calculate_molecule(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
{

}

Calculate_molecule::~Calculate_molecule()
{
}

void Calculate_molecule::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Calculate_molecule, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &Calculate_molecule::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &Calculate_molecule::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &Calculate_molecule::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON10, &Calculate_molecule::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON9, &Calculate_molecule::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON11, &Calculate_molecule::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON14, &Calculate_molecule::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON2, &Calculate_molecule::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON13, &Calculate_molecule::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON12, &Calculate_molecule::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON15, &Calculate_molecule::OnBnClickedButton15)
END_MESSAGE_MAP()


// Calculate_molecule 消息处理程序


void Calculate_molecule::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!Dialog6.GetSafeHwnd())//现判断窗口是否已经创建
	Dialog6.Create(MAKEINTRESOURCE(IDD_DIALOG6));
	Dialog6.ShowWindow(1);
}

///积分计算
void Calculate_molecule::OnBnClickedButton4()
{
	//MessageBox(_T("Now:Atom mode RUNNING."), _T("使用说明"), MB_OK | MB_ICONINFORMATION);
	//Dialog2.ShowWindow(SW_SHOW);//显示子对话框1
	//CDialog* dlg1 = new CDialog;
	if (!Dialog2.GetSafeHwnd())//现判断窗口是否已经创建
	Dialog2.Create(MAKEINTRESOURCE(IDD_DIALOG2));
	Dialog2.ShowWindow(1);
}


void Calculate_molecule::OnBnClickedButton3()
{
	CDialog::OnOK();
}


void Calculate_molecule::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!Dialog8.GetSafeHwnd())//现判断窗口是否已经创建
	Dialog8.Create(MAKEINTRESOURCE(IDD_DIALOG8));
	Dialog8.ShowWindow(1);
}

///多元一次方程
void Calculate_molecule::OnBnClickedButton9()
{
	if (!Dialog3.GetSafeHwnd())//现判断窗口是否已经创建
	Dialog3.Create(MAKEINTRESOURCE(IDD_DIALOG3));
	Dialog3.ShowWindow(1);
}


void Calculate_molecule::OnBnClickedButton11()
{
	if (!Dialog4.GetSafeHwnd())//现判断窗口是否已经创建
	Dialog4.Create(MAKEINTRESOURCE(IDD_DIALOG4));
	Dialog4.ShowWindow(1);
}


void Calculate_molecule::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!Dialog5.GetSafeHwnd())//现判断窗口是否已经创建
	Dialog5.Create(MAKEINTRESOURCE(IDD_DIALOG5));
	Dialog5.ShowWindow(1);
}


void Calculate_molecule::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!Dialog7.GetSafeHwnd())//现判断窗口是否已经创建
	Dialog7.Create(MAKEINTRESOURCE(IDD_DIALOG7));
	Dialog7.ShowWindow(1);
}


void Calculate_molecule::OnBnClickedButton13()
{
	if (!Dialog9.GetSafeHwnd())//现判断窗口是否已经创建
	Dialog9.Create(MAKEINTRESOURCE(IDD_DIALOG9));
	Dialog9.ShowWindow(1);
	// TODO: 在此添加控件通知处理程序代码
}


void Calculate_molecule::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!Dialog10.GetSafeHwnd())//现判断窗口是否已经创建
	Dialog10.Create(MAKEINTRESOURCE(IDD_DIALOG10));
	Dialog10.ShowWindow(1);
}


void Calculate_molecule::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!Dialog11.GetSafeHwnd())//现判断窗口是否已经创建
	Dialog11.Create(MAKEINTRESOURCE(IDD_DIALOG11));
	Dialog11.ShowWindow(1);
}
