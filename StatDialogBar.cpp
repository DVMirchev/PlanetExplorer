// StatDialogBar.cpp : implementation file
//

#include "stdafx.h"
#include "PlanerExplorer.h"
#include "StatDialogBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStatDialogBar dialog


CStatDialogBar::CStatDialogBar()
	: CDialogBar()
{
	//{{AFX_DATA_INIT(CStatDialogBar)
	m_strMoves = _T("");
	m_strAverageMoves = _T("");
	//}}AFX_DATA_INIT
}


void CStatDialogBar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CStatDialogBar)
	DDX_Text(pDX, IDC_MOVES, m_strMoves);
	DDX_Text(pDX, IDC_AVERAGE_MOVES, m_strAverageMoves);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CStatDialogBar, CDialogBar)
	//{{AFX_MSG_MAP(CStatDialogBar)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStatDialogBar message handlers
