#pragma once
#include <queue>
#include <string>
#include "JCManagerLock.h"
#include "JCUserLock.h"
// CTDThread ÃüÁîÄ¿±ê
using namespace std;

class JCThreadManager;
typedef DWORD (WINAPI *THREADPROC)(JCThreadManager*);

enum THREADEVENT
{
	ThreadStart,
	ThreadClose
};

class JCThreadManager
{
public:
	JCThreadManager();
	virtual ~JCThreadManager();
	static DWORD WINAPI ThreadManagerProc(LPVOID lparam);
	void InitManager(THREADPROC pfnThreadProc,void* pParam,bool bStart = true,string lockName="");
	void Start();
	void End();
	bool IsClose();
	bool IsRun();
	void WaitForClose(DWORD dwMilliseconds = INFINITE);
	void* GetParam();
	void Lock(DWORD dwMilliseconds = INFINITE);
	void UnLock();
private:
	THREADPROC m_pfnThreadProc;
	HANDLE m_hUserThread;
	HANDLE m_hManagerThread;
	void* m_pParam;
	bool m_bClose;
	bool m_bThreadManagerClose;
	JCLock* m_pManagerLock;
	JCLock* m_pUserLock;
	queue<THREADEVENT> m_queTreadEvent;
	static int m_nRunNumner;
};


