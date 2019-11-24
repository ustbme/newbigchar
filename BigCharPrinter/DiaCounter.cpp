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


// CDiaCounter 消息处理程序
