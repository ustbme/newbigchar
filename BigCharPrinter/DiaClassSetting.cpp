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
}


BEGIN_MESSAGE_MAP(CDiaClassSetting, CDialogEx)
END_MESSAGE_MAP()


// CDiaClassSetting 消息处理程序
