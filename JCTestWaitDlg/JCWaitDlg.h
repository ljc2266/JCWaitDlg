#pragma once
#include "JCThreadManager.h"
#include "PictureEx.h"

// CJCWaitDlg �Ի���

class CJCWaitDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CJCWaitDlg)

public:
	CJCWaitDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CJCWaitDlg();

// �Ի�������
	enum { IDD = IDD_JCWAITDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	JCThreadManager m_ThreadManager;
	CWinThread* m_pWinThread;
	CPictureEx m_PictureEx;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
public:
	void Start(THREADPROC pfnThreadProc,LPVOID pParam);
};
