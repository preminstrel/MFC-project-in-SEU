// Complex_cal.cpp: 实现文件
//

#include "pch.h"
#include "Calculate_atom.h"
#include "Complex_cal.h"
#include "afxdialogex.h"


// Complex_cal 对话框

IMPLEMENT_DYNAMIC(Complex_cal, CDialogEx)

Complex_cal::Complex_cal(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
	, r1(_T(""))
	, r2(_T(""))
	, i1(_T(""))
	, i2(_T(""))
{

}

Complex_cal::~Complex_cal()
{
}

void Complex_cal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, r1);
	DDX_Text(pDX, IDC_EDIT3, r2);
	DDX_Text(pDX, IDC_EDIT2, i1);
	DDX_Text(pDX, IDC_EDIT4, i2);
}


BEGIN_MESSAGE_MAP(Complex_cal, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &Complex_cal::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON4, &Complex_cal::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON9, &Complex_cal::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON1, &Complex_cal::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Complex_cal::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Complex_cal::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &Complex_cal::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON11, &Complex_cal::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &Complex_cal::OnBnClickedButton12)
END_MESSAGE_MAP()


// Complex_cal 消息处理程序


void Complex_cal::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

//+
void Complex_cal::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double R1 = atof(r1);
	double R2 = atof(r2);
	double I1 = atof(i1);
	double I2 = atof(i2);
	CString msg = ("");
	CString rr, ii;
	rr.Format(_T("%.4f"), R1+R2);
	ii.Format(_T("%.4f"), I1+I2);
	if (I1 + I2 >= 0)
		msg = CString("结果： ") + rr + CString("+") + ii + CString("i");
	else
		msg = CString("结果： ") + rr + ii + CString("i");
	MessageBox(msg, CString("Answer"));
	UpdateData(FALSE);
}

//-
void Complex_cal::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double R1 = atof(r1);
	double R2 = atof(r2);
	double I1 = atof(i1);
	double I2 = atof(i2);
	CString msg = ("");
	CString rr, ii;
	rr.Format(_T("%.4f"), R1 - R2);
	ii.Format(_T("%.4f"), I1 - I2);
	if(I1 - I2>=0)
	msg = CString("结果： ") + rr + CString("+") + ii + CString("i");
	else
		msg = CString("结果： ") + rr  + ii + CString("i");
	MessageBox(msg, CString("Answer"));
	UpdateData(FALSE);
}


void Complex_cal::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double R1 = atof(r1);
	double R2 = atof(r2);
	double I1 = atof(i1);
	double I2 = atof(i2);
	CString msg = ("");
	CString rr, ii;
	rr.Format(_T("%.4f"), R1*R2-I1*I2);
	ii.Format(_T("%.4f"), I1*R2 + R1*I2);
	if (I1 * R2 + R1 * I2 >= 0)
		msg = CString("结果： ") + rr + CString("+") + ii + CString("i");
	else
		msg = CString("结果： ") + rr + ii + CString("i");
	MessageBox(msg, CString("Answer"));
	UpdateData(FALSE);
}


void Complex_cal::OnBnClickedButton2()
{//(ac+bd)/(c^2+d^2)+(bc-ad)/(c^2+d^2)i
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double R1 = atof(r1);
	double R2 = atof(r2);
	double I1 = atof(i1);
	double I2 = atof(i2);
	CString msg = ("");
	CString rr, ii;
	rr.Format(_T("%.4f"), (R1 * R2+ I1 * I2)/(R2*R2+I2*I2));
	ii.Format(_T("%.4f"), (I1 * R2 - R1 * I2 )/ (R2 * R2 + I2 * I2));
	if ((I1 * R2 - R1 * I2) / (R2 * R2 + I2 * I2) >= 0)
		msg = CString("结果： ") + rr + CString("+") + ii + CString("i");
	else
		msg = CString("结果： ") + rr + ii + CString("i");
	MessageBox(msg, CString("Answer"));
	UpdateData(FALSE);
}


void Complex_cal::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double R1 = atof(r1);
	double R2 = atof(r2);
	double I1 = atof(i1);
	double I2 = atof(i2);
	CString msg = ("");
	CString mo;
	mo.Format(_T("%.4f"), sqrt(R1 * R1 + I1 * I1));
		msg = CString("结果： ") + mo;
	MessageBox(msg, CString("Answer"));
	UpdateData(FALSE);
}


void Complex_cal::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double R1 = atof(r1);
	double R2 = atof(r2);
	double I1 = atof(i1);
	double I2 = atof(i2);
	CString msg = ("");
	CString mo;
	mo.Format(_T("%.4f"), sqrt(R2 * R2 + I2 * I2));
	msg = CString("结果： ") + mo;
	MessageBox(msg, CString("Answer"));
	UpdateData(FALSE);
}


void Complex_cal::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double R1 = atof(r1);
	double R2 = atof(r2);
	double I1 = atof(i1);
	double I2 = atof(i2);
	CString msg = ("");
	CString angle;
	angle.Format(_T("%.4f"), atan2(I1, R1));
	msg = CString("结果： ") + angle;
	MessageBox(msg, CString("Answer"));
	UpdateData(FALSE);
}


void Complex_cal::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double R1 = atof(r1);
	double R2 = atof(r2);
	double I1 = atof(i1);
	double I2 = atof(i2);
	CString msg = ("");
	CString angle;
	angle.Format(_T("%.4f"), atan2(I2, R2));
	msg = CString("结果： ") + angle;
	MessageBox(msg, CString("Answer"));
	UpdateData(FALSE);
}
