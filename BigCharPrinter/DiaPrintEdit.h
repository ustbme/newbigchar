#pragma once


// CDiaPrintEdit 对话框

class CDiaPrintEdit : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaPrintEdit)

public:
	CDiaPrintEdit(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaPrintEdit();

// 对话框数据
	enum { IDD = IDD_DIA_PRINT_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
