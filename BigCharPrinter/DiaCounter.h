#pragma once


// CDiaCounter �Ի���

class CDiaCounter : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaCounter)

public:
	CDiaCounter(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaCounter();

// �Ի�������
	enum { IDD = IDD_DIA_COUNTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
