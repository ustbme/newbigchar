#pragma once


// CDiaPrintParam �Ի���

class CDiaPrintParam : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaPrintParam)

public:
	CDiaPrintParam(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaPrintParam();

// �Ի�������
	enum { IDD = IDD_DIA_PRINT_PARAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
