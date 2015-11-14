// OptionDialog.cpp : implementation file
//

#include "stdafx.h"
#include "PlanerExplorer.h"
#include "OptionDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COptionDialog dialog


COptionDialog::COptionDialog(int nSamplesNumber, int nExplorersNumber, CWnd* pParent /*=NULL*/)
	: CDialog(COptionDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(COptionDialog)
	m_nSamplesNumber = nSamplesNumber;
	m_nExplorersNumber = nExplorersNumber;
	//}}AFX_DATA_INIT
}


void COptionDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COptionDialog)
	DDX_Text(pDX, IDC_SAMPLES, m_nSamplesNumber);
	DDX_Text(pDX, IDC_EXPLORERS, m_nExplorersNumber);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COptionDialog, CDialog)
	//{{AFX_MSG_MAP(COptionDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionDialog message handlers
