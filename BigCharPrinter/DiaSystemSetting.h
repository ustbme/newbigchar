#pragma once


// CDiaSystemSetting �Ի���

class CDiaSystemSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CDiaSystemSetting)

public:
	CDiaSystemSetting(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDiaSystemSetting();

// �Ի�������
	enum { IDD = IDD_DIA_SYSTEM_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
};
