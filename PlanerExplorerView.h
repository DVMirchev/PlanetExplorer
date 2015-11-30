// PlanerExplorerView.h : interface of the CPlanerExplorerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANEREXPLORERVIEW_H__0E2033AC_D2D2_403D_B89F_2E84ED64D9E2__INCLUDED_)
#define AFX_PLANEREXPLORERVIEW_H__0E2033AC_D2D2_403D_B89F_2E84ED64D9E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPlanerExplorerView : public CView
{
protected: // create from serialization only
	CPlanerExplorerView();
	DECLARE_DYNCREATE(CPlanerExplorerView)

	// Attributes
public:
	CPlanerExplorerDoc* GetDocument();

	// Operations
public:

	// Overrides
		// ClassWizard generated virtual function overrides
		//{{AFX_VIRTUAL(CPlanerExplorerView)
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPlanerExplorerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// Generated message map functions
protected:
	bool m_bCallInitDraw;
	int m_nTimer;
	//{{AFX_MSG(CPlanerExplorerView)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLoop();
	afx_msg void OnStep();
	afx_msg void OnStop();
	afx_msg void OnInit();
	afx_msg void OnOptionsOptions();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in PlanerExplorerView.cpp
inline CPlanerExplorerDoc* CPlanerExplorerView::GetDocument()
{
	return static_cast<CPlanerExplorerDoc*> (m_pDocument);
}
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLANEREXPLORERVIEW_H__0E2033AC_D2D2_403D_B89F_2E84ED64D9E2__INCLUDED_)
