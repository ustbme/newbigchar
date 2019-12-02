// DiaCustomIcon.cpp : 实现文件
//

#include "stdafx.h"
#include "BigCharPrinter.h"
#include "DiaCustomIcon.h"
#include "afxdialogex.h"



// CDiaCustomIcon 对话框

IMPLEMENT_DYNAMIC(CDiaCustomIcon, CDialogEx)

	


CDiaCustomIcon::CDiaCustomIcon(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDiaCustomIcon::IDD, pParent)
{
	m_nStep = 10;

}

CDiaCustomIcon::~CDiaCustomIcon()
{
}

void CDiaCustomIcon::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PIC, m_drawPic);
	DDX_Control(pDX, IDC_OpenPic, m_OpenPic);
	DDX_Control(pDX, IDC_SavePic, m_SavePic);
}


BEGIN_MESSAGE_MAP(CDiaCustomIcon, CDialogEx)
	
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	
	ON_BN_CLICKED(IDC_OpenPic, &CDiaCustomIcon::OnBnClickedOpenpic)
	ON_BN_CLICKED(IDC_SavePic, &CDiaCustomIcon::OnBnClickedSavepic)
END_MESSAGE_MAP()


// CDiaCustomIcon 消息处理程序





BOOL CDiaCustomIcon::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	for(int nRow = 0; nRow < 16; nRow++)
		for(int nCol = 0; nCol < 16; nCol++)
			m_arrData[nRow][nCol] = 0;

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CDiaCustomIcon::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	CDC *pDC = m_drawPic.GetDC();


	//先清除内容
	CBrush cbrush;
	CBrush* pBrush; //旧笔刷
	CRect rect;
	m_drawPic.GetClientRect(&rect);
	cbrush.CreateSolidBrush(RGB(255,255,255)); 
	pBrush = pDC->SelectObject(&cbrush); //载入笔刷
	pDC->Rectangle(&rect); //绘制矩形		
	pDC->SelectObject(pBrush); //恢复笔刷
	cbrush.DeleteObject();
	pBrush->DeleteObject();


	m_drawPic.SetWindowPos(NULL, -1, -1, 16*m_nStep, 16*m_nStep, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);
	int i;
	for (i = 0; i <= 16; i++)
	{		 
		pDC->MoveTo(0,i*m_nStep);
		pDC->LineTo(16*m_nStep,i*m_nStep);			 
	}

	for (i = 0; i <= 16; i++)
	{		 
		pDC->MoveTo(i*m_nStep,0);
		pDC->LineTo(i*m_nStep,16*m_nStep);			 
	}

	//根据m_arrData画点
	for(int nRow = 0; nRow < 16; nRow++)
	{
		for(int nCol = 0; nCol < 16; nCol++)
		{
			if(m_arrData[nRow][nCol])
			{
				CBrush cbrush;
				CBrush* pBrush; //旧笔刷				 
				cbrush.CreateSolidBrush(RGB(255,0,0)); //红色
				pBrush = pDC->SelectObject(&cbrush); //载入笔刷	
				pDC->Ellipse(nRow*m_nStep,nCol*m_nStep,(nRow+1)*m_nStep,(nCol+1)*m_nStep);

				pDC->SelectObject(pBrush); //恢复笔刷
				cbrush.DeleteObject();
				pBrush->DeleteObject();
			}
		}
	}
}



void CDiaCustomIcon::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDialogEx::OnLButtonDown(nFlags, point);
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//////////////////////////////////////////////////////////////////////////	
	//最后把当前鼠标的坐标转化为相对于rect的坐标
	CRect lRect;
	m_drawPic.GetWindowRect(&lRect);  //获取控件相对于屏幕的位置
	ScreenToClient(&lRect);

	if((point.x >= lRect.left && point.x <= lRect.right) && (point.y >= lRect.top && point.y <= lRect.bottom))
	{
		point.x -= lRect.left;
		point.y -= lRect.top;
		int nRow;
		int nCol;	 
		nRow = point.x / m_nStep;
		nCol = point.y / m_nStep;
		m_arrData[nRow][nCol] = !m_arrData[nRow][nCol]; //给数组赋值,取反
	}
	OnPaint();	
}

CString CDiaCustomIcon::FileName()
{
	//读写的文件名称
	m_binFileName = "1.dat";
	return m_binFileName;


}


void CDiaCustomIcon::Serialize(CArchive &ar)
{
	if (ar.IsStoring())
	{
		//写变量的数据到文件
		int nRow,nCol;
		for(int nRow = 0; nRow < 16; nRow++)
			for(int nCol = 0; nCol < 16; nCol++)
				ar<<m_arrData[nRow][nCol] ;
	}
	else
	{
		//读文件内容并保存到变量：
		int nRow,nCol;	
		for(int nRow = 0; nRow < 16; nRow++)
			for(int nCol = 0; nCol < 16; nCol++)
				ar>>m_arrData[nRow][nCol] ;
	}
}

BOOL CDiaCustomIcon::Save2File()
{
	
	BOOL bOpenFileDialog = FALSE;
	BOOL bVistaStyle = FALSE; 
	TCHAR BASED_CODE szFilter[] = 
		_T("二进制文件(*.dat)|*.dat|")
		_T("All Files (*.*)|*.*||");
	CString path_and_fileName;

	CFileDialog fdlg(bOpenFileDialog, _T("dat"), _T("*.dat"),
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL, 0, bVistaStyle);
	if (IDOK == fdlg.DoModal()) 
	{
		CFile fileSave;
		CFileException ex;

		path_and_fileName = fdlg.GetPathName();
		if (!fileSave.Open(path_and_fileName, CFile::modeCreate | 
			CFile::modeWrite | CFile::typeBinary, &ex))
		{   
			TCHAR szError[1024];
			ex.GetErrorMessage(szError, 1024);		
			return FALSE;
		}

		CArchive ar(&fileSave, CArchive::store);     	
		Serialize(ar);
		ar.Close();
		fileSave.Close();
	}

	return TRUE;
}

BOOL CDiaCustomIcon::Read2File()
{	
	BOOL bOpenFileDialog = true;
	BOOL bVistaStyle = FALSE; // no VistaStyle
	TCHAR BASED_CODE szFilter[] = 
		_T("二进制文件(*.dat)|*.dat|")
		_T("All Files (*.*)|*.*||");
	CString path_and_fileName;

	CFileDialog fdlg(bOpenFileDialog, _T("dat"), _T("*.dat"),
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, NULL, 0, bVistaStyle);
	if (IDOK == fdlg.DoModal()) 
	{
		CFile fileRead;
		CFileException ex;

		path_and_fileName = fdlg.GetPathName();
		if (!fileRead.Open(path_and_fileName, CFile::modeRead | CFile::typeBinary, &ex))
		{   
			TCHAR szError[1024];
			ex.GetErrorMessage(szError, 1024);			
			return FALSE;
		}

		CArchive ar(&fileRead, CArchive::load); 
		Serialize(ar);
		ar.Close();
		fileRead.Close();
	}

	return TRUE;
}

void CDiaCustomIcon::OnBnClickedOpenpic()
{
	// TODO: 在此添加控件通知处理程序代码
	Read2File();	
	OnPaint();
}


void CDiaCustomIcon::OnBnClickedSavepic()
{
	// TODO: 在此添加控件通知处理程序代码	
	Save2File();
}
