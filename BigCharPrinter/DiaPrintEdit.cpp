// DiaPrintEdit.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaPrintEdit.h"
#include "afxdialogex.h"


// CDiaPrintEdit �Ի���

IMPLEMENT_DYNAMIC(CDiaPrintEdit, CDialogEx)

CDiaPrintEdit::CDiaPrintEdit(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaPrintEdit::IDD, pParent)
{

}

CDiaPrintEdit::~CDiaPrintEdit()
{
}

void CDiaPrintEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDiaPrintEdit, CDialogEx)
	ON_LBN_SELCHANGE(IDC_LIST10, &CDiaPrintEdit::OnLbnSelchangeList10)
END_MESSAGE_MAP()


// CDiaPrintEdit ��Ϣ�������


void CDiaPrintEdit::OnLbnSelchangeList10()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
