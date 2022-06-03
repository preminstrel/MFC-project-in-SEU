
// Calculate_atomDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Calculate_atom.h"
#include "Calculate_atomDlg.h"
#include"Leisure.h"
#include "afxdialogex.h"
#include  "stack"
#include "math.h"
//#include<string>;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


using namespace std;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
void CAboutDlg::OnBnClickedOk() 
{
	CDialogEx::OnOK();
}
CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CAboutDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CCalculateatomDlg 对话框


CCalculateatomDlg::CCalculateatomDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATE_ATOM_DIALOG, pParent)
	, m_str(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON2);
}

void CCalculateatomDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
	DDX_Text(pDX, IDC_EDIT1, m_str);
}

BEGIN_MESSAGE_MAP(CCalculateatomDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CCalculateatomDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON7, &CCalculateatomDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON34, &CCalculateatomDlg::OnBnClickedButton34)
	ON_BN_CLICKED(IDC_BUTTON8, &CCalculateatomDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON5, &CCalculateatomDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON11, &CCalculateatomDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON13, &CCalculateatomDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON31, &CCalculateatomDlg::OnBnClickedButton31)
	ON_BN_CLICKED(IDC_BUTTON26, &CCalculateatomDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON10, &CCalculateatomDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON14, &CCalculateatomDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON27, &CCalculateatomDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON21, &CCalculateatomDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON28, &CCalculateatomDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON22, &CCalculateatomDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON3, &CCalculateatomDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, &CCalculateatomDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON12, &CCalculateatomDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON32, &CCalculateatomDlg::OnBnClickedButton32)
	ON_BN_CLICKED(IDC_BUTTON23, &CCalculateatomDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON15, &CCalculateatomDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON17, &CCalculateatomDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON9, &CCalculateatomDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON16, &CCalculateatomDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON18, &CCalculateatomDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CCalculateatomDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CCalculateatomDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON24, &CCalculateatomDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CCalculateatomDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON29, &CCalculateatomDlg::OnBnClickedButton29)
	ON_COMMAND(ID_HELP_INSTRUCTIONS, &CCalculateatomDlg::OnHelpInstructions)
//	ON_COMMAND(ID_EDIT_COPY32775, &CCalculateatomDlg::OnEditCopy32775)
ON_COMMAND(ID_MODE_MOLECULEMODE, &CCalculateatomDlg::OnModeMoleculemode)
ON_COMMAND(ID_MODE_LEISUREMODE, &CCalculateatomDlg::OnModeLeisuremode)
ON_COMMAND(ID_CONTACTUS, &CCalculateatomDlg::OnContactus)
ON_COMMAND(ID_32785, &CCalculateatomDlg::On32785)
ON_COMMAND(ID_MODE_DRAWMODE, &CCalculateatomDlg::OnModeDrawmode)
END_MESSAGE_MAP()


// CCalculateatomDlg 消息处理程序

BOOL CCalculateatomDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CLoginDlg login;
	//if (login.DoModal() != IDOK) return FALSE;
	if (login.DoModal() != IDOK)
	{
		PostQuitMessage(0);
		return FALSE;
	}
	// 加载菜单资源
	m_Menu.LoadMenu(IDR_MENU1);
	// 为对话框设置菜单
	this->SetMenu(&m_Menu);
	// 将“关于...”菜单项添加到系统菜单中。

	Dialog1.Create(IDD_DIALOG1, this);
	Dialog1.SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOSIZE);
	Dialog1.ShowWindow(SW_HIDE);

	Dialog0.Create(IDD_DIALOG13, this);
	Dialog0.SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOSIZE);
	Dialog0.ShowWindow(SW_HIDE);

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalculateatomDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculateatomDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculateatomDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CCalculateatomDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
//转换UNICODE的情况，（可以防止下面的const char*转换为CString的过程中的错误）

const char lNumFront = '[';//两个数字之间的分隔符

const char rNumBack = ']';//两个数字之间的分隔符

const char *a = "+-*/^";
CString LPCT_OPCH(a); //保存运算符 
// 出现不存在从CStrign到const char*的转换，
 //可以将项目属性的字符集设置从"使用Unicode字符集“转换为”使用多字字符集“，
 //点击”项目“----"属性"----"配置属性"----”常规“----”字符集“更改即可
 INT CCalculateatomDlg::PriorityLevel(char op)
 {
	 if (op == '+' || op == '-')
		 return 1;
	 if (op == '*' || op == '/')
		 return 2;
	 if (op == '^')
		 return 3;
	 return 0;
 }
 BOOL CCalculateatomDlg::IsOpr(char c)
 {
	 for (int i = 0; i < LPCT_OPCH.GetLength(); i++) {
		 if (c == LPCT_OPCH[i]) return true;
	 }
	 return false;
 }


 CString CCalculateatomDlg::minusjudge(CString a)
 {
	 CString transres = "";
	 for (int i = 0; i < a.GetLength(); i++)
	 {
		 char c = a[i];
		 if (c == '(' && a[i + 1] == '-')
			 transres += '0';
			 transres += c;
	 }
	 return transres;
 }


 //中缀转为后缀
 CString CCalculateatomDlg::InfixToSuffix(CString szIn)
 {
	 CString ans="";
	 stack<char>Optr;
	 for (int i = 0; i < szIn.GetLength(); i++) {
		 char c = szIn[i];
		 if (c >= '0' && c <= '9' || c == '.') //数字and"."直接输出
		 {
			 ans += lNumFront;
			 ans += c;
			 while (i + 1 < szIn.GetLength() && szIn[i + 1] >= '0' && szIn[i + 1] <= '9'|| szIn[i + 1] == '.') {
				 ans += szIn[i + 1]; ++i;
			 }
			 ans += rNumBack;
		 }
		 else if (Optr.empty())
		 {
			 Optr.push(c);
		 }
		 else if (c == '(') //无条件压栈
		 {
			 Optr.push(c);
		 }
		 else if (c == ')')  //弹栈并输出
		 {
			 while (Optr.top() != '(')
			 {
				 if (Optr.empty()) //基于安全性的考虑
				 {
					 AfxMessageBox(_T("提示:括号不匹配！"));
					 ASSERT(Optr.empty());
					 //return ans;
				 }
				 ans += Optr.top();
				 Optr.pop();
			 }
			 Optr.pop();
		 }
		 else//其他条件即为 + - * / ^
		 {
			 if (PriorityLevel(c) > PriorityLevel(Optr.top()))
				 Optr.push(c);
			 else
			 {
				 while (!Optr.empty() && PriorityLevel(c) <= PriorityLevel(Optr.top()))
				 {
					 ans += Optr.top();
					 Optr.pop();
				 }
				 Optr.push(c);
			 }
		 }
	 }
	 while (!Optr.empty())
	 {
		 ans += Optr.top();
		 Optr.pop();
	 }
	 return ans;
 }
 
 //下面是后缀表达式得出答案的过程
 double CCalculateatomDlg::SuffixToResult(CString szSuffix)
 {
	 double res;
	 stack<double>OpNb;
	 for (int i = 0; i < szSuffix.GetLength(); i++) {
		 if (szSuffix[i] == lNumFront) //如遇到数字分隔符号
		 {
			 int nSta = ++i, nCount = 1;
			 while (rNumBack != szSuffix[i]) { i++; nCount++; }
			 OpNb.push(atof((szSuffix.Mid(nSta, nCount))));
		 }
		 else { //遇到运算符
			 double lt, rt, tmp;
			 rt = OpNb.top(); OpNb.pop();
			 lt = OpNb.top(); OpNb.pop();
			 switch (szSuffix[i])
			 {
			 case '+':
				 tmp = lt + rt;
				 break;
			 case '-':
				 tmp = lt - rt;
				 break;
			 case '*':
				 tmp = lt * rt;
				 break;
			 case '/':
				 tmp = lt / rt;
				 break;
			 case '^':
				 tmp = pow(lt, rt);
				 break;
			 }
			 OpNb.push(tmp);
		 }
	 }
	 res = OpNb.top(); OpNb.pop();
	 return res;
 }


////“加法”键的实现
void CCalculateatomDlg::OnBnClickedButton7()
{/////////////////////////plus--"+"//////////////////////////
	UpdateData(TRUE);
	m_str = m_str + '+';
	UpdateData(FALSE);
}
///C
void CCalculateatomDlg::OnBnClickedButton8()
{////////////////////"C"/////////////////////
	UpdateData(TRUE);
	m_str = "";
	UpdateData(FALSE);
}
///delete
void CCalculateatomDlg::OnBnClickedButton5()
{///////////////////"Delete"////////////////
	UpdateData(TRUE);//将屏幕中的数据转换到变量中

	if (!m_str.IsEmpty())//如果字符串不为空
	{
		m_str = m_str.Left(m_str.GetLength() - 1);
	}
	UpdateData(FALSE);
}
//“减法”键的实现
void CCalculateatomDlg::OnBnClickedButton11()
{//////////////////////////////minus“-”/////////////////////////////////
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '-';
	UpdateData(FALSE);
}

//“乘法”键的实现
void CCalculateatomDlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '*';
	UpdateData(FALSE);
}

//“除法”键的实现
void CCalculateatomDlg::OnBnClickedButton31()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '/';
	UpdateData(FALSE);
}

//“指数”运算符的实现
void CCalculateatomDlg::OnBnClickedButton26()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '^';
	UpdateData(FALSE);

}

//“左括号”的实现
void CCalculateatomDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '(';
	UpdateData(FALSE);
}

//“右括号”的实现
void CCalculateatomDlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + ')';
	UpdateData(FALSE);

}

//“等于号”的实现
void CCalculateatomDlg::OnBnClickedButton34()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	double result_atom =SuffixToResult(InfixToSuffix(minusjudge(m_str)));
	m_str.Format(_T("%.4f"), result_atom);
	UpdateData(FALSE);
}

//////the record of the number "1,2,3,4,5,6,7,8,9,0"///////
void CCalculateatomDlg::OnBnClickedButton27()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '1';
	UpdateData(FALSE);
}
void CCalculateatomDlg::OnBnClickedButton21()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '2';
	UpdateData(FALSE);
}
void CCalculateatomDlg::OnBnClickedButton28()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '3';
	UpdateData(FALSE);
}
void CCalculateatomDlg::OnBnClickedButton22()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '4';
	UpdateData(FALSE);
}
void CCalculateatomDlg::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '5';
	UpdateData(FALSE);
}
void CCalculateatomDlg::OnBnClickedButton17()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '6';
	UpdateData(FALSE);
}
void CCalculateatomDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '7';
	UpdateData(FALSE);
}
void CCalculateatomDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '8';
	UpdateData(FALSE);
}
void CCalculateatomDlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '9';
	UpdateData(FALSE);
}
void CCalculateatomDlg::OnBnClickedButton23()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '0';
	UpdateData(FALSE);
}
void CCalculateatomDlg::OnBnClickedButton32()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_str = m_str + '.';
	UpdateData(FALSE);
}


void CCalculateatomDlg::OnBnClickedButton9()
{
	UpdateData(TRUE);
	if(_ttof(m_str)!=int(_ttof(m_str)))
		MessageBox(TEXT("Please input integer."));
	else 
	{
		int i = 1;
		int result=1;
        int num = _ttof(m_str);
		for (i = 1; i <= num; i++)
			result *= i;
	    m_str.Format(TEXT("%d"), result);
	}
	
	UpdateData(FALSE);
}

////tan function---realize
void CCalculateatomDlg::OnBnClickedButton16()
{	UpdateData(TRUE);
	double result = tan(_ttof(m_str));
	m_str.Format(TEXT("%f"), result);
	UpdateData(FALSE);
}

//cos function---realize
void CCalculateatomDlg::OnBnClickedButton18()
{
	UpdateData(TRUE);
	double result = cos(_ttof(m_str));
	m_str.Format(TEXT("%f"), result);
	UpdateData(FALSE);
}

//sin function---realize
void CCalculateatomDlg::OnBnClickedButton19()
{
	UpdateData(TRUE);
	double result = sin(_ttof(m_str));
	m_str.Format(TEXT("%f"), result);
	UpdateData(FALSE);
}

//ln function---realize
void CCalculateatomDlg::OnBnClickedButton20()
{
	UpdateData(TRUE);
	double result = log(_ttof(m_str));
	m_str.Format(TEXT("%f"), result);
	UpdateData(FALSE);
}

//e^x
void CCalculateatomDlg::OnBnClickedButton24()
{
	const double e = 2.7182818284590452353;
	UpdateData(TRUE);
	double result = pow(e,_ttof(m_str));
	m_str.Format(TEXT("%f"), result);
	UpdateData(FALSE);
}

//ans^2
void CCalculateatomDlg::OnBnClickedButton25()
{
	UpdateData(TRUE);
	double result = pow( _ttof(m_str),2);
	m_str.Format(TEXT("%f"), result);
	UpdateData(FALSE);
}


void CCalculateatomDlg::OnBnClickedButton29()
{
	UpdateData(TRUE);
	double result = pow(_ttof(m_str), 0.5);
	m_str.Format(TEXT("%f"), result);
	UpdateData(FALSE);
}



//MENUE
 
void CCalculateatomDlg::OnHelpInstructions()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox("File    ：可以查看本软件的设计报告\nmode：提供更多的数学计算(Molecule mode),\n绘图功能(Draw mode)以及休闲功能(Leisure mode)\nC      ：归零键\nDelete：清除键\n（       ：左括号\n）    ：右括号\n ^ ：乘方\n + ：加运算\n - ：减运算\n×      ：乘运算\n / ：除运算\n = ：输出结果\ntan（Ans） ：该数的正切值\nsin（Ans）  ：该数的正弦值\ncos（Ans） ：该数的余弦值\n（Ans)!  ：阶乘\nln （Ans）  ：自然对数\ne^ （Ans）  ：e的Ans次方\n（Ans） ^ 2  ：平方\nsqrt（Ans）：平方根", _T("使用说明"));
}




///copy///
void CCalculateatomDlg::OnEditCopy32775()
{
	// TODO: 在此添加命令处理程序代码
 
 
}


void CCalculateatomDlg::OnModeMoleculemode()
{
	//ShellExecute(NULL, "open", "C:/Users/12647/Desktop/molecule/molecule/Debug/molecule.exe", NULL, NULL, SW_SHOWNORMAL);
     //CDialog* dlg = new CDialog;
	//dlg->Create(MAKEINTRESOURCE(IDD_DIALOG1));
	//dlg->ShowWindow(1);
	//this->ShowWindow(0);
	Dialog1.ShowWindow(SW_SHOW);//显示子对话框1
     
}


void CCalculateatomDlg::OnModeLeisuremode()
{
	// TODO: 在此添加命令处理程序代码
	Dialog0.ShowWindow(SW_SHOW);
}


void CCalculateatomDlg::OnContactus()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox("东南大学九龙湖校区桃园3D435室\n孙寒石\t张扬\t陶星宇\t车旭明", _T("联系我们"));
}


void CCalculateatomDlg::On32785()
{
	// TODO: 在此添加命令处理程序代码
	ShellExecute(NULL, "open", "计算机综合课程设计报告.doc", NULL, NULL, SW_SHOWNORMAL);
}


void CCalculateatomDlg::OnModeDrawmode()
{
	// TODO: 在此添加命令处理程序代码
	ShellExecute(NULL, "open", "MFC_DRAW.exe", NULL, NULL, SW_SHOWNORMAL);
}

