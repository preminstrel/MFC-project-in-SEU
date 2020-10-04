// INT.cpp: 实现文件
//

#include "pch.h"
#include "Calculate_atom.h"
#include "INT.h"
#include "afxdialogex.h"


// INT 对话框

IMPLEMENT_DYNAMIC(INT, CDialogEx)

INT::INT(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

INT::~INT()
{
}

void INT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(INT, CDialogEx)
END_MESSAGE_MAP()


// INT 消息处理程序
