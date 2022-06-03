// linear.cpp: 实现文件
//

#include "pch.h"
#include "Calculate_atom.h"
#include "linear.h"
#include "afxdialogex.h"


// linear 对话框

IMPLEMENT_DYNAMIC(linear, CDialogEx)

linear::linear(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, coefficient_11(_T(""))
	, coefficient_12(_T(""))
	, coefficient_13(_T(""))
	, coefficient_14(_T(""))
	, coefficient_15(_T(""))
	, coefficient_21(_T(""))
	, coefficient_22(_T(""))
	, coefficient_23(_T(""))
	, coefficient_24(_T(""))
	, coefficient_25(_T(""))
	, coefficient_31(_T(""))
	, coefficient_32(_T(""))
	, coefficient_33(_T(""))
	, coefficient_34(_T(""))
	, coefficient_35(_T(""))
	, coefficient_41(_T(""))
	, coefficient_42(_T(""))
	, coefficient_43(_T(""))
	, coefficient_44(_T(""))
	, coefficient_45(_T(""))
{

}

linear::~linear()
{
}

void linear::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, coefficient_11);
	DDX_Text(pDX, IDC_EDIT6, coefficient_12);
	DDX_Text(pDX, IDC_EDIT10, coefficient_13);
	DDX_Text(pDX, IDC_EDIT14, coefficient_14);
	DDX_Text(pDX, IDC_EDIT18, coefficient_15);
	DDX_Text(pDX, IDC_EDIT4, coefficient_21);
	DDX_Text(pDX, IDC_EDIT7, coefficient_22);
	DDX_Text(pDX, IDC_EDIT11, coefficient_23);
	DDX_Text(pDX, IDC_EDIT15, coefficient_24);
	DDX_Text(pDX, IDC_EDIT19, coefficient_25);
	DDX_Text(pDX, IDC_EDIT2, coefficient_31);
	DDX_Text(pDX, IDC_EDIT8, coefficient_32);
	DDX_Text(pDX, IDC_EDIT12, coefficient_33);
	DDX_Text(pDX, IDC_EDIT16, coefficient_34);
	DDX_Text(pDX, IDC_EDIT20, coefficient_35);
	DDX_Text(pDX, IDC_EDIT5, coefficient_41);
	DDX_Text(pDX, IDC_EDIT9, coefficient_42);
	DDX_Text(pDX, IDC_EDIT13, coefficient_43);
	DDX_Text(pDX, IDC_EDIT17, coefficient_44);
	DDX_Text(pDX, IDC_EDIT21, coefficient_45);
}


BEGIN_MESSAGE_MAP(linear, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &linear::OnBnClickedButton2)
END_MESSAGE_MAP()


// linear 消息处理程序


void linear::OnBnClickedButton2()
{
	UpdateData(TRUE);
	int n, m;
	double a11, a12, a13, a14, a15, a21, a22, a23, a24, a25, a31, a32, a33, a34, a35, a41, a42, a43, a44, a45;
	double s[4];
	a11 = atof(coefficient_11);
	a12 = atof(coefficient_12);
	a13 = atof(coefficient_13);
	a14 = atof(coefficient_14);
	a15 = atof(coefficient_15);
	a21 = atof(coefficient_21);
	a22 = atof(coefficient_22);
	a23 = atof(coefficient_23);
	a24 = atof(coefficient_24);
	a25 = atof(coefficient_25);
	a31 = atof(coefficient_31);
	a32 = atof(coefficient_32);
	a33 = atof(coefficient_33);
	a34 = atof(coefficient_34);
	a35 = atof(coefficient_35);
	a41 = atof(coefficient_41);
	a42 = atof(coefficient_42);
	a43 = atof(coefficient_43);
	a44 = atof(coefficient_44);
	a45 = atof(coefficient_45);
	double det = a11*a22 * a33 * a44 - a11 * a22 * a34 * a43 - a11 * a23 * a32 * a44 + a11 * a23 * a34 * a42
		+ a11 * a24 * a32 * a43 - a11 * a24 * a33 * a42 - a12 * a21 * a33 * a44 + a12 * a21 * a34 * a43
		+ a12 * a23 * a31 * a44 - a12 * a23 * a34 * a41 - a12 * a24 * a31 * a43 + a12 * a24 * a33 * a41
		+ a13 * a21 * a32 * a44 - a13 * a21 * a34 * a42 - a13 * a22 * a31 * a44 + a13 * a22 * a34 * a41
		+ a13 * a24 * a31 * a42 - a13 * a24 * a32 * a41 - a14 * a21 * a32 * a43 + a14 * a21 * a33 * a42
		+ a14 * a22 * a31 * a43 - a14 * a22 * a33 * a41 - a14 * a23 * a31 * a42 + a14 * a23 * a32 * a41;
	double a[4][5] = {
		{a11,a12,a13,a14,a15},
		{a21,a22,a23,a24,a25},
		{a31,a32,a33,a34,a35},
		{a41,a42,a43,a44,a45},
	};//第四列是增广矩阵 
	int i, j;
	n = 4;
	for (j = 0; j < n; j++)
	{
		double max = 0;
		double imax = 0;
		for (i = j; i < n; i++)
		{
			if (imax < fabs(a[i][j])) {
				imax = fabs(a[i][j]);
				max = a[i][j];//得到各行中所在列最大元素 
				m = i;
			}
		}
		if (fabs(a[j][j]) != max)
		{
			double b = 0;
			for (int k = j; k < n + 1; k++) {
				b = a[j][k];
				a[j][k] = a[m][k];
				a[m][k] = b;
			}
		}
		for (int r = j; r < n + 1; r++)
		{
			a[j][r] = a[j][r] / max;//让该行的所在列除以所在列的第一个元素，目的是让首元素为1 
		}
		for (i = j + 1; i < n; i++)
		{
			double c = a[i][j];
			if (c == 0) continue;
			for (int s = j; s < n + 1; s++) {
				double tempdata = a[i][s];
				a[i][s] = a[i][s] - a[j][s] * c;//前后行数相减，使下一行或者上一行的首元素为0 

			}

		}

	}
	for (i = n - 2; i >= 0; i--)
	{
		for (j = i + 1; j < n; j++)
		{
			double tempData = a[i][j];
			double data1 = a[i][n];
			double data2 = a[j][n];
			a[i][n] = a[i][n] - a[j][n] * a[i][j];
		}
	}

	for (int k = 0; k < n; k++) {
		s[k] = a[k][n];
	}
	CString S1, S2, S3, S4, S5;
	S1.Format(_T("%.4f"), s[0]);
	S2.Format(_T("%.4f"), s[1]);
	S3.Format(_T("%.4f"), s[2]);
	S4.Format(_T("%.4f"), s[3]);
	S1 = CString("解为:\n") + CString("a=") + S1 + CString("\n") + CString("b=") +
		S2 + CString("\n") + CString("c=") + S3 + CString("\n") + CString("d=") + S4;
	if(det)MessageBox(S1, _T("The answer"));
	if(det==0)MessageBox(_T("不满秩"), _T("Wrong"));
	UpdateData(FALSE);
}
