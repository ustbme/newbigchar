#include "StdAfx.h"
#include "CharObject.h"
#include <iostream>    
#include <fstream>      
using namespace std;

CCharObject::CCharObject(void)
{
	m_xPos = 0;
	m_yPos = 0;
	m_Width = 0;
	m_High = 0;
	m_bSelected = false;
}


CCharObject::~CCharObject(void)
{
}

void CCharObject::DrawObject(CDC* pDC,int nStepPixels)
{	  
	m_nStepPixels = nStepPixels;
	//��ȡÿ���ַ��ĵ�����Ϣ
	int startCol = m_xPos;	 

	int nCharNum = strlen(m_texts);
	m_Width = nCharNum*6; //Ҫ����ʵ��ռ�õ��������е���
	m_High = 8;
	for(int k = 0; k < nCharNum; k++)
	{
		startCol = m_xPos + k*6; //Ҫ����ʵ��ռ�õ��������е���
		char c = m_texts[k];

		wchar_t ttt = c;
		int unicodeNum = (int)ttt;

		int lonTextUniSetOffT = (unicodeNum)*8+64;
		char readfnt[8];
		readBin("7x5.fnt",lonTextUniSetOffT,readfnt,8);
        int nCol = readfnt[7];
		for(int i = 0; i < nCol; i++)
		{
			for(int j = 0; j < 8; j++)
			{
				bool bDraw = ((readfnt[i]>>j) & 0x01);
				if(bDraw)
				{
					int row = 7-j+m_yPos;
					int col = startCol+i;
					CBrush cbrush;
					CBrush* pBrush; //�ɱ�ˢ					
					cbrush.CreateSolidBrush(RGB(0,0,0)); 
					pBrush = pDC->SelectObject(&cbrush); //�����ˢ

					CRect rect(col*nStepPixels,row*nStepPixels,(col+1)*nStepPixels,(row+1)*nStepPixels);
					pDC->Ellipse(&rect); 

					pDC->SelectObject(pBrush); //�ָ���ˢ
					cbrush.DeleteObject();
					pBrush->DeleteObject();
				}
			}
		}
	}
	//���Ʊ�ѡ�к���̿�
	if(m_bSelected)
	{
		CRect rect;
		GetObjectBox(&rect);
		CPen cPen; 
		cPen.CreatePen(PS_SOLID,1,RGB(252,157,154)); 
		CPen* pOldPen; 
		pOldPen = pDC->SelectObject(&cPen); //�����ˢ
 
		//����һ�����μ���
		CPoint pts[5];
		pts[0] = pts[4] = CPoint(rect.TopLeft());
		pts[1] = CPoint(rect.right,rect.top);
		pts[2] = CPoint(rect.BottomRight());
		pts[3] = CPoint(rect.left,rect.bottom);

		pDC->MoveTo(pts[0]);pDC->LineTo(pts[1]);
		pDC->MoveTo(pts[1]);pDC->LineTo(pts[2]);
		pDC->MoveTo(pts[2]);pDC->LineTo(pts[3]);
		pDC->MoveTo(pts[3]);pDC->LineTo(pts[4]);

		pDC->SelectObject(pOldPen);
		cPen.DeleteObject();
		pOldPen->DeleteObject();

		//CPen pen;
		//pen.CreatePen(PS_SOLID,1,RGB(255,0,0));
		//CDC *dc = CDC::FromHandle(::GetDC(NULL));
		//CPen *pOldPen=dc->SelectObject(&pen);//����ѡ���豸�����������ص�ǰ�Ļ���
		//CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));//����һ��͸���Ļ�ˢ
		//CBrush *pOldBrush=dc->SelectObject(pBrush);//ѡ��ˢ
		//dc->Rectangle(rect);
		//dc->FillRect(rect,pBrush);
		//dc->SelectObject(pOldBrush);//�ָ���ǰ �Ļ�ˢ
		//dc->SelectObject(pOldPen);//�ָ���ǰ�Ļ���
	}
}

void CCharObject::GetObjectBox(CRect* rect)
{
	rect->left = m_xPos*m_nStepPixels;
	rect->top = m_yPos*m_nStepPixels;

	rect->right = rect->left+m_Width*m_nStepPixels;
	rect->bottom = rect->top+m_High*m_nStepPixels;
};


bool CCharObject::readBin(char* FontName,int offset,char *arr, int DataLen )
{
	ifstream file;
 
	file.open(FontName,ios::binary);
	file.seekg(offset,ios::beg);
	file.read(arr,DataLen);
	return true;
}


