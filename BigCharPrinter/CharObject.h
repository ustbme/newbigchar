#pragma once
class CCharObject
{
public:
	CCharObject(void);
	~CCharObject(void);

public:

	char  m_texts[256];
	int   m_xPos;
	int   m_yPos;

	int   m_Width;
	int   m_High;

	bool m_bSelected;

	int m_nStepPixels;

public:
	void DrawObject(CDC* pDC,int nStepPixels);
	bool readBin(char* FontName,int offset,char *arr, int DataLen);
	void GetObjectBox(CRect* rect);
};

