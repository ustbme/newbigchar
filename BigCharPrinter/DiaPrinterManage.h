#pragma once


// CDiaPrinterManage �Ի���

class CDiaPrinterManage : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaPrinterManage)

public:
	CDiaPrinterManage(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaPrinterManage();

// �Ի�������
	enum { IDD = IDD_DIA_PRINTER_MANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
