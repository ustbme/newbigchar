// DiaSystemSetting.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaSystemSetting.h"
#include "afxdialogex.h"


// CDiaSystemSetting �Ի���

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
}


BEGIN_MESSAGE_MAP(CDiaSystemSetting, CDialogEx)
END_MESSAGE_MAP()


// CDiaSystemSetting ��Ϣ�������
