
//  LogTrace.h -- Interface for the CLogTrace class
//  A class to do debug logging


#pragma once


class CLogTrace
{
// Construction/Destruction
public:
	CLogTrace();
	~CLogTrace();

// Attributes
public:
	CString m_strAppName;

protected:
	BOOL m_bActive;
	CString m_strFileName;
	BOOL m_bTimeStamp;

// Operations
public:
	void WriteLine(LPCTSTR szLine);
	void WriteLine(LPCTSTR szFormat, LPCTSTR szAddInfo);
	void WriteLine(LPCTSTR szFormat, int nAddInfo);
	void ResetFile();
	void OnStartup(BOOL bActive, BOOL bTimeStamp);
	void SetFileName(LPCTSTR szFileName);

protected:


// Inlines
public:
	inline void SetActive(BOOL bSet)
	{
		m_bActive = bSet;
	}
	inline CString GetFileName()
	{
		return m_strFileName;
	}
};


