#pragma once


// CDiaClassSetting 对话框

class CDiaClassSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaClassSetting)

public:
	CDiaClassSetting(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CDiaClassSetting();

// 对话框数据
	enum { IDD = IDD_DIA_CLASS_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
