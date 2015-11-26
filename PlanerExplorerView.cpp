// PlanerExplorerView.cpp : implementation of the CPlanerExplorerView class
//

#include "stdafx.h"
#include "PlanerExplorer.h"

#include "PlanerExplorerDoc.h"
#include "PlanerExplorerView.h"
#include "OptionDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlanerExplorerView

IMPLEMENT_DYNCREATE(CPlanerExplorerView, CView)

BEGIN_MESSAGE_MAP(CPlanerExplorerView, CView)
	//{{AFX_MSG_MAP(CPlanerExplorerView)
	ON_WM_TIMER()
	ON_COMMAND(ID_LOOP, OnLoop)
	ON_COMMAND(ID_STEP, OnStep)
	ON_COMMAND(ID_STOP, OnStop)
	ON_COMMAND(ID_INIT, OnInit)
	ON_COMMAND(ID_OPTIONS_OPTIONS, OnOptionsOptions)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlanerExplorerView construction/destruction

CPlanerExplorerView::CPlanerExplorerView()
{
	m_bCallInitDraw = TRUE;
}

CPlanerExplorerView::~CPlanerExplorerView()
{
}

BOOL CPlanerExplorerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CPlanerExplorerView drawing

void CPlanerExplorerView::OnDraw(CDC* pDC)
{
	CPlanerExplorerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc->m_bReadyToDraw)
		return;

	pDoc->m_World.Draw(pDC, m_bCallInitDraw);

	m_bCallInitDraw = TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CPlanerExplorerView printing

BOOL CPlanerExplorerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPlanerExplorerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPlanerExplorerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CPlanerExplorerView diagnostics

#ifdef _DEBUG
void CPlanerExplorerView::AssertValid() const
{
	CView::AssertValid();
}

void CPlanerExplorerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPlanerExplorerDoc* CPlanerExplorerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPlanerExplorerDoc)));
	return (CPlanerExplorerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPlanerExplorerView message handlers

void CPlanerExplorerView::OnTimer(UINT nIDEvent)
{
	OnStep();

	CView::OnTimer(nIDEvent);
}

void CPlanerExplorerView::OnLoop()
{
	m_nTimer = SetTimer(1, 50, 0);
}

void CPlanerExplorerView::OnStep()
{
	(<CPlanerExplorerDoc*> (GetDocument()))->OnStep();
	m_bCallInitDraw = FALSE;
	Invalidate(FALSE);
}

void CPlanerExplorerView::OnStop()
{
	KillTimer(m_nTimer);
}

void CPlanerExplorerView::OnInit()
{
	KillTimer(m_nTimer);
	srand(GetTickCount());
	(<CPlanerExplorerDoc*> (GetDocument()))->OnInit();
	m_bCallInitDraw = TRUE;
	Invalidate(FALSE);
}

void CPlanerExplorerView::OnOptionsOptions()
{
	COptionDialog dlgOptions(gl_nSamplesNumber, gl_nExplorerNumber);

	if (dlgOptions.DoModal() == IDOK)
	{
		gl_nSamplesNumber = dlgOptions.m_nSamplesNumber;
		gl_nExplorerNumber = dlgOptions.m_nExplorersNumber;
	}
}