
// LeftView.h : CLeftView 类的接口
//


#pragma once

class CBigCharPrinterDoc;

class CLeftView : public CTreeView
{
protected: // 仅从序列化创建
	CLeftView();
	DECLARE_DYNCREATE(CLeftView)

// 特性
public:
	CBigCharPrinterDoc* GetDocument();

// 操作
public:

// 重写
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CLeftView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // LeftView.cpp 中的调试版本
inline CBigCharPrinterDoc* CLeftView::GetDocument()
   { return reinterpret_cast<CBigCharPrinterDoc*>(m_pDocument); }
#endif

