#pragma once


// CDiaPrintParam 对话框

class CDiaPrintParam : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaPrintParam)

public:
	CDiaPrintParam(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaPrintParam();

// 对话框数据
	enum { IDD = IDD_DIA_PRINT_PARAM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
