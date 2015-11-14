// World.cpp: implementation of the CWorld class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PlanerExplorer.h"
#include "Explorer.h"
#include "World.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWorld::CWorld()
{
	InitWorld();
}

CWorld::~CWorld()
{
	CleanWorld();
}

void CWorld::Draw(CDC* pDC, const bool& bInitDraw)
{
	if (bInitDraw)
		InitDraw(pDC);

	// Set Status Bar Text
//	CString str;
//	str.Format("bIsCarringSample: %d", m_pExplorer->m_bIsCarringResource );
//	((CMainFrame*) AfxGetMainWnd())->m_wndStatusBar.SetPaneText( 1, str, TRUE );
	//	pDC->TextOut(0, 0, str);

	// Draw Base
	pDC->FillSolidRect((m_ptBasePos.x + 1) * 5 + 1,
		(m_ptBasePos.x + 1) * 5 + 1,
		4,
		4,
		RGB(255,
			0,
			0
			)
		);

	for (std::vector<CExplorer*>::iterator it = m_vectExplorers.begin(); it != m_vectExplorers.end(); it++)
	{
		DrawExplorer(*it, pDC);
	}
}

void CWorld::InitDraw(CDC *pDC)
{
	int i;
	int j;
	int car;

	for (i = 0; i < MAX_WORLD_X; i++)
		for (j = 0; j < MAX_WORLD_X; j++)
		{
			car = m_arrMatrix[i][j];
			pDC->FillSolidRect((i + 1) * 5,
				(j + 1) * 5,
				5,
				5,
				RGB(255 - 100 * car,
					255 - 100 * car,
					255 - 100 * car
					)
				);
		}

	for (i = 1; i < MAX_WORLD_X + 2; i++)
	{
		CPen pen(PS_SOLID, 1, RGB(210, 210, 210));
		CPen* ppenOld = pDC->SelectObject(&pen);
		pDC->MoveTo(i * 5, 5);
		pDC->LineTo(i * 5, (MAX_WORLD_X + 1) * 5);
		pDC->MoveTo(5, i * 5);
		pDC->LineTo((MAX_WORLD_Y + 1) * 5, i * 5);
		pDC->SelectObject(ppenOld);
	}
}

void CWorld::Step()
{
	for (std::vector<CExplorer*>::iterator it = m_vectExplorers.begin(); it != m_vectExplorers.end(); it++)
	{
		(*it)->Step();
	}
}

void CWorld::DrawExplorer(CExplorer *pExplorer, CDC *pDC)
{
	COLORREF clrColor;
	if (pExplorer->m_bIsCarringResource)
		clrColor = RGB(0, 0, 0);
	else
		clrColor = RGB(0, 0, 255);

	COLORREF clrUnderColor;
	if (m_arrMatrix[pExplorer->m_ptOldPos.x][pExplorer->m_ptOldPos.y])
		clrUnderColor = RGB(155, 155, 155);
	else
		clrUnderColor = RGB(255, 255, 255);

	pDC->FillSolidRect((pExplorer->m_ptOldPos.x + 1) * 5 + 1,
		(pExplorer->m_ptOldPos.y + 1) * 5 + 1,
		4,
		4,
		clrUnderColor
		);

	pDC->FillSolidRect((pExplorer->m_ptPos.x + 1) * 5 + 1,
		(pExplorer->m_ptPos.y + 1) * 5 + 1,
		4,
		4,
		clrColor
		);
}

void CWorld::InitWorld()
{
	int i = 0, j = 0;
	m_ptBasePos = CPoint(MAX_WORLD_X / 2, MAX_WORLD_Y / 2);
	CExplorer* pExplorer = NULL;
	for (i = 0; i < gl_nExplorerNumber; i++)
	{
		pExplorer = new CExplorer(CPoint(m_ptBasePos.x + 1, m_ptBasePos.y + 1), m_ptBasePos, this);
		m_vectExplorers.push_back(pExplorer);
	}

	for (i = 0; i < MAX_WORLD_X; i++)
		for (j = 0; j < MAX_WORLD_X; j++)
			m_arrMatrix[i][j] = 0;

	for (i = 0; i < gl_nSamplesNumber; i++)
	{
		int XPos = (int)MAX_WORLD_X * (((float)rand()) / ((float)RAND_MAX));
		int YPos = (int)MAX_WORLD_Y * (((float)rand()) / ((float)RAND_MAX));

		m_arrMatrix[XPos][YPos] = 1;
	}

	m_arrMatrix[m_ptBasePos.x][m_ptBasePos.y] = 2;
}

void CWorld::CleanWorld()
{
	for (std::vector<CExplorer*>::iterator it = m_vectExplorers.begin(); it != m_vectExplorers.end(); it++)
	{
		if (*it != NULL)
			delete[] * it;
	}
	m_vectExplorers.clear();
}