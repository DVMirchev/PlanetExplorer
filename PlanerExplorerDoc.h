// PlanerExplorerDoc.h : interface of the CPlanerExplorerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLANEREXPLORERDOC_H__6211E099_EDDD_4764_AF68_E8DCBFA5DC90__INCLUDED_)
#define AFX_PLANEREXPLORERDOC_H__6211E099_EDDD_4764_AF68_E8DCBFA5DC90__INCLUDED_

#include "World.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CPlanerExplorerDoc : public CDocument
{
protected: // create from serialization only
	CPlanerExplorerDoc();
	DECLARE_DYNCREATE(CPlanerExplorerDoc)

	// Attributes
public:

	// Operations
public:

	// Overrides
		// ClassWizard generated virtual function overrides
		//{{AFX_VIRTUAL(CPlanerExplorerDoc)
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	BOOL m_bReadyToDraw;
	CWorld m_World;
	virtual ~CPlanerExplorerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	void OnInit();
	void OnStep();

protected:

	// Generated message map functions
protected:
	//{{AFX_MSG(CPlanerExplorerDoc)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLANEREXPLORERDOC_H__6211E099_EDDD_4764_AF68_E8DCBFA5DC90__INCLUDED_)
