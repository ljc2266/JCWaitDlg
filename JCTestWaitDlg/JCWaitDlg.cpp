// JCWaitDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "JCTestWaitDlg.h"
#include "JCWaitDlg.h"
#include "afxdialogex.h"


// CJCWaitDlg 对话框

IMPLEMENT_DYNAMIC(CJCWaitDlg, CDialogEx)

CJCWaitDlg::CJCWaitDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CJCWaitDlg::IDD, pParent)
	, m_ThreadManager()
{

}

CJCWaitDlg::~CJCWaitDlg()
{
}

void CJCWaitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_GIFSTATIC, m_PictureEx);
}


BEGIN_MESSAGE_MAP(CJCWaitDlg, CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CJCWaitDlg 消息处理程序


BOOL CJCWaitDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN&&pMsg->wParam==VK_RETURN)
	{
		return FALSE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


BOOL CJCWaitDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	MoveWindow(0,0,108,114);
	CenterWindow();
	COLORREF maskColor = RGB(255,255,255);   //掩码颜色  
	SetWindowLong(this->GetSafeHwnd(),  GWL_EXSTYLE,   GetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE)| 0x80000);  //设定窗体使用扩展模式   
	SetLayeredWindowAttributes(maskColor,0,LWA_COLORKEY);
	m_PictureEx.MoveWindow(0,0,108,114);
	m_PictureEx.Load(_T("waitimage.gif"));
	m_PictureEx.Draw();
	m_ThreadManager.Start();
	SetTimer(0,100,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


BOOL CJCWaitDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	return FALSE;
	return CDialogEx::OnEraseBkgnd(pDC);
}


void CJCWaitDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 0)
	{
		if (!m_ThreadManager.IsRun())
		{
			SendMessage(WM_CLOSE);
		}
	}
	CDialogEx::OnTimer(nIDEvent);
}


void CJCWaitDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_PictureEx.DestroyWindow();
	CDialogEx::OnClose();
}

void CJCWaitDlg::Start(THREADPROC pfnThreadProc,LPVOID pParam)
{
	m_ThreadManager.InitManager(pfnThreadProc,pParam);
}