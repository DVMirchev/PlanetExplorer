// PlanerExplorerDoc.cpp : implementation of the CPlanerExplorerDoc class
//

#include "stdafx.h"
#include "PlanerExplorer.h"	  
#include "Explorer.h"
#include "PlanerExplorerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlanerExplorerDoc

IMPLEMENT_DYNCREATE(CPlanerExplorerDoc, CDocument)

BEGIN_MESSAGE_MAP(CPlanerExplorerDoc, CDocument)
	//{{AFX_MSG_MAP(CPlanerExplorerDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlanerExplorerDoc construction/destruction

CPlanerExplorerDoc::CPlanerExplorerDoc()
{
	m_bReadyToDraw = FALSE;
}

CPlanerExplorerDoc::~CPlanerExplorerDoc()
{
}

BOOL CPlanerExplorerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPlanerExplorerDoc serialization

void CPlanerExplorerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CPlanerExplorerDoc diagnostics

#ifdef _DEBUG
void CPlanerExplorerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPlanerExplorerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPlanerExplorerDoc commands

void CPlanerExplorerDoc::OnInit() 
{
	m_bReadyToDraw = TRUE;
	m_World.CleanWorld();
	m_World.InitWorld();
}

void CPlanerExplorerDoc::OnStep() 
{
	m_World.Step();
}
