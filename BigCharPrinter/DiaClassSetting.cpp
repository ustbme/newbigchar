// DiaClassSetting.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaClassSetting.h"
#include "afxdialogex.h"


// CDiaClassSetting �Ի���

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
}


BEGIN_MESSAGE_MAP(CDiaClassSetting, CDialogEx)
END_MESSAGE_MAP()


// CDiaClassSetting ��Ϣ�������
