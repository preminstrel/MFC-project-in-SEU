// Matrix_Cal.cpp: 实现文件
//

#include "pch.h"
#include "Calculate_atom.h"
#include "Matrix_Cal.h"
#include "afxdialogex.h"


// Matrix_Cal 对话框

IMPLEMENT_DYNAMIC(Matrix_Cal, CDialogEx)

Matrix_Cal::Matrix_Cal(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG7, pParent)
	, a11(_T(""))
	, a12(_T(""))
	, a21(_T(""))
	, a22(_T(""))
	, b21(_T(""))
	, b11(_T(""))
	, b12(_T(""))
	, b22(_T(""))
{

}

Matrix_Cal::~Matrix_Cal()
{
}

void Matrix_Cal::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, a11);
	DDX_Text(pDX, IDC_EDIT4, a12);
	DDX_Text(pDX, IDC_EDIT2, a21);
	DDX_Text(pDX, IDC_EDIT5, a22);
	DDX_Text(pDX, IDC_EDIT9, b21);
	DDX_Text(pDX, IDC_EDIT6, b11);
	DDX_Text(pDX, IDC_EDIT7, b12);
	DDX_Text(pDX, IDC_EDIT8, b22);
}


BEGIN_MESSAGE_MAP(Matrix_Cal, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Matrix_Cal::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Matrix_Cal::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON4, &Matrix_Cal::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON13, &Matrix_Cal::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON9, &Matrix_Cal::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &Matrix_Cal::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &Matrix_Cal::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &Matrix_Cal::OnBnClickedButton12)
END_MESSAGE_MAP()


// Matrix_Cal 消息处理程序


void Matrix_Cal::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double A11 = atof(a11);
	double A12 = atof(a12);
	double A21 = atof(a21);
	double A22 = atof(a22);
	double B11 = atof(b11);
	double B12 = atof(b12);
	double B22 = atof(b22);
	double B21 = atof(b21);
	double c11 = A11*B11+A12*B21;
	double c12 = A21 * B11 + A22 * B21;
	double c21 = A11* B12 + A12*B22;
	double c22 = A21 * B12 + A22 * B22;
	CString C11, C12, C21, C22;
	C11.Format(_T("%.4f"), c11);
	C12.Format(_T("%.4f"), c12);
	C21.Format(_T("%.4f"), c21);
	C22.Format(_T("%.4f"), c22);
	CString M("结果：新矩阵：[");
	M += C11 + CString(", ") + C12 + CString("; ") + C21 + CString(", ") + C22 + CString("] ");
	MessageBox(M, _T("The answer"));
	UpdateData(FALSE);
}


void Matrix_Cal::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double A11 = atof(a11);
	double A12 = atof(a12);
	double A21 = atof(a21);
	double A22 = atof(a22);
	double B11 = atof(b11);
	double B12 = atof(b12);
	double B22 = atof(b22);
	double B21 = atof(b21);
	double c11 = A11 + B11;
	double c12 = A12 + B12;
	double c21 = A21 + B21;
	double c22 = A22 + B22;
	CString C11, C12, C21, C22;
	C11.Format(_T("%.4f"), c11);
	C12.Format(_T("%.4f"), c12);
	C21.Format(_T("%.4f"), c21);
	C22.Format(_T("%.4f"), c22);
	CString M("结果：新矩阵：[");
	M += C11 + CString(", ") + C12 + CString("; ") + C21 + CString(", ") + C22 + CString("] ");
	MessageBox(M, _T("The answer"));
	UpdateData(FALSE);
}


void Matrix_Cal::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double A11 = atof(a11);
	double A12 = atof(a12);
	double A21 = atof(a21);
	double A22 = atof(a22);
	double B11 = atof(b11);
	double B12 = atof(b12);
	double B22 = atof(b22);
	double B21 = atof(b21);
	double c11 = A11 - B11;
	double c12 = A12 - B12;
	double c21 = A21 - B21;
	double c22 = A22 - B22;
	CString C11, C12, C21, C22;
	C11.Format(_T("%.4f"), c11);
	C12.Format(_T("%.4f"), c12);
	C21.Format(_T("%.4f"), c21);
	C22.Format(_T("%.4f"), c22);
	CString M("结果：新矩阵：[");
	M += C11 + CString(", ") + C12 + CString("; ") + C21 + CString(", ") + C22 + CString("] ");
	MessageBox(M , _T("The answer"));
	UpdateData(FALSE);
}


void Matrix_Cal::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double A11 = atof(a11);
	double A12 = atof(a12);
	double A21 = atof(a21);
	double A22 = atof(a22);
	double B11 = atof(b11);
	double B12 = atof(b12);
	double B22 = atof(b22);
	double B21 = atof(b21);
	CString M("结果：新矩阵1：[");
	M += a11 + CString(", ") + a21 + CString("; ") + a12 + CString(", ") + a22 + CString("] ")+ CString(";  新矩阵2：[ ")+b11 + CString(", ") + b21 + CString("; ") + b12 + CString(", ") + b22 + CString("] ");
	MessageBox(M, _T("The answer"));
	UpdateData(FALSE);
}


void Matrix_Cal::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double A11 = atof(a11);
	double A12 = atof(a12);
	double A21 = atof(a21);
	double A22 = atof(a22);
	double B11 = atof(b11);
	double B12 = atof(b12);
	double B22 = atof(b22);
	double B21 = atof(b21);
	CString M("结果:");
	CString x;
	double xx = A11 * A22 - A21 * A12;
	x.Format(_T("%.4f"), xx);
	M += x;
	MessageBox(M, _T("The answer"));
	UpdateData(FALSE);
}


void Matrix_Cal::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double A11 = atof(a11);
	double A12 = atof(a12);
	double A21 = atof(a21);
	double A22 = atof(a22);
	double B11 = atof(b11);
	double B12 = atof(b12);
	double B22 = atof(b22);
	double B21 = atof(b21);
	CString M("结果:");
	CString x;
	double xx = B11 * B22 - B21 * B12;
	x.Format(_T("%.4f"), xx);
	M += x;
	MessageBox(M, _T("The answer"));
	UpdateData(FALSE);
}


void Matrix_Cal::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double A11 = atof(a11);
	double A12 = atof(a12);
	double A21 = atof(a21);
	double A22 = atof(a22);
	double B11 = atof(b11);
	double B12 = atof(b12);
	double B22 = atof(b22);
	double B21 = atof(b21);
	CString M("结果:");
	CString x;
	double xx = A11 * A22 - A21 * A12;
	if (xx != 0)x.Format(_T("%d"), 2);
	else if (xx == 0 && A11 == 0 && A12 == 0 && A21 == 0 && A22 == 0)x.Format(_T("%d"), 0);
	else x.Format(_T("%d"), 1);
	M += x;
	MessageBox(M, _T("The answer"));
	UpdateData(FALSE);
}


void Matrix_Cal::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double A11 = atof(a11);
	double A12 = atof(a12);
	double A21 = atof(a21);
	double A22 = atof(a22);
	double B11 = atof(b11);
	double B12 = atof(b12);
	double B22 = atof(b22);
	double B21 = atof(b21);
	CString M("结果:");
	CString x;
	double xx = B11 * B22 - B21 * B12;
	if (xx!=0)x.Format(_T("%d"), 2);
	else if (xx == 0 && B11 == 0 && B12 == 0 && B21 == 0 && B22 == 0)x.Format(_T("%d"), 0);
	else x.Format(_T("%d"), 1);
	M += x;
	MessageBox(M, _T("The answer"));
	UpdateData(FALSE);
}
