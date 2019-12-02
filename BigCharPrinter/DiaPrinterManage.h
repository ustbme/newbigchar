#pragma once


// CDiaPrinterManage 对话框

class CDiaPrinterManage : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaPrinterManage)

public:
	CDiaPrinterManage(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaPrinterManage();

// 对话框数据
	enum { IDD = IDD_DIA_PRINTER_MANAGE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
