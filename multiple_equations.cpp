// multiple_equations.cpp: 实现文件
//

#include "pch.h"
#include "Calculate_atom.h"
#include "multiple_equations.h"
#include "afxdialogex.h"
#include<iomanip>
#include<cmath>
double fx(double nparam[3], double x)
{
    return pow(x, 3) + nparam[0] * pow(x, 2) + nparam[1] * x + nparam[2];
}
int oneresult(double nparam[3], double nrange[2], double via, int position)
{
    double i = via;
    nrange[0] = via;
    if (position == 0)
    {
        while (fx(nparam, i) * fx(nparam, via) > 0)
        {
            if (i > -10)
                i = i - 0.1;
            else
                i = i - 1;
            if (i < -100)
                return 1;
        }
        nrange[1] = i;
    }
    else
    {
        while (fx(nparam, i) * fx(nparam, via) > 0)
        {
            if (i < 10)
                i = i + 0.1;
            else
                i = i + 1;
            if (i > 100)
                return 1;
        }
        nrange[1] = i;
    }
    return 0;
}
double dichotomy(double nparam[3], double x1, double x2)
{
    double x0;
    double x3;
    while (x0 = (x1 + x2) / 2, (x3 = fabs(fx(nparam, x0))) > 1e-5)
    {
        if (fx(nparam, x0) * fx(nparam, x2) > 0)
            x2 = x0;
        else
            x1 = x0;
    }
    return x0;
}
int Imagequation(double x1, double* p1, double* p2, double* r, double* i)//根据求出来的一个跟，利用待定系数法分解因式，求出两个虚数解
{
    *p1 += x1;
    *p2 += x1 * (*p1);
    *r = -(*p1) / 2;
    *i = sqrt(4 * (*p2) - pow(*p1, 2)) / 2;
    return 1;
}
// multiple_equations 对话框

IMPLEMENT_DYNAMIC(multiple_equations, CDialogEx)

multiple_equations::multiple_equations(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
    , A(_T(""))
    , B(_T(""))
    , C(_T(""))
    , D(_T(""))
{

}

multiple_equations::~multiple_equations()
{
}

void multiple_equations::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT1, A);
    DDX_Text(pDX, IDC_EDIT2, B);
    DDX_Text(pDX, IDC_EDIT4, C);
    DDX_Text(pDX, IDC_EDIT5, D);
}


BEGIN_MESSAGE_MAP(multiple_equations, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &multiple_equations::OnBnClickedButton1)
END_MESSAGE_MAP()


// multiple_equations 消息处理程序


void multiple_equations::OnBnClickedButton1()
{
    UpdateData(TRUE);
    double param[3];
    double dparam[3];
    double range[2];
    double result[3];
    double x1, x2;
    double a, b, c, d;
    int i = 0;
    a = atof(A);
    b = atof(B);
    c = atof(C);
    d = atof(D);
    if (a == 0)
    {
        MessageBox(_T("您数的参数有误!"), _T("Wrong"));
    }
    param[0] = b / a;
    param[1] = c / a;
    param[2] = d / a;
    dparam[0] = 3;
    dparam[1] = 2 * param[0];
    dparam[2] = param[1];
    if (dparam[1] * dparam[1] - 4 * dparam[2] * dparam[0] < 0)//单调递增的,只有一个实数解
    {
        if (1 == oneresult(param, range, 0, 1) && 1 == oneresult(param, range, 0, 0))
        {
            MessageBox(_T("无法求解!"));
        }
        else
        {
            if (1 == oneresult(param, range, 0, 1))
                oneresult(param, range, 0, 0);
            result[0] = dichotomy(param, range[0], range[1]);
           // cout << "" << result[0] << endl;
            CString x1,x2r, x2i,x3r,x3i;
            x1.Format(_T("%.4f"), result[0]);
            x2r.Format(_T("%.4f"), result[1]);
            x2i.Format(_T("%.4f"), result[2]);
            x3r.Format(_T("%.4f"), result[1]);
            x3i.Format(_T("%.4f"), -result[2]);
            Imagequation(result[0], &param[0], &param[1], &result[1], &result[2]);
            x1 = CString("只有一个实数解和两个虚数解!x1=")+x1 + 
                CString("x2=")+x2r+CString("+")+x2i+CString("x3=") + x2r + CString("-") + x2i;
            //  cout << "x2=" << result[1] << "+" << result[2] << "i" << endl;
           // cout << "x3=" << result[1] << "-" << result[2] << "i" << endl;
            MessageBox(x1, _T("The answer"));
        }
    }
    else
    {
        x1 = (-dparam[1] + sqrt(dparam[1] * dparam[1] - 4 * dparam[2] * dparam[0])) / (2 * dparam[0]);
        x2 = (-dparam[1] - sqrt(dparam[1] * dparam[1] - 4 * dparam[2] * dparam[0])) / (2 * dparam[0]);
        if (fx(param, x2) * fx(param, x1) <= 0)//极大值和极小值处函数值符号相反,则肯定有三个实数解
        {
            oneresult(param, range, x2, 0);
            result[0] = dichotomy(param, range[0], range[1]);
            oneresult(param, range, x1, 1);
            result[1] = dichotomy(param, range[0], range[1]);
            result[2] = dichotomy(param, x2, x1);
            CString x1, x2,x3;
            x1.Format(_T("%.4f"), result[0]);
            x2.Format(_T("%.4f"), result[1]);
            x3.Format(_T("%.4f"), result[2]);
            x1 = CString("有三个实数解! x1=") + x1 +
                CString(", x2=") + x2 + CString(", x3=") + x3 ;
            MessageBox(x1);
           // cout.setf(ios::fixed);
          //  cout << setprecision(6) << "x1=" << result[0] << endl;
          //  cout << setprecision(6) << "x2=" << result[1] << endl;
           // cout << setprecision(6) << "x3=" << result[2] << endl;
        }
        else//极大值和极小值处函数值符号相同,则肯定只有有一个实数解,两个虚数解
        {

          //  MessageBox(_T("只有一个实数解"));
            oneresult(param, range, x1, 1);
            result[0] = dichotomy(param, range[0], range[1]);
            //cout.setf(ios::fixed);
          //  cout << setprecision(6) << "x1=" << result[0] << endl;
            Imagequation(result[0], &param[0], &param[1], &result[1], &result[2]);
           // MessageBox(_T("有两个虚数解!"));            
            CString x1, x2r, x2i, x3r, x3i;
            x1.Format(_T("%.4f"), result[0]);
            x2r.Format(_T("%.4f"), result[1]);
            x2i.Format(_T("%.4f"), result[2]);
            x3r.Format(_T("%.4f"), result[1]);
            x3i.Format(_T("%.4f"), -result[2]);
            x1 = CString("只有一个实数解和两个虚数解! x1=") + x1 +
                CString(", x2=") + x2r + CString("+") + x2i + CString("i, x3=") + x2r + CString("-") + x2i+CString("i");
            MessageBox(x1, _T("The answer"));
            // cout << "!!" << endl;
           // cout << "x2=" << result[1] << "+" << result[2] << "i" << endl;
          //  cout << "x3=" << result[1] << "-" << result[2] << "i" << endl;
        }
    }
    UpdateData(FALSE);
}


