// integration.cpp: 实现文件
//

#include "pch.h"
#include "Calculate_atom.h"
#include "integration.h"
#include "afxdialogex.h"


// integration 对话框

IMPLEMENT_DYNAMIC(integration, CDialogEx)

integration::integration(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, integrate_input(_T(""))
	, integrate_input_2(_T(""))
	, integrate_input_min(_T(""))
	, m_r1(FALSE)
	, m_r2(FALSE)
	, m_r3(FALSE)
	, m_r4(FALSE)
	, m_r5(FALSE)
	, m_r6(FALSE)
{

}

integration::~integration()
{
}

void integration::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, integrate_input);
	DDX_Text(pDX, IDC_EDIT3, integrate_input_min);
	//DDX_Radio(pDX, IDC_RADIO1, m_r1);
	//DDX_Radio(pDX, IDC_RADIO2, m_r2);
	//DDX_Radio(pDX, IDC_RADIO3, m_r3);
	//DDX_Radio(pDX, IDC_RADIO4, m_r4);
	//DDX_Radio(pDX, IDC_RADIO5, m_r5);
	//DDX_Radio(pDX, IDC_RADIO6, m_r6);
}


BEGIN_MESSAGE_MAP(integration, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &integration::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &integration::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT3, &integration::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_RADIO1, &integration::OnBnClickedRadio1)
END_MESSAGE_MAP()


// integration 消息处理程序


void integration::OnBnClickedButton1()
{
	UpdateData(TRUE);
	CString result;
	if (((CButton*)GetDlgItem(IDC_RADIO1))->GetCheck())
	{
		double max = atof(integrate_input); //上限
		double min = atof(integrate_input_min); //下限
		double res = ((max * max ) - (min * min )) / 2;
		result.Format(_T("%.4f"), res);
		MessageBox(_T(result), _T("The answer"));
	}
	if (((CButton*)GetDlgItem(IDC_RADIO2))->GetCheck())
	{
		double max = atof(integrate_input); //上限
		double min = atof(integrate_input_min); //下限
		double res = ((max * max * max) - (min * min * min)) / 3;
		result.Format(_T("%.4f"), res);
		MessageBox(_T(result), _T("The answer"));
	}
	if (((CButton*)GetDlgItem(IDC_RADIO3))->GetCheck())
	{
		double max = atof(integrate_input); //上限
		double min = atof(integrate_input_min); //下限
		double res = exp(max) - exp(min);
		result.Format(_T("%.4f"), res);
		MessageBox(_T(result), _T("The answer"));
	}
	if (((CButton*)GetDlgItem(IDC_RADIO4))->GetCheck())
	{
		double max = atof(integrate_input); //上限
		double min = atof(integrate_input_min); //下限
		double res = max*(log(max)-1)- min * (log(min) - 1);
		result.Format(_T("%.4f"), res);
		MessageBox(_T(result), _T("The answer"));
	}
	if (((CButton*)GetDlgItem(IDC_RADIO5))->GetCheck())
	{
		double max = atof(integrate_input); //上限
		double min = atof(integrate_input_min); //下限
		double res = sin(max) - sin(min);
		result.Format(_T("%.4f"), res);
		MessageBox(_T(result), _T("The answer"));
	}
	if (((CButton*)GetDlgItem(IDC_RADIO6))->GetCheck())
	{
		double max = atof(integrate_input); //上限
		double min = atof(integrate_input_min); //下限
		double res = cos(max) - cos(min);
		result.Format(_T("%.4f"), res);
		MessageBox(_T(result), _T("The answer"));
	}
	UpdateData(FALSE);
}


void integration::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void integration::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}




void integration::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
}
