// DiaPrintParam.cpp : 实现文件
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaPrintParam.h"
#include "afxdialogex.h"
#include <locale>

// CDiaPrintParam 对话框

IMPLEMENT_DYNAMIC(CDiaPrintParam, CDialogEx)

CDiaPrintParam::CDiaPrintParam(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaPrintParam::IDD, pParent)
{

}

CDiaPrintParam::~CDiaPrintParam()
{
}

void CDiaPrintParam::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CharBide, m_bide);
	DDX_Control(pDX, IDC_SPIN_BideChange, m_bidechange);
	DDX_Control(pDX, IDC_EDIT_Size, m_size);
	DDX_Control(pDX, IDC_SPIN_SizeChange, m_sizechange);
	DDX_Control(pDX, IDC_EDIT_Delay, m_delay);
	DDX_Control(pDX, IDC_SPIN_DelayChange, m_delaychange);
	DDX_Control(pDX, IDC_EDIT_Space, m_space);
	DDX_Control(pDX, IDC_SPIN_SpaceChange, m_spacechangr);
	DDX_Control(pDX, IDC_EDIT_PluseNum, m_plusenum);
	DDX_Control(pDX, IDC_SPIN_PluseNumChange, m_plusenumchange);
	DDX_Control(pDX, IDC_EDIT_PrintNum, m_printnum);
	DDX_Control(pDX, IDC_SPIN_PrintNumChange, m_printnumchange);
	DDX_Control(pDX, IDC_EDIT_PrintTime, m_printtime);
	DDX_Control(pDX, IDC_SPIN_PrintTimeChange, m_printtimechange);
	DDX_Control(pDX, IDC_EDIT_Effect, m_effect);
	DDX_Control(pDX, IDC_SPIN_EffectChange, m_effectchange);
	DDX_Control(pDX, IDC_DATE_DateChosse, m_datechoose);
	DDX_Control(pDX, IDC_DATE_Time, m_datetime);


	DDX_Control(pDX, IDC_BUT_writeparam, m_writeparam);
	//  DDX_Control(pDX, IDC_BUT_readparam, m_readparam);
	DDX_Control(pDX, IDC_BUT_readparam, m_Readparam);
	DDX_Control(pDX, IDC_BUT_Writedate, m_writedate);
	DDX_Control(pDX, IDC_BUT_ReadDate, m_readdate);
	DDX_Control(pDX, IDC_BUT_WriteEffectDate, m_writeeffectdate);
	DDX_Control(pDX, IDC_BUT_ReadEffectDate, m_readeffectdate);
}


BEGIN_MESSAGE_MAP(CDiaPrintParam, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO2, &CDiaPrintParam::OnBnClickedRadio2)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATE_DateChosse, &CDiaPrintParam::OnDtnDatetimechangeDateDatechosse)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATE_Time, &CDiaPrintParam::OnDtnDatetimechangeDateTime)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATE_Effectdate, &CDiaPrintParam::OnDtnDatetimechangeDateEffectdate)
	ON_BN_CLICKED(IDC_BUT_writeparam, &CDiaPrintParam::OnBnClickedButwriteparam)
	ON_BN_CLICKED(IDC_BUT_readparam, &CDiaPrintParam::OnBnClickedButreadparam)
	ON_BN_CLICKED(IDC_BUT_Writedate, &CDiaPrintParam::OnBnClickedButWritedate)
	ON_BN_CLICKED(IDC_BUT_ReadDate, &CDiaPrintParam::OnBnClickedButReaddate)
	ON_BN_CLICKED(IDC_BUT_WriteEffectDate, &CDiaPrintParam::OnBnClickedButWriteeffectdate)
	ON_BN_CLICKED(IDC_BUT_ReadEffectDate, &CDiaPrintParam::OnBnClickedButReadeffectdate)
END_MESSAGE_MAP()


// CDiaPrintParam 消息处理程序


BOOL CDiaPrintParam::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_bide.SetWindowTextW(_T("600"));
	m_bidechange.SetRange32(600,60000);
	m_bidechange.SetBuddy(GetDlgItem(IDC_EDIT_CharBide));

	m_size.SetWindowTextW(_T("300"));
	m_sizechange.SetRange32(300,30000);
	m_sizechange.SetBuddy(GetDlgItem(IDC_EDIT_Size));

	m_delay.SetWindowTextW(_T("0"));
	m_delaychange.SetRange32(0,5000);
	m_delaychange.SetBuddy(GetDlgItem(IDC_EDIT_Delay));
	
	m_space.SetWindowTextW(_T("0"));
	m_spacechangr.SetRange32(0,255);
	m_spacechangr.SetBuddy(GetDlgItem(IDC_EDIT_Space));

	m_plusenum.SetWindowTextW(_T("1"));
	m_plusenumchange.SetRange32(1,255);
	m_plusenumchange.SetBuddy(GetDlgItem(IDC_EDIT_PluseNum));

	m_printnum.SetWindowTextW(_T("0"));
	m_printnumchange.SetRange32(0,255);
	m_printnumchange.SetBuddy(GetDlgItem(IDC_EDIT_PrintNum));

	m_printtime.SetWindowTextW(_T("0"));
	m_printtimechange.SetRange32(0,5000);
	m_printtimechange.SetBuddy(GetDlgItem(IDC_EDIT_PrintTime));

	m_effect.SetWindowTextW(_T("0"));
	m_effectchange.SetRange32(0,5000);
	m_effectchange.SetBuddy(GetDlgItem(IDC_EDIT_Effect));

	

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDiaPrintParam::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDiaPrintParam::OnDtnDatetimechangeDateDatechosse(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
			
	UpdateData(TRUE);
	
	
	*pResult = 0;
}


void CDiaPrintParam::OnDtnDatetimechangeDateTime(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	*pResult = 0;
}


void CDiaPrintParam::OnDtnDatetimechangeDateEffectdate(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);

	*pResult = 0;
}


void CDiaPrintParam::OnBnClickedButwriteparam()
{
	// TODO: 在此添加控件通知处理程序代码

	
	CString strText(_T(""));
	
	
	CStdioFile file;
	file.Open(_T("..\\bigcharprintparam.txt"),CFile::modeCreate|CFile::modeWrite|CFile::typeText);
	GetDlgItemText(IDC_EDIT_CharBide, strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDC_EDIT_Size,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDC_EDIT_Delay,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDC_EDIT_Space,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDC_EDIT_PluseNum,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDC_EDIT_PrintNum,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDC_EDIT_PrintTime, strText);
	file.WriteString(strText+"\n");


	file.Close();
	
	

}





void CDiaPrintParam::OnBnClickedButreadparam()
{
	// TODO: 在此添加控件通知处理程序代码

	
	CStdioFile file;
	file.Open(_T("..\\bigcharprintparam.txt"),CFile::modeRead);
		
	CString strText =_T( "");
	

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_CharBide,strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_Size, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_Delay, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_Space, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_PluseNum, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_PrintNum, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_PrintTime, strText);

	
	UpdateData(FALSE);
	file.Close();
}


void CDiaPrintParam::OnBnClickedButWritedate()
{
	// TODO: 在此添加控件通知处理程序代码

	
	CString strText(_T(""));

	CStdioFile file;
		file.Open(_T("..\\bigcharprintparamdate.txt"),CFile::modeCreate|CFile::modeWrite|CFile::typeText);
		GetDlgItemText(IDC_DATE_DateChosse, strText);
		file.WriteString(strText+"\n");

		GetDlgItemText(IDC_DATE_Time,  strText);
		file.WriteString(strText+"\n");

		
		file.Close();
	

	}




void CDiaPrintParam::OnBnClickedButReaddate()
{
	// TODO: 在此添加控件通知处理程序代码

	CStdioFile file;
	file.Open(_T("..\\bigcharprintparam.txt"),CFile::modeRead);

	CString strText =_T( "");


	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_DATE_DateChosse,strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_DATE_Time, strText);

	
	UpdateData(FALSE);
	file.Close();
}


void CDiaPrintParam::OnBnClickedButWriteeffectdate()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CString strText(_T(""));

	
		CStdioFile file;
		file.Open(_T("..\\bigcharprintparameffectdate.txt"),CFile::modeCreate|CFile::modeWrite|CFile::typeText);
		GetDlgItemText(IDC_DATE_Effectdate, strText);
		file.WriteString(strText+"\n");

		GetDlgItemText(IDC_EDIT_Effect,  strText);
		file.WriteString(strText+"\n");


		file.Close();
	
}


void CDiaPrintParam::OnBnClickedButReadeffectdate()
{
	// TODO: 在此添加控件通知处理程序代码

	CStdioFile file;
	file.Open(_T("..\\bigcharprintparameffectdate.txt"),CFile::modeRead);

	CString strText =_T( "");


	file.ReadString( strText ) ;

	strText += "\n";
	SetDlgItemText(IDC_DATE_Effectdate,strText);

	file.ReadString( strText ) ;
	strText += "\n";

	SetDlgItemText(IDC_EDIT_Effect, strText);


	UpdateData(FALSE);
	file.Close();
}
