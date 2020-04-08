#pragma once
#include "jclock.h"
class JCUserLock :
	public JCLock
{
public:
	JCUserLock(void);
	~JCUserLock(void);
	void Init(string name);
	void Lock(DWORD dwMilliseconds = INFINITE);
	void UnLock();
private:
	HANDLE m_hEvent;
};

