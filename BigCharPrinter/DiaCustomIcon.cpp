// DiaCustomIcon.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaCustomIcon.h"
#include "afxdialogex.h"


// CDiaCustomIcon �Ի���

IMPLEMENT_DYNAMIC(CDiaCustomIcon, CDialogEx)

CDiaCustomIcon::CDiaCustomIcon(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaCustomIcon::IDD, pParent)
{

}

CDiaCustomIcon::~CDiaCustomIcon()
{
}

void CDiaCustomIcon::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDiaCustomIcon, CDialogEx)
END_MESSAGE_MAP()


// CDiaCustomIcon ��Ϣ�������
