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
	//读取每个字符的点阵信息
	int startCol = m_xPos;	 

	int nCharNum = strlen(m_texts);
	m_Width = nCharNum*6; //要根据实际占用的列数进行调节
	m_High = 8;
	for(int k = 0; k < nCharNum; k++)
	{
		startCol = m_xPos + k*6; //要根据实际占用的列数进行调节
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
					CBrush* pBrush; //旧笔刷					
					cbrush.CreateSolidBrush(RGB(0,0,0)); 
					pBrush = pDC->SelectObject(&cbrush); //载入笔刷

					CRect rect(col*nStepPixels,row*nStepPixels,(col+1)*nStepPixels,(row+1)*nStepPixels);
					pDC->Ellipse(&rect); 

					pDC->SelectObject(pBrush); //恢复笔刷
					cbrush.DeleteObject();
					pBrush->DeleteObject();
				}
			}
		}
	}
	//绘制被选中后的绿框
	if(m_bSelected)
	{
		CRect rect;
		GetObjectBox(&rect);
		CPen cPen; 
		cPen.CreatePen(PS_SOLID,1,RGB(252,157,154)); 
		CPen* pOldPen; 
		pOldPen = pDC->SelectObject(&cPen); //载入笔刷
 
		//绘制一个矩形即可
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
		//CPen *pOldPen=dc->SelectObject(&pen);//画笔选入设备描述表，并返回当前的画笔
		//CBrush *pBrush=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));//创建一个透明的画刷
		//CBrush *pOldBrush=dc->SelectObject(pBrush);//选择画刷
		//dc->Rectangle(rect);
		//dc->FillRect(rect,pBrush);
		//dc->SelectObject(pOldBrush);//恢复以前 的画刷
		//dc->SelectObject(pOldPen);//恢复以前的画笔
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


