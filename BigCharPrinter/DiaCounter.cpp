// DiaCounter.cpp : 实现文件
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaCounter.h"
#include "afxdialogex.h"


// CDiaCounter 对话框

IMPLEMENT_DYNAMIC(CDiaCounter, CDialogEx)

CDiaCounter::CDiaCounter(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaCounter::IDD, pParent)
	/*, m_plus2(0)
	, m_devide1(0)
	, m_devide2(0)
	, m_devide3(0)
	, m_devide3(0)
	, m_devide4(0)*/
{

}

CDiaCounter::~CDiaCounter()
{
}

void CDiaCounter::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_CountNum1, m_countnum1);
	DDX_Control(pDX, IDC_EDIT_CountNum2, m_countnum2);
	//DDX_Control(pDX, IDC_EDIT9, m_countnum3);
	DDX_Control(pDX, IDC_SPIN_CountNumChange1, m_countnumchange1);
	DDX_Control(pDX, IDC_SPIN_CountNumChange2, m_countnumchange2);
	//DDX_Control(pDX, IDC_SPIN9, m_countnumchange3);
	DDX_Control(pDX, IDC_EDIT_GoalNum1, m_goalnum1);
	DDX_Control(pDX, IDC_EDIT_GoalNum2, m_goalnum2);
	DDX_Control(pDX, IDC_EDIT_GoalNum3, m_goalnum3);
	DDX_Control(pDX, IDC_SPIN_GoalNumChange1, m_goalnumchange1);
	DDX_Control(pDX, IDC_SPIN_GoalNumChange2, m_goalnumchange2);
	DDX_Control(pDX, IDC_SPIN_GoalNumChange3, m_goalnumchange3);
	DDX_Control(pDX, IDC_EDIT_StartNum1, m_startnum1);
	DDX_Control(pDX, IDC_EDIT_StartNum2, m_startnum2);
	DDX_Control(pDX, IDC_EDIT_StartNum3, m_startnum3);
	DDX_Control(pDX, IDC_SPIN_StartNumChange1, m_startnumchange1);
	DDX_Control(pDX, IDC_SPIN_StartNumChange2, m_startnumchange2);
	DDX_Control(pDX, IDC_SPIN_StartNumChange3, m_startnumchange3);
	DDX_Control(pDX, IDC_EDIT_CurrentNum1, m_currentnum1);
	DDX_Control(pDX, IDC_EDIT_CurrentNum2, m_currentnum2);
	DDX_Control(pDX, IDC_EDIT_CurrentNum3, m_currentnum3);
	DDX_Control(pDX, IDC_SPIN_CurrentNumChange1, m_currentnumchange1);
	DDX_Control(pDX, IDC_SPIN_CurrentNumChange2, m_currentnumchange2);
	DDX_Control(pDX, IDC_SPIN_CurrentNumChange3, m_currentnumchange3);
	DDX_Control(pDX, IDC_EDIT_CountNum3, m_countnum33);
	DDX_Control(pDX, IDC_SPIN_CountNumChange3, m_countnumchange33);
	DDX_Control(pDX, IDC_BUT_Write1, m_write1);
	DDX_Control(pDX, IDC_BUT_Write2, m_write2);
	//  DDX_Control(pDX, IDC_BUT_Write3, m_write3);
	DDX_Control(pDX, IDC_BUT_Read1, m_read1);
	DDX_Control(pDX, IDC_BUT_Read2, m_read2);
	DDX_Control(pDX, IDC_BUT_Read3, m_m_read3);
	DDX_Control(pDX, IDC_BUT_Write3, m_write3);
	//  DDX_Control(pDX, IDC_RADIO1, m_plus1);
	//  DDX_Control(pDX, IDC_RADIO11, m_plus2);
	//  DDX_Control(pDX, IDC_RADIO1, m_plus1);
	//  DDX_Control(pDX, IDC_RADIO3, m_plus2);
	//  DDX_Control(pDX, IDC_RADIO5, m_plus3);
	//  DDX_Control(pDX, IDC_RADIO7, m_plus4);
}


BEGIN_MESSAGE_MAP(CDiaCounter, CDialogEx)
	ON_BN_CLICKED(IDC_BUT_Write3, &CDiaCounter::OnBnClickedButWrite3)
	ON_BN_CLICKED(IDC_BUT_Write1, &CDiaCounter::OnBnClickedButWrite1)
	ON_BN_CLICKED(IDC_BUT_Write2, &CDiaCounter::OnBnClickedButWrite2)
	ON_BN_CLICKED(IDC_BUT_Read1, &CDiaCounter::OnBnClickedButRead1)
	ON_BN_CLICKED(IDC_BUT_Read2, &CDiaCounter::OnBnClickedButRead2)
	ON_BN_CLICKED(IDC_BUT_Read3, &CDiaCounter::OnBnClickedButRead3)
END_MESSAGE_MAP()


// CDiaCounter 消息处理程序


BOOL CDiaCounter::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_countnum1.SetWindowTextW(_T("1"));
	m_countnumchange1.SetRange32(0,5);
	m_countnumchange1.SetBuddy(GetDlgItem(IDC_EDIT_CountNum1));

	m_countnum2.SetWindowTextW(_T("1"));
	m_countnumchange2.SetRange32(0,5);
	m_countnumchange2.SetBuddy(GetDlgItem(IDC_EDIT_CountNum2));

	m_countnum33.SetWindowTextW(_T("1"));
	m_countnumchange33.SetRange32(0,5);
	m_countnumchange33.SetBuddy(GetDlgItem(IDC_EDIT_CountNum3));

	m_goalnum2.SetWindowTextW(_T("1"));
	m_goalnumchange2.SetRange32(1,9999);
	m_goalnumchange2.SetBuddy(GetDlgItem(IDC_EDIT_GoalNum2));

	m_goalnum1.SetWindowTextW(_T("1"));
	m_goalnumchange1.SetRange32(1,9999);
	m_goalnumchange1.SetBuddy(GetDlgItem(IDC_EDIT_GoalNum1));

	m_goalnum3.SetWindowTextW(_T("1"));
	m_goalnumchange3.SetRange32(1,9999);
	m_goalnumchange3.SetBuddy(GetDlgItem(IDC_EDIT_GoalNum3));

	m_startnum1.SetWindowTextW(_T("1"));
	m_startnumchange1.SetRange32(1,9999);
	m_startnumchange1.SetBuddy(GetDlgItem(IDC_EDIT_StartNum1));

	m_startnum2.SetWindowTextW(_T("1"));
	m_startnumchange2.SetRange32(1,9999);
	m_startnumchange2.SetBuddy(GetDlgItem(IDC_EDIT_StartNum2));

	m_startnum3.SetWindowTextW(_T("1"));
	m_startnumchange3.SetRange32(1,9999);
	m_startnumchange3.SetBuddy(GetDlgItem(IDC_EDIT_StartNum3));

	m_currentnum1.SetWindowTextW(_T("1"));
	m_currentnumchange1.SetRange32(1,9999);
	m_currentnumchange1.SetBuddy(GetDlgItem(IDC_EDIT_CurrentNum1));

	m_currentnum2.SetWindowTextW(_T("1"));
	m_currentnumchange2.SetRange32(1,9999);
	m_currentnumchange2.SetBuddy(GetDlgItem(IDC_EDIT_CurrentNum2));

	m_currentnum3.SetWindowTextW(_T("1"));
	m_currentnumchange3.SetRange32(1,9999);
	m_currentnumchange3.SetBuddy(GetDlgItem(IDC_EDIT_CurrentNum3));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}




void CDiaCounter::OnBnClickedButWrite1()
{
	// TODO: 在此添加控件通知处理程序代码

	CString strText(_T(""));
	CStdioFile file;
	file.Open(_T("..\\bigcharprintcount1.txt"),CFile::modeCreate|CFile::modeWrite|CFile::typeText);
	GetDlgItemText(IDC_EDIT_CountNum1, strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDC_EDIT_GoalNum1,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDC_EDIT_StartNum1,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDC_EDIT_CurrentNum1,  strText);
	file.WriteString(strText+"\n");

	file.Close();

}


void CDiaCounter::OnBnClickedButWrite2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strText(_T(""));
	CStdioFile file;
	file.Open(_T("..\\bigcharprintcount2.txt"),CFile::modeCreate|CFile::modeWrite|CFile::typeText);
	GetDlgItemText(IDC_EDIT_CountNum2, strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDC_EDIT_GoalNum2,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDC_EDIT_StartNum2,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDC_EDIT_CurrentNum2,  strText);
	file.WriteString(strText+"\n");

	file.Close();

}


void CDiaCounter::OnBnClickedButWrite3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strText(_T(""));
	CStdioFile file;
	file.Open(_T("..\\bigcharprintcount3.txt"),CFile::modeCreate|CFile::modeWrite|CFile::typeText);
	GetDlgItemText(IDC_EDIT_CountNum3, strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDC_EDIT_GoalNum3,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDC_EDIT_StartNum3,  strText);
	file.WriteString(strText+"\n");

	GetDlgItemText(IDC_EDIT_CurrentNum3,  strText);
	file.WriteString(strText+"\n");

	file.Close();

}

void CDiaCounter::OnBnClickedButRead1()
{
	// TODO: 在此添加控件通知处理程序代码

	CStdioFile file;
	file.Open(_T("..\\bigcharprintcount1.txt"),CFile::modeRead);

	CString strText =_T( "");


	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_CountNum1,strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_GoalNum1, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_StartNum1, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_CurrentNum1, strText);


	UpdateData(FALSE);
	file.Close();
}


void CDiaCounter::OnBnClickedButRead2()
{
	// TODO: 在此添加控件通知处理程序代码

	CStdioFile file;
	file.Open(_T("..\\bigcharprintcount2.txt"),CFile::modeRead);

	CString strText =_T( "");


	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_CountNum2,strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_GoalNum2, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_StartNum2, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_CurrentNum2, strText);


	UpdateData(FALSE);
	file.Close();
}


void CDiaCounter::OnBnClickedButRead3()
{
	// TODO: 在此添加控件通知处理程序代码
	CStdioFile file;
	file.Open(_T("..\\bigcharprintcount3.txt"),CFile::modeRead);

	CString strText =_T( "");


	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_CountNum3,strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_GoalNum3, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_StartNum3, strText);

	file.ReadString( strText ) ;
	strText += "\n";
	SetDlgItemText(IDC_EDIT_CurrentNum3, strText);


	UpdateData(FALSE);
	file.Close();

}
