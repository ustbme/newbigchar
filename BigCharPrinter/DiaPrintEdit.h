#pragma once


// CDiaPrintEdit �Ի���

class CDiaPrintEdit : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaPrintEdit)

public:
	CDiaPrintEdit(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaPrintEdit();

// �Ի�������
	enum { IDD = IDD_DIA_PRINT_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
