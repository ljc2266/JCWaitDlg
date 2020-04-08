
// JCTestWaitDlgDlg.h : 头文件
//

#pragma once
#include "JCWaitDlg.h"
#include "afxcmn.h"
// CJCTestWaitDlgDlg 对话框
class CJCTestWaitDlgDlg : public CDialogEx
{
// 构造
public:
	CJCTestWaitDlgDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_JCTESTWAITDLG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
