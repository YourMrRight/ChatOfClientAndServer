#include "pch.h"
#include"MFCChatServerDlg.h"
#include "CChatSocket.h"
#include"MFCChatServer.h"
CChatSocket::CChatSocket()
{
}

CChatSocket::~CChatSocket()
{
}

void CChatSocket::OnReceive(int nErrorCode)
{ 
	
	CMFCChatServerDlg* dlg = (CMFCChatServerDlg*)AfxGetApp()->GetMainWnd();
	char szRecvBuf[MAX_SERVER_BUF] = { 0 };
	Receive(szRecvBuf, MAX_SERVER_BUF, 0);
	USES_CONVERSION;
	CString strRecvMsg = A2W(szRecvBuf);

	CString strShow;
	CString strInfo = _T("");
	strShow = dlg->CatShowString(strInfo, strRecvMsg);

	dlg->m_list.AddString(strShow);

	CAsyncSocket::OnReceive(nErrorCode);
}
