#pragma once
#include "afx.h"
#include "socket\SocketClient.h"
#include "AppInfo.h"
#include "cmdList.h"

// �û��Զ�����Ϣ
enum UserMsg
{
	MSG_InsertApp = (WM_USER + 100), 
	MSG_UpdateApp, 
	MSG_DeleteApp, 
	MSG_ChangeColor, 
};

#define COLOR_DEFAULT 0		//Ĭ��������ɫ
#define COLOR_RED 2048		// ��ɫ����
#define COLOR_YELLOW 2049	// ��ɫ����

// CAppListCtrl

class CAppListCtrl : public CListCtrl
{
	DECLARE_DYNAMIC(CAppListCtrl)

	int m_nIndex;		// ��ǰѡ����

public:
	CAppListCtrl();
	virtual ~CAppListCtrl();

	// ��ʼ��������
	void AddColumns(const CString its[], int cols);

	// ƽ���ֲ�����
	void AvgColumnWidth(int cols);

	//////////////////////////////////////////////////////////////////////////
	// ����4�������漰���߳�

	// ������[m]
	void InsertAppItem(const char* port);

	// ɾ����[m]
	void DeleteAppItem(const char* port);

	// ������[m]
	void UpdateAppItem(const char* port, const AppInfo &it);

	// ���������[m]
	void Clear();

	CRITICAL_SECTION m_cs;

	inline void Lock() { EnterCriticalSection(&m_cs); }

	inline void Unlock() { LeaveCriticalSection(&m_cs); }

	std::string getCurSelNo();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnNMRClick(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void RestartApp();
	afx_msg void QueryAppInfo();
	afx_msg void OnLvnColumnclick(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void StopApp();
	afx_msg void StartApp();
	afx_msg void UpdateApp();
	afx_msg LRESULT MessageInsertApp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT MessageUpdateApp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT MessageDeleteApp(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT MessageChangeColor(WPARAM wParam, LPARAM lParam);
	afx_msg void OnNMCustomdraw(NMHDR *pNMHDR, LRESULT *pResult);
};