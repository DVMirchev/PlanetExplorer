#if !defined(AFX_OPTIONDIALOG_H__372DC9BA_5BA6_4CB9_B6C4_A00F5903DB1E__INCLUDED_)
#define AFX_OPTIONDIALOG_H__372DC9BA_5BA6_4CB9_B6C4_A00F5903DB1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptionDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptionDialog dialog

class COptionDialog : public CDialog
{
	// Construction
public:
	COptionDialog(int nSamplesNumber, int nExplorersNumber, CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COptionDialog)
	enum { IDD = IDD_DIALOG1 };
	int		m_nSamplesNumber;
	int		m_nExplorersNumber;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptionDialog)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptionDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONDIALOG_H__372DC9BA_5BA6_4CB9_B6C4_A00F5903DB1E__INCLUDED_)
