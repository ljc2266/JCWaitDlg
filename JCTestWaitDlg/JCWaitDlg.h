#pragma once
#include "JCThreadManager.h"
#include "PictureEx.h"

// CJCWaitDlg 对话框

class CJCWaitDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CJCWaitDlg)

public:
	CJCWaitDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CJCWaitDlg();

// 对话框数据
	enum { IDD = IDD_JCWAITDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
