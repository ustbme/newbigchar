#pragma once

#include "CharObject.h"

#include <vector>

using namespace std;

class CObjectFileDeal
{
public:
	CObjectFileDeal(void);
	~CObjectFileDeal(void);

public:

	vector<CCharObject> m_arrObjects; //a.insert(v,6);

public:
	void ReadObjectsFromXml(char* strFileName);
	void SaveObjectsToXml(char* strFileName);
	void DrawObjects(CDC* pDC,int nStepPixels);

};

