#pragma once


// CDiaMouthClean 对话框

class CDiaMouthClean : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaMouthClean)

public:
	CDiaMouthClean(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaMouthClean();

// 对话框数据
	enum { IDD = IDD_DIA_MOUTH_CLEAN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
