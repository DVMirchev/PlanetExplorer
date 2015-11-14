#if !defined(AFX_STATDIALOGBAR_H__42E041E6_BF2D_49F9_8F22_86D0E3C36307__INCLUDED_)
#define AFX_STATDIALOGBAR_H__42E041E6_BF2D_49F9_8F22_86D0E3C36307__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "resource.h"
// StatDialogBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CStatDialogBar dialog

class CStatDialogBar : public CDialogBar
{
	// Construction
public:
	CStatDialogBar();   // standard constructor

// Dialog Data
	//{{AFX_DATA(CStatDialogBar)
	enum { IDD = IDD_STATISTICS_DIALOGBAR };
	CString	m_strMoves;
	CString	m_strAverageMoves;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatDialogBar)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CStatDialogBar)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATDIALOGBAR_H__42E041E6_BF2D_49F9_8F22_86D0E3C36307__INCLUDED_)
