#pragma once


// CDiaMouthClean �Ի���

class CDiaMouthClean : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaMouthClean)

public:
	CDiaMouthClean(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaMouthClean();

// �Ի�������
	enum { IDD = IDD_DIA_MOUTH_CLEAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
