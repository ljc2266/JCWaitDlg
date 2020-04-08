// JCWaitDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "JCTestWaitDlg.h"
#include "JCWaitDlg.h"
#include "afxdialogex.h"


// CJCWaitDlg �Ի���

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


// CJCWaitDlg ��Ϣ�������


BOOL CJCWaitDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (pMsg->message == WM_KEYDOWN&&pMsg->wParam==VK_RETURN)
	{
		return FALSE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


BOOL CJCWaitDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	MoveWindow(0,0,108,114);
	CenterWindow();
	COLORREF maskColor = RGB(255,255,255);   //������ɫ  
	SetWindowLong(this->GetSafeHwnd(),  GWL_EXSTYLE,   GetWindowLong(this->GetSafeHwnd(),GWL_EXSTYLE)| 0x80000);  //�趨����ʹ����չģʽ   
	SetLayeredWindowAttributes(maskColor,0,LWA_COLORKEY);
	m_PictureEx.MoveWindow(0,0,108,114);
	m_PictureEx.Load(_T("waitimage.gif"));
	m_PictureEx.Draw();
	m_ThreadManager.Start();
	SetTimer(0,100,NULL);
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


BOOL CJCWaitDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	return FALSE;
	return CDialogEx::OnEraseBkgnd(pDC);
}


void CJCWaitDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	m_PictureEx.DestroyWindow();
	CDialogEx::OnClose();
}

void CJCWaitDlg::Start(THREADPROC pfnThreadProc,LPVOID pParam)
{
	m_ThreadManager.InitManager(pfnThreadProc,pParam);
}