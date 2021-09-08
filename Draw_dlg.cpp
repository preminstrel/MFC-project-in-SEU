// Draw_dlg.cpp: 实现文件
//

#include "pch.h"
#include "Calculate_atom.h"
#include "Draw_dlg.h"
#include "afxdialogex.h"
#pragma warning(disable:4996)
// Draw_dlg 对话框

IMPLEMENT_DYNAMIC(Draw_dlg, CDialogEx)

Draw_dlg::Draw_dlg(CWnd* pParent /*=nullptr*/)
: CDialogEx(IDD_DIALOG11, pParent)

	{
	  //AFX_MANAGE_STATE(AfxGetStaticModuleState());
	//	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
		// Load two cursors
}

Draw_dlg::~Draw_dlg()
{
}


BEGIN_MESSAGE_MAP(Draw_dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//	ON_WM_NCMOUSEMOVE()
//ON_BN_CLICKED(IDC_RADIO2, &Draw_dlg::OnBnClickedRadio2)
//ON_BN_CLICKED(IDC_RADIO3, &Draw_dlg::OnBnClickedRadio3)
//ON_BN_CLICKED(IDC_RADIO4, &Draw_dlg::OnBnClickedRadio4)
//ON_BN_CLICKED(IDC_RADIO5, &Draw_dlg::OnBnClickedRadio5)
END_MESSAGE_MAP()


// Draw_dlg 消息处理程序
