// DiaPrintParam.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaPrintParam.h"
#include "afxdialogex.h"


// CDiaPrintParam �Ի���

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
}


BEGIN_MESSAGE_MAP(CDiaPrintParam, CDialogEx)
END_MESSAGE_MAP()


// CDiaPrintParam ��Ϣ�������
