#include "StdAfx.h"
#include "ObjectFileDeal.h"
#include "tinyxml.h"


CObjectFileDeal::CObjectFileDeal(void)
{
}


CObjectFileDeal::~CObjectFileDeal(void)
{
}

void CObjectFileDeal::SaveObjectsToXml(char* strFileName)
{
	TiXmlDocument doc(strFileName);

	//从本类中取数据（如m_arrObjects），然后保存
	CCharObject obj;
	sprintf_s(obj.m_texts,"afds");
	m_arrObjects.push_back(obj);
	m_arrObjects.push_back(obj);

	TiXmlElement itemMes( "MES" );

	TiXmlElement itemPro( "PRO" );
	TiXmlText textMatrix( "1L7M" );
	TiXmlElement itemMatrix( "Matrix" );
	itemMatrix.InsertEndChild(textMatrix);
	itemPro.InsertEndChild( itemMatrix );
	itemMes.InsertEndChild( itemPro );

	for(int i = 0; i < m_arrObjects.size(); i++)
	{
		TiXmlElement itemObj( "OBJ" ); 
		TiXmlText textSetTEXT( m_arrObjects[i].m_texts);
		TiXmlElement itemSetTEXT( "setTEXT" );
		itemSetTEXT.InsertEndChild(textSetTEXT);
		itemObj.InsertEndChild( itemSetTEXT );
		itemMes.InsertEndChild( itemObj ); 
	}	 
	doc.InsertEndChild(itemMes);
	doc.SaveFile();

}

void CObjectFileDeal::ReadObjectsFromXml(char* strFileName)
{
	TiXmlDocument doc(strFileName);
	bool loadOkay = doc.LoadFile();

	//vector<CCharObject> m_arrObjects;
	TiXmlNode* node = 0;
	TiXmlElement* todoElement = 0;
	TiXmlElement* itemElement = 0;
	node = doc.FirstChild( "MES" );
	assert( node );
	todoElement = node->ToElement();
	assert( todoElement  );

	node = todoElement->FirstChildElement();	 
	assert( node );
	itemElement = node->ToElement();
	assert( itemElement  );
 
	int count = 0;
	//itemElement = itemElement->NextSiblingElement();
	for( node = todoElement->FirstChildElement();node;node = node->NextSibling() )
	{
		const char* str ;
		str = node->ValueTStr().c_str();
		count++;
		if(strcmp(str,"PRO") == 0)
		{
			//读入信息
			CCharObject obj;
			obj.m_texts;

		}
		else if(strcmp(str,"OBJ") == 0)
		{
			//读入属性信息
			CCharObject obj;
			TiXmlNode* nodeTmp = 0;
			for( nodeTmp = node->IterateChildren(0);nodeTmp;nodeTmp = node->IterateChildren( nodeTmp ) )
			{
				const char* strItem = nodeTmp->ValueTStr().c_str();
				if(strcmp(strItem,"setTEXT") == 0)
				{
					//读入信息
					const char* strText; 
					TiXmlText* nodeText = nodeTmp->FirstChild()->ToText();
					strText = nodeText->ValueTStr().c_str();
					sprintf_s(obj.m_texts,"%s",strText); 
				}
			}
			obj.m_xPos = 100;
			obj.m_yPos = 20;
			m_arrObjects.push_back(obj);
		}
	}	
}

void CObjectFileDeal::DrawObjects(CDC* pDC,int nStepPixels)
{
	for(int i = 0; i < m_arrObjects.size(); i++)
	{
		m_arrObjects[i].DrawObject(pDC,nStepPixels);		 
	}	 
}
