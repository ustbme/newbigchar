#pragma once


// CDiaClassSetting �Ի���

class CDiaClassSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaClassSetting)

public:
	CDiaClassSetting(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaClassSetting();

// �Ի�������
	enum { IDD = IDD_DIA_CLASS_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
