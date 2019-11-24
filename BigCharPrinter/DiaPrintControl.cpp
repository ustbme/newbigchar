// DiaPrintControl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaPrintControl.h"
#include "afxdialogex.h"


// CDiaPrintControl �Ի���

IMPLEMENT_DYNAMIC(CDiaPrintControl, CDialogEx)

CDiaPrintControl::CDiaPrintControl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaPrintControl::IDD, pParent)
{

}

CDiaPrintControl::~CDiaPrintControl()
{
}

void CDiaPrintControl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUT_OPEN_FILE, m_ButOpenFile);
}


BEGIN_MESSAGE_MAP(CDiaPrintControl, CDialogEx)
	ON_BN_CLICKED(IDC_BUT_OPEN_FILE, &CDiaPrintControl::OnBnClickedButOpenFile)
END_MESSAGE_MAP()


// CDiaPrintControl ��Ϣ�������


void CDiaPrintControl::OnBnClickedButOpenFile()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


BOOL CDiaPrintControl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_ButOpenFile.SetBitmaps(IDB_BITMAP1,RGB(255,255,255),IDB_BITMAP1,RGB(255,255,255));
	m_ButOpenFile.DrawTransparent(true);
	m_ButOpenFile.SetFlat(1);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
