
// MFCChatServerDlg.h: 头文件
//

#pragma once
#include "CServerSocket.h"
#include "CChatSocket.h"

// CMFCChatServerDlg 对话框
class CMFCChatServerDlg : public CDialogEx
{
// 构造
public:
	CMFCChatServerDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCHATSERVER_DIALOG };
#endif

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
public:
	afx_msg void OnBnClickedMalButton();
	afx_msg void OnBnClickedMalButton2();
	afx_msg void OnBnClickedCalButton2();
	afx_msg void OnBnClickedCalButton();
	afx_msg void OnBnClickedStartButton();
	CString CatShowString(CString strInfo, CString strMsg);
	CListBox m_list;
	CServerSocket* m_server;
	CChatSocket* m_chat;
	CTime m_tm;
	afx_msg void OnBnClickedSendButton();
	afx_msg void OnEnChangePortEdit();
	afx_msg void OnBnClickedClearButton();
	afx_msg void OnBnClickedStopButton4();
};
