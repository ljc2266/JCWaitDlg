
// JCTestWaitDlgDlg.h : ͷ�ļ�
//

#pragma once
#include "JCWaitDlg.h"
#include "afxcmn.h"
// CJCTestWaitDlgDlg �Ի���
class CJCTestWaitDlgDlg : public CDialogEx
{
// ����
public:
	CJCTestWaitDlgDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_JCTESTWAITDLG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	static DWORD WINAPI ProgressThreadProc(JCThreadManager* pThreadManager);
public:
	afx_msg void OnBnClickedTestbutton();
private:
	CProgressCtrl m_ProgressCtrl;
};
