#pragma once


// CDiaCounter 对话框

class CDiaCounter : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaCounter)

public:
	CDiaCounter(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaCounter();

// 对话框数据
	enum { IDD = IDD_DIA_COUNTER };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
