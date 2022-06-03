// Prime_factor.cpp: 实现文件
//

#include "pch.h"
#include "Calculate_atom.h"
#include "Prime_factor.h"
#include "afxdialogex.h"


// Prime_factor 对话框

IMPLEMENT_DYNAMIC(Prime_factor, CDialogEx)

Prime_factor::Prime_factor(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG10, pParent)
	, n(_T(""))
{

}

Prime_factor::~Prime_factor()
{
}

void Prime_factor::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, n);
}


BEGIN_MESSAGE_MAP(Prime_factor, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Prime_factor::OnBnClickedButton1)
END_MESSAGE_MAP()

CString M("");
// Prime_factor 消息处理程序 
void PrimeDecomposition(int k)

{   CString x;
     x.Format(_T("%d"), k);
     M += x + CString("=");
   // cout << k << "=";
    if (k < 2)
        M = CString("不能够进行质因数分解");
    else if (k == 4)
        M += CString("2*2");
    else
    {

        for (int i = 2; i < sqrt(k); i++)
        {
            while (k != i)//这里用while循环是考虑到质因子中有可能有重复个i的情况
            {
                if (k % i == 0)
                {
                    x.Format(_T("%d"), i);
                    M += x + CString("*");
                    //cout << i << "*";
                    k = k / i;
                }
                else
                    break;
            }
        }
        x.Format(_T("%d"), k);
        M += x ;
    }
}
void Prime_factor::OnBnClickedButton1()
{
    UpdateData(TRUE);
    long num = 0;
    num = atof(n);
        PrimeDecomposition(num);
        MessageBox(M, _T("The answer")); M = CString("");
    UpdateData(FALSE);
}
