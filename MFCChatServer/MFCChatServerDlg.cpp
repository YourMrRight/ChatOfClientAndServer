﻿
// MFCChatServerDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MFCChatServer.h"
#include "MFCChatServerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCChatServerDlg 对话框



CMFCChatServerDlg::CMFCChatServerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCHATSERVER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCChatServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MESG_LIST, m_list);
}

BEGIN_MESSAGE_MAP(CMFCChatServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_MAL_BUTTON, &CMFCChatServerDlg::OnBnClickedMalButton)
	ON_BN_CLICKED(IDC_CAL_BUTTON, &CMFCChatServerDlg::OnBnClickedCalButton)
	ON_BN_CLICKED(IDC_START_BUTTON, &CMFCChatServerDlg::OnBnClickedStartButton)
	ON_BN_CLICKED(IDC_SEND_BUTTON, &CMFCChatServerDlg::OnBnClickedSendButton)
	ON_EN_CHANGE(IDC_PORT_EDIT, &CMFCChatServerDlg::OnEnChangePortEdit)
	ON_BN_CLICKED(IDC_CLEAR_BUTTON, &CMFCChatServerDlg::OnBnClickedClearButton)
	ON_BN_CLICKED(IDC_STOP_BUTTON4, &CMFCChatServerDlg::OnBnClickedStopButton4)
END_MESSAGE_MAP()


// CMFCChatServerDlg 消息处理程序

BOOL CMFCChatServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标
	GetDlgItem(IDC_PORT_EDIT)->SetWindowText(_T("5000"));

	GetDlgItem(IDC_START_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_STOP_BUTTON4)->EnableWindow(FALSE);
	GetDlgItem(IDC_SEND_BUTTON)->EnableWindow(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCChatServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCChatServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCChatServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CString CMFCChatServerDlg::CatShowString(CString strInfo, CString strMsg)
{
	CString strTime;
	CTime tmNow = CTime::GetCurrentTime();

	strTime = tmNow.Format("%X ");
	CString strShow;
	strShow = strTime + strShow;
	strShow += strInfo;
	strShow += strMsg;
	return strShow;
}

void CMFCChatServerDlg::OnBnClickedMalButton()
{
	// TODO: 在此添加控件通知处理程序代码
}

void CMFCChatServerDlg::OnBnClickedCalButton()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMFCChatServerDlg::OnBnClickedStartButton()
{
	//控制控件
	GetDlgItem(IDC_START_BUTTON)->EnableWindow(FALSE);
	GetDlgItem(IDC_STOP_BUTTON4)->EnableWindow(TRUE);
	GetDlgItem(IDC_SEND_BUTTON)->EnableWindow(TRUE);

	CString strPort;
	GetDlgItem(IDC_PORT_EDIT)->GetWindowTextW(strPort);

	USES_CONVERSION;
	LPCSTR szPort = (LPCSTR)T2A(strPort);

	int iPort = _ttoi(strPort);

	//创建服务器socket的对象
	m_server = new CServerSocket;

	if (!m_server->Create(iPort))
	{
		return;
	}

	if (!m_server->Listen())
	{
		return;
	}

	CString strShow;
	CString strInfo = _T("");
	CString strMsg = _T("建立服务");

	strShow = CatShowString(strInfo, strMsg);
	m_list.AddString(strShow);
	UpdateData(FALSE);





}


void CMFCChatServerDlg::OnBnClickedSendButton()
{
	CString strTmpmsg;
	GetDlgItem(IDC_SEND_EDIT)->GetWindowTextW(strTmpmsg);

	USES_CONVERSION;
	char* szSendbuf = T2A(strTmpmsg);
	m_chat->Send(szSendbuf, MAX_SERVER_BUF, 0);

	CString strShow;
	CString strInfo = _T("服务端：");
	strShow = CatShowString(strInfo, strTmpmsg);

	m_list.AddString(strShow);
	UpdateData(FALSE);
	//清空编辑框
	GetDlgItem(IDC_SEND_EDIT)->SetWindowTextW(_T(""));
}


void CMFCChatServerDlg::OnEnChangePortEdit()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCChatServerDlg::OnBnClickedClearButton()
{
	m_list.ResetContent();
}


void CMFCChatServerDlg::OnBnClickedStopButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_START_BUTTON)->EnableWindow(TRUE);
	GetDlgItem(IDC_STOP_BUTTON4)->EnableWindow(FALSE);
	GetDlgItem(IDC_SEND_BUTTON)->EnableWindow(FALSE);
	//回收资源
	m_server->Close();
	if (m_server != NULL)
	{
		delete m_server;
		m_server = NULL;
	}
	if (m_chat != NULL)
	{
		delete m_chat;
		m_chat = NULL;
	}

	CString strShow;

	strShow = CatShowString(_T(""), _T("服务器停止"));
	m_list.AddString(strShow);
	UpdateData(FALSE);
}