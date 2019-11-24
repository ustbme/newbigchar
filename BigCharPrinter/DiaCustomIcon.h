#pragma once


// CDiaCustomIcon 对话框

class CDiaCustomIcon : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaCustomIcon)

public:
	CDiaCustomIcon(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaCustomIcon();

// 对话框数据
	enum { IDD = IDD_DIA_CUSTOM_ICON };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
