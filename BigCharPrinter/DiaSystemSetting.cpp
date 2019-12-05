// DiaSystemSetting.cpp : 实现文件
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaSystemSetting.h"
#include "afxdialogex.h"


// CDiaSystemSetting 对话框

IMPLEMENT_DYNAMIC(CDiaSystemSetting, CDialogEx)

CDiaSystemSetting::CDiaSystemSetting(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaSystemSetting::IDD, pParent)
{

}

CDiaSystemSetting::~CDiaSystemSetting()
{
}

void CDiaSystemSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDD_SYSTEM_SETTING1, m_system_setting1);
	DDX_Control(pDX, IDD_SYSTEM_SETTING2, m_system_setting2);
	DDX_Control(pDX, IDD_SYSTEM_SETTING3, m_system_setting3);
	DDX_Control(pDX, IDD_SYSTEM_SETTING4, m_system_setting4);
	DDX_Control(pDX, IDD_SYSTEM_SETTING5, m_system_setting5);
}


BEGIN_MESSAGE_MAP(CDiaSystemSetting, CDialogEx)
	ON_BN_CLICKED(IDC_SYSTEMBUTTON1, &CDiaSystemSetting::OnBnClickedSystembutton1)
	ON_BN_CLICKED(IDC_SYSTEMBUTTON2, &CDiaSystemSetting::OnBnClickedSystembutton2)
	ON_BN_CLICKED(IDC_SYSTEMBUTTON3, &CDiaSystemSetting::OnBnClickedSystembutton3)
END_MESSAGE_MAP()


// CDiaSystemSetting 消息处理程序


void CDiaSystemSetting::OnBnClickedSystembutton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CStdioFile file;
	file.Open(_T("..\\system_setting.txt"),CFile::modeRead);

	CString strText =_T( "");


	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_SYSTEM_SETTING1,strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_SYSTEM_SETTING2, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_SYSTEM_SETTING3, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_SYSTEM_SETTING4, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_SYSTEM_SETTING5, strText);


	UpdateData(FALSE);
	file.Close();
}


void CDiaSystemSetting::OnBnClickedSystembutton2()
{
	// TODO: 在此添加控件通知处理程序代码

	CString strText(_T(""));


	CStdioFile file;
	file.Open(_T("..\\system_setting.txt"),CFile::modeCreate|CFile::modeWrite|CFile::typeText);
	GetDlgItemText(IDD_SYSTEM_SETTING1, strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_SYSTEM_SETTING2,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_SYSTEM_SETTING3,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_SYSTEM_SETTING4,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_SYSTEM_SETTING5,  strText);
	file.WriteString(strText+"\n");


	file.Close();

}


void CDiaSystemSetting::OnBnClickedSystembutton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CStdioFile file;
	file.Open(_T("..\\origin_system.txt"),CFile::modeRead);

	CString strText =_T( "");


	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_SYSTEM_SETTING1,strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_SYSTEM_SETTING2, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_SYSTEM_SETTING3, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_SYSTEM_SETTING4, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_SYSTEM_SETTING5, strText);


	UpdateData(FALSE);
	file.Close();
}
