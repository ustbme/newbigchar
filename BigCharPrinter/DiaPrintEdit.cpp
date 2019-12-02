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
	, m_strInputText(_T(""))
{
 
	m_bDesign = true; 
	m_nStepPixels = 5;
	m_nSelectObjIndex = -1;
	for(int i = 0; i < m_nRowSum; i++)
		for(int j = 0; j < m_nColSum; j++)
			m_arrPrintData[i][j] = false;
 
}

CDiaPrintEdit::~CDiaPrintEdit()
{
}

void CDiaPrintEdit::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
 
	DDX_Control(pDX, IDC_COM_PARAM, m_ComParam);
	DDX_Control(pDX, IDC_COM_DATA, m_ComData);
	DDX_Control(pDX, IDC_STATIC_DESIGN_AREA, m_designArea);
	DDX_Control(pDX, IDC_COM_FONT, m_comFonts);
	DDX_Text(pDX, IDC_EDIT_INPUT_TEXT, m_strInputText);
 
}


BEGIN_MESSAGE_MAP(CDiaPrintEdit, CDialogEx)
 
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUT_DESIGN_VIEW, &CDiaPrintEdit::OnBnClickedButDesignView)
	ON_BN_CLICKED(IDC_BUT_PRINT_VIEW, &CDiaPrintEdit::OnBnClickedButPrintView)
	ON_BN_CLICKED(IDC_BUT_DESIGN_CLEAN, &CDiaPrintEdit::OnBnClickedButDesignClean)
	ON_BN_CLICKED(IDC_BUT_DESIGN_SAVE, &CDiaPrintEdit::OnBnClickedButDesignSave)
	ON_BN_CLICKED(IDC_BUT_OPEN_DESIGN, &CDiaPrintEdit::OnBnClickedButOpenDesign)
	ON_BN_CLICKED(IDC_BUT_INSERT_PARAM, &CDiaPrintEdit::OnBnClickedButInsertParam)
	ON_BN_CLICKED(IDC_BUT_INSERT_DADA, &CDiaPrintEdit::OnBnClickedButInsertDada)
	ON_BN_CLICKED(IDC_BUT_ADD_TEXT, &CDiaPrintEdit::OnBnClickedButAddText)
	ON_BN_CLICKED(IDC_BUT_MOVE_UP, &CDiaPrintEdit::OnBnClickedButMoveUp)
	ON_BN_CLICKED(IDC_BUT_MOVE_DOWN, &CDiaPrintEdit::OnBnClickedButMoveDown)
	ON_BN_CLICKED(IDC_BUT_MOVE_LEFT, &CDiaPrintEdit::OnBnClickedButMoveLeft)
	ON_BN_CLICKED(IDC_BUT_MOVE_RIGHT, &CDiaPrintEdit::OnBnClickedButMoveRight)
	ON_BN_CLICKED(IDC_BUT_DEL_TEXT, &CDiaPrintEdit::OnBnClickedButDelText)
	ON_WM_LBUTTONDOWN()

END_MESSAGE_MAP()


// CDiaPrintEdit ��Ϣ�������


BOOL CDiaPrintEdit::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	m_ComParam.SendMessage(CB_SETITEMHEIGHT,-1,43); //�ı���Ͽ�ĸ߶�
	m_ComData.SendMessage(CB_SETITEMHEIGHT,-1,43);

	m_ComParam.SendMessage(CB_SETITEMHEIGHT,0,20);
	m_ComData.SendMessage(CB_SETITEMHEIGHT,0,20);

	for (int i = 1; i <= 10; i++)
	{
		CString str;
		str.Format(L"%d",i);
		m_ComParam.InsertString(i-1,str);
	}
	m_ComParam.SetCurSel(0);

	m_ComData.InsertString(0,L"ϵͳ����");
	m_ComData.InsertString(1,L"��Ч����");
	m_ComData.InsertString(2,L"ϵͳʱ��");
	m_ComData.InsertString(3,L"����1");
	m_ComData.InsertString(4,L"����2");
	m_ComData.InsertString(5,L"����3");
	m_ComData.InsertString(6,L"��ĸ����");
	m_ComData.InsertString(7,L"�����");

	m_comFonts.InsertString(0,L"5X5");
	m_comFonts.InsertString(1,L"7X5");
	m_comFonts.InsertString(2,L"12X12");
	m_comFonts.InsertString(2,L"16X12");

	m_ComData.SetCurSel(0);	 
	m_comFonts.SetCurSel(1);	 

	m_designArea.SetWindowPos(NULL,-1,-1,195*5,16*5, SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOZORDER);

	return TRUE;  // return TRUE unless you set the focus to a control	
}


void CDiaPrintEdit::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

	CDC* pDC = m_designArea.GetDC();
	//�������ӡԤ������
	CBrush cbrush;
	CBrush* pBrush; //�ɱ�ˢ
	CRect rect;
	m_designArea.GetClientRect(&rect);
	cbrush.CreateSolidBrush(RGB(255,255,255)); 
	pBrush=pDC->SelectObject(&cbrush); //�����ˢ
	pDC->Rectangle(&rect); //���ƾ���		
	pDC->SelectObject(pBrush); //�ָ���ˢ
	cbrush.DeleteObject();
	pBrush->DeleteObject();
	if(m_bDesign)
	{
		//������ƽ��
		m_PrintObjectsDeal.DrawObjects(pDC,m_nStepPixels);
	}
	else
	{		 
		CPen cPen; 
		cPen.CreatePen(PS_SOLID,1,RGB(252,157,154)); 
		CPen* pOldPen; 
		pOldPen = pDC->SelectObject(&cPen); //�����ˢ
		
		for(int i = 0; i < m_nRowSum; i++)
		{
			pDC->MoveTo(0,i*m_nStepPixels);
			pDC->LineTo(m_nStepPixels*m_nColSum,i*m_nStepPixels);
		}
		for(int i = 0; i < m_nColSum; i++)
		{
			pDC->MoveTo(i*m_nStepPixels,0);
			pDC->LineTo(i*m_nStepPixels,m_nStepPixels*m_nRowSum);
		}
		pDC->SelectObject(pOldPen);
		cPen.DeleteObject();
		pOldPen->DeleteObject();

		CBrush cbrush;
		CBrush* pBrush; //�ɱ�ˢ	
		cbrush.CreateSolidBrush(RGB(0,0,0)); 
		pBrush = pDC->SelectObject(&cbrush); //�����ˢ
	  
		for(int i = 0; i < m_nRowSum; i++)
			for(int j = 0; j < m_nColSum; j++)
				DrawOnePoint(pDC,i,j);

		pDC->SelectObject(pBrush); //�ָ���ˢ
		cbrush.DeleteObject();
		pBrush->DeleteObject();
	}

	ReleaseDC(pDC); 
}

void CDiaPrintEdit::OnBnClickedButDesignView()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_bDesign = true; 
	OnPaint();
}

void CDiaPrintEdit::OnBnClickedButPrintView()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_bDesign = false;
 	OnPaint();
}

void CDiaPrintEdit::DrawOnePoint(CDC* pDC ,int row,int col)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_arrPrintData[row][col])
	{
		CRect rect(col*m_nStepPixels,row*m_nStepPixels,(col+1)*m_nStepPixels,(row+1)*m_nStepPixels);
		pDC->Ellipse(&rect); 
	}
}


void CDiaPrintEdit::OnBnClickedButDesignClean()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDiaPrintEdit::OnBnClickedButDesignSave()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BOOL isOpen = TRUE;		//�Ƿ��(����Ϊ����)
	CString defaultDir = L"";	//Ĭ�ϴ򿪵��ļ�·��
	CString fileName = L"";			//Ĭ�ϴ򿪵��ļ���
	CString filter = L"�ļ� (*.xml; *.lab)|*.xml;*.lab||";	//�ļ����ǵ�����
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY|OFN_READONLY, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = L".//test.xml";
	INT_PTR result = openFileDlg.DoModal();
	CString filePath = defaultDir + L"\\test.xml";
	if(result == IDOK) {
		filePath = openFileDlg.GetPathName();
		USES_CONVERSION;  
		m_PrintObjectsDeal.SaveObjectsToXml(W2A(filePath.GetBuffer(0)));
	}  
}


void CDiaPrintEdit::OnBnClickedButOpenDesign()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	BOOL isOpen = TRUE;		//�Ƿ��(����Ϊ����)
	CString defaultDir = L"";	//Ĭ�ϴ򿪵��ļ�·��
	CString fileName = L"";			//Ĭ�ϴ򿪵��ļ���
	CString filter = L"�ļ� (*.xml; *.lab)|*.xml;*.lab||";	//�ļ����ǵ�����
	CFileDialog openFileDlg(isOpen, defaultDir, fileName, OFN_HIDEREADONLY|OFN_READONLY, filter, NULL);
	openFileDlg.GetOFN().lpstrInitialDir = L".//test.xml";
	INT_PTR result = openFileDlg.DoModal();
	CString filePath = defaultDir + L"\\test.xml";
	if(result == IDOK) {
		filePath = openFileDlg.GetPathName();
		USES_CONVERSION;  
		m_PrintObjectsDeal.ReadObjectsFromXml(W2A(filePath.GetBuffer(0)));
		OnPaint();
	}  
}


void CDiaPrintEdit::OnBnClickedButInsertParam()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDiaPrintEdit::OnBnClickedButInsertDada()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CDiaPrintEdit::OnBnClickedButAddText()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	CCharObject obj;
	USES_CONVERSION;
	sprintf(obj.m_texts,"%s",W2A(m_strInputText.GetBuffer(0)));
	m_PrintObjectsDeal.m_arrObjects.push_back(obj);

	OnPaint();
}


void CDiaPrintEdit::OnBnClickedButMoveUp()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_nSelectObjIndex < 0) return;
	m_PrintObjectsDeal.m_arrObjects[m_nSelectObjIndex].m_yPos -=1;

	OnPaint();

}


void CDiaPrintEdit::OnBnClickedButMoveDown()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_nSelectObjIndex < 0) return;
	m_PrintObjectsDeal.m_arrObjects[m_nSelectObjIndex].m_yPos +=1;

	OnPaint();
}


void CDiaPrintEdit::OnBnClickedButMoveLeft()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_nSelectObjIndex < 0) return;
	m_PrintObjectsDeal.m_arrObjects[m_nSelectObjIndex].m_xPos -=1;
	OnPaint();
}


void CDiaPrintEdit::OnBnClickedButMoveRight()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_nSelectObjIndex < 0) return;

	m_PrintObjectsDeal.m_arrObjects[m_nSelectObjIndex].m_xPos +=1;

	OnPaint();
}


void CDiaPrintEdit::OnBnClickedButDelText()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	if(m_nSelectObjIndex < 0) return;	 

	int n = 0;
	vector<CCharObject>::iterator itr = m_PrintObjectsDeal.m_arrObjects.begin();
	while (itr != m_PrintObjectsDeal.m_arrObjects.end())
	{
		if (n == m_nSelectObjIndex)
		{
			m_PrintObjectsDeal.m_arrObjects.erase(itr);//ɾ��Ԫ��
			break;
		}
		++itr;
		n++;
		//*itr->DrawObject()
	}

	m_nSelectObjIndex = -1;
	OnPaint();
}


void CDiaPrintEdit::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CRect lRect;
	m_designArea.GetWindowRect(&lRect);  //��ȡ�ؼ��������Ļ��λ��
	ScreenToClient(&lRect);
	m_nSelectObjIndex = -1;
	if((point.x >= lRect.left && point.x <= lRect.right) && (point.y >= lRect.top && point.y <= lRect.bottom))
	{
		point.x -= lRect.left;
		point.y -= lRect.top;
		int nRow;
		int nCol;	 
		nRow = point.y / m_nStepPixels;
		nCol = point.x / m_nStepPixels;
		int n = 0;

		vector<CCharObject>::iterator itr = m_PrintObjectsDeal.m_arrObjects.begin();
		while (itr != m_PrintObjectsDeal.m_arrObjects.end())
		{
			
			itr->m_bSelected = false;
			if(nRow >itr->m_yPos && nRow < itr->m_yPos + itr->m_High &&
               nCol >itr->m_xPos && nCol < itr->m_xPos + itr->m_Width )
			{
				itr->m_bSelected = true;
				m_nSelectObjIndex = n;
				break;
			}			 
			++itr;
			n++;
			//*itr->DrawObject()
		}

	}
	OnPaint();

	CDialogEx::OnLButtonDown(nFlags, point);
}
