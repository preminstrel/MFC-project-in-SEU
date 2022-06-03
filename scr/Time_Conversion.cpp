// Time_Conversion.cpp: 实现文件
//

#include "pch.h"
#include "Calculate_atom.h"
#include "Time_Conversion.h"
#include "afxdialogex.h"


// Time_Conversion 对话框

IMPLEMENT_DYNAMIC(Time_Conversion, CDialogEx)

Time_Conversion::Time_Conversion(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG8, pParent)
	, h1(_T(""))
	, m1(_T(""))
	, s1(_T(""))
	, h2(_T(""))
	, m2(_T(""))
	, s2(_T(""))
{

}

Time_Conversion::~Time_Conversion()
{
}

void Time_Conversion::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, h1);
	DDX_Text(pDX, IDC_EDIT4, m1);
	DDX_Text(pDX, IDC_EDIT1, s1);
	DDX_Text(pDX, IDC_EDIT6, h2);
	DDX_Text(pDX, IDC_EDIT7, m2);
	DDX_Text(pDX, IDC_EDIT8, s2);
}


BEGIN_MESSAGE_MAP(Time_Conversion, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &Time_Conversion::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &Time_Conversion::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &Time_Conversion::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON9, &Time_Conversion::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &Time_Conversion::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &Time_Conversion::OnBnClickedButton11)
END_MESSAGE_MAP()


// Time_Conversion 消息处理程序
void Time_Conversion::basiccon(CString a, CString b, CString c)
{
	UpdateData(TRUE);
	double h = atof(a);
	double m = atof(b); 
	double s = atof(c);
	double sum = 3600 * h + 60 * m + s;
	h = sum / 3600;
	h = int(h) % 24;
	sum = int(sum) % 3600;
	m = int(sum / 60);
	sum = int(sum) % 60;
	s = sum;
	h1.Format(_T("%d"), int(h));
	m1.Format(_T("%d"),int( m));
	s1.Format(_T("%d"), int(s)); 
	UpdateData(FALSE);
}
void Time_Conversion::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	basiccon(h1, m1, s1); 
	double h = atof(h2);
	double m = atof(m2);
	double s = atof(s2);
	double sum = 3600 * h + 60 * m + s;
	h = sum / 3600;
	h = int(h) % 24;
	sum = int(sum) % 3600;
	m = int(sum / 60);
	sum = int(sum) % 60;
	s = sum;
	h2.Format(_T("%d"), int(h));
	m2.Format(_T("%d"), int(m));
	s2.Format(_T("%d"), int(s));
	UpdateData(FALSE);
}


void Time_Conversion::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	basiccon(h1, m1, s1);
	CString a, b, c;
	a.Format(_T("%d"), int(atof(h1) + atof(h2)));
	b.Format(_T("%d"), int(atof(m1) + atof(m2))); 
	c.Format(_T("%d"), int(atof(s1) + atof(s2)));
	//CString a =atof(h1) + atof(h2);
	//CString b = m1 + m2; 
	//CString c = s1 + s2;
	
	double h = atof(a);
	double m = atof(b);
	double s = atof(c);
	double sum = 3600 * h + 60 * m + s;
	h = sum / 3600;
	h = int(h) % 24;
	sum = int(sum) % 3600;
	m = int(sum / 60);
	sum = int(sum) % 60;
	s = sum;
	a.Format(_T("%d"), int(h));
	b.Format(_T("%d"), int(m));
	c.Format(_T("%d"), int(s));
	MessageBox(a+CString(":")+b+ CString(":")+c, _T("The answer"));
	UpdateData(FALSE);
}


void Time_Conversion::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	//获取系统时间
	CTime tm;
	tm = CTime::GetCurrentTime();//获取系统日期
	str = tm.Format("现在北京时间是%Y年%m月%d日 %X");
	MessageBox(str, _T("The answer"));
}


void Time_Conversion::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	CTime t = CTime::GetCurrentTime();
	int h = t.GetHour(); //获取当前为几时
	int mm = t.GetMinute(); //获取分钟
	int s = t.GetSecond(); //获取秒
	h = h + 1;
	h = h % 24;
	CString a, b, c;
	a.Format(_T("%d"), int(h));
	b.Format(_T("%d"), int(mm));
	c.Format(_T("%d"), int(s));
	MessageBox(CString("现在东京时间是")+a + CString(":") + b + CString(":") + c, _T("The answer"));
}


void Time_Conversion::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	CTime t = CTime::GetCurrentTime();
	int h = t.GetHour(); //获取当前为几时
	int mm = t.GetMinute(); //获取分钟
	int s = t.GetSecond(); //获取秒
	h = h - 7;
	h = h % 24;
	CString a, b, c;
	a.Format(_T("%d"), int(h));
	b.Format(_T("%d"), int(mm));
	c.Format(_T("%d"), int(s));
	MessageBox(CString("现在伦敦时间是") + a + CString(":") + b + CString(":") + c, _T("The answer"));
}


void Time_Conversion::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	CTime t = CTime::GetCurrentTime();
	int h = t.GetHour(); //获取当前为几时
	int mm = t.GetMinute(); //获取分钟
	int s = t.GetSecond(); //获取秒
	h = h - 12;
	h = h % 24;
	CString a, b, c;
	a.Format(_T("%d"), int(h));
	b.Format(_T("%d"), int(mm));
	c.Format(_T("%d"), int(s));
	MessageBox(CString("现在华盛顿时间是") + a + CString(":") + b + CString(":") + c, _T("The answer"));
}
