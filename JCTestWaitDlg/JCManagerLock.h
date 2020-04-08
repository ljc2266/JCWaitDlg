#pragma once
#include "jclock.h"
class JCManagerLock :
	public JCLock
{
protected:
	JCManagerLock(void);
public:
	~JCManagerLock(void);
	void Init(string name);
	void Lock(DWORD dwMilliseconds = INFINITE);
	void UnLock();
	static JCManagerLock* GetInstance();
private:
	static JCManagerLock *m_pJCManagerLock;
	CRITICAL_SECTION m_CS;
};

