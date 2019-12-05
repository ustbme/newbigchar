// DiaClassSetting.cpp : 实现文件
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaClassSetting.h"
#include "afxdialogex.h"


// CDiaClassSetting 对话框

IMPLEMENT_DYNAMIC(CDiaClassSetting, CDialogEx)

CDiaClassSetting::CDiaClassSetting(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaClassSetting::IDD, pParent)
{

}

CDiaClassSetting::~CDiaClassSetting()
{
}

void CDiaClassSetting::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDD_CLASSSETTING3, m_classsetting3);
	DDX_Control(pDX, IDD_CLASSSETTING4, m_classsetting4);
	DDX_Control(pDX, IDD_CLASSSETTING5, m_classsetting5);
	DDX_Control(pDX, IDD_CLASSSETTING6, m_classsetting6);
	DDX_Control(pDX, IDD_CLASSSETTING7, m_classsetting7);
	DDX_Control(pDX, IDD_CLASSSETTING8, m_classsetting8);
	DDX_Control(pDX, IDD_CLASSSETTING9, m_classsetting9);
	DDX_Control(pDX, IDD_CLASSSETTING10, m_classsetting10);
	DDX_Control(pDX, IDD_CLASSSETTING11, m_classsetting11);
	DDX_Control(pDX, IDD_CLASSSETTING12, m_classsetting12);
	DDX_Control(pDX, IDD_CLASSSETTING13, m_classsetting13);
	DDX_Control(pDX, IDD_CLASSSETTING14, m_classsetting14);
	DDX_Control(pDX, IDD_CLASSSETTING15, m_classsetting15);
	DDX_Control(pDX, IDD_CLASSSETTING16, m_classsetting16);
	DDX_Control(pDX, IDD_CLASSSETTING17, m_classsetting17);
	DDX_Control(pDX, IDD_CLASSSETTING18, m_classsetting18);
	DDX_Control(pDX, IDD_CLASSSETTING19, m_classsetting19);
	DDX_Control(pDX, IDD_CLASSSETTING20, m_classsetting20);
	DDX_Control(pDX, IDD_CLASSSETTING21, m_classsetting21);
	DDX_Control(pDX, IDD_CLASSSETTING22, m_classsetting22);
	DDX_Control(pDX, IDD_CLASSSETTING23, m_classsetting23);
	DDX_Control(pDX, IDD_CLASSSETTING24, m_classsetting24);
}


BEGIN_MESSAGE_MAP(CDiaClassSetting, CDialogEx)
	ON_BN_CLICKED(IDC_CLASSSETTINGBUTTON2, &CDiaClassSetting::OnBnClickedClasssettingbutton2)
	ON_BN_CLICKED(IDC_CLASSSETTINGBUTTON0, &CDiaClassSetting::OnBnClickedClasssettingbutton0)
END_MESSAGE_MAP()


// CDiaClassSetting 消息处理程序


void CDiaClassSetting::OnBnClickedClasssettingbutton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strText(_T(""));


	CStdioFile file;
	file.Open(_T("..\\classsetting.txt"),CFile::modeCreate|CFile::modeWrite|CFile::typeText);
	GetDlgItemText(IDD_CLASSSETTING1, strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING2,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING3,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING4,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING5,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING6,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING7,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING8,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING9,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING10,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING11,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING12,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING13,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING14,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING15,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING16,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING17,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING18,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING19,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING20,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING21,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING22,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING23,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDD_CLASSSETTING24,  strText);
	file.WriteString(strText+"\n");


	file.Close();

}


void CDiaClassSetting::OnBnClickedClasssettingbutton0()
{
	// TODO: 在此添加控件通知处理程序代码
	CStdioFile file;
	file.Open(_T("..\\classsetting.txt"),CFile::modeRead);

	CString strText =_T( "");


	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING1,strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING2, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING3, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING4, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING5, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING6, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING7, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING8, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING9, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING10, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING11, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING12, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING13, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING14, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING15, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING16, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING17, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING18, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING19, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING20, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING21, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING22, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING23, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDD_CLASSSETTING24, strText);

	UpdateData(FALSE);
	file.Close();
}
