#pragma once
#include <Windows.h>
#include <string>
using namespace std;
class JCLock
{
public:
	JCLock(void);
	virtual ~JCLock(void);
	virtual void Init(string name)=0;
	virtual void Lock(DWORD dwMilliseconds = INFINITE)=0;
	virtual void UnLock()=0;
};

