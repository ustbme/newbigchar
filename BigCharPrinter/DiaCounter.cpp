// DiaCounter.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaCounter.h"
#include "afxdialogex.h"


// CDiaCounter �Ի���

IMPLEMENT_DYNAMIC(CDiaCounter, CDialogEx)

CDiaCounter::CDiaCounter(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaCounter::IDD, pParent)
{

}

CDiaCounter::~CDiaCounter()
{
}

void CDiaCounter::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDiaCounter, CDialogEx)
END_MESSAGE_MAP()


// CDiaCounter ��Ϣ�������
