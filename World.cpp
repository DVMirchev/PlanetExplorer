// World.cpp: implementation of the CWorld class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PlanerExplorer.h"
#include "Explorer.h"
#include "World.h"
#include <random>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

const int gl_nGridSize = 9;

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
	pDC->FillSolidRect((m_ptBasePos.x + 1) * gl_nGridSize + 1,
		(m_ptBasePos.x + 1) * gl_nGridSize + 1,
		4,
		4,
		RGB(255,
			0,
			0
			)
		);

	for (const auto& Explorer : m_vectExplorers)
	{
		DrawExplorer(Explorer, pDC);
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
			car = max( 0, m_arrMatrix[i][j] == 0 ? 255 : 127 - 5 * m_arrMatrix[i][j]);
			pDC->FillSolidRect((i + 1) * gl_nGridSize,
				(j + 1) * gl_nGridSize,
				gl_nGridSize,
				gl_nGridSize,
				RGB(car, car, car)
				);
		}

	for (i = 1; i < MAX_WORLD_X + 2; i++)
	{
		CPen pen(PS_SOLID, 1, RGB(210, 210, 210));
		CPen* ppenOld = pDC->SelectObject(&pen);
		pDC->MoveTo(i * gl_nGridSize, gl_nGridSize);
		pDC->LineTo(i * gl_nGridSize, (MAX_WORLD_X + 1) * gl_nGridSize);
		pDC->MoveTo(gl_nGridSize, i * gl_nGridSize);
		pDC->LineTo((MAX_WORLD_Y + 1) * gl_nGridSize, i * gl_nGridSize);
		pDC->SelectObject(ppenOld);
	}
}

void CWorld::Step()
{
	for (const auto& Explorer : m_vectExplorers)
	{
		Explorer->Step();
	}
}

void CWorld::DrawExplorer(const std::unique_ptr<IExplorer>& pExplorer, CDC *pDC)
{
	COLORREF clrColor;
	if (pExplorer->CarringResource())
		clrColor = RGB(0, 255, 0);
	else
		if (pExplorer->Returning())
			clrColor = RGB(255, 0, 0);
		else
			clrColor = RGB(0, 0, 255);

	COLORREF clrUnderColor;
	if (m_arrMatrix[pExplorer->GetOldPossition().x][pExplorer->GetOldPossition().y])
		clrUnderColor = RGB(155, 155, 155);
	else
		clrUnderColor = RGB(255, 255, 255);

	pDC->FillSolidRect((pExplorer->GetOldPossition().x + 1) * gl_nGridSize + 1,
		(pExplorer->GetOldPossition().y + 1) * gl_nGridSize + 1,
		gl_nGridSize - 1,
		gl_nGridSize - 1,
		clrUnderColor
		);

	pDC->FillSolidRect((pExplorer->GetPossition().x + 1) * gl_nGridSize + 1,
		(pExplorer->GetPossition().y + 1) * gl_nGridSize + 1,
		gl_nGridSize - 1,
		gl_nGridSize - 1,
		clrColor
		);
}

void CWorld::InitWorld()
{
	int i = 0, j = 0;
	m_ptBasePos = CPoint(MAX_WORLD_X / 2, MAX_WORLD_Y / 2);
	for (i = 0; i < gl_nExplorerNumber; i++)
	{
		m_vectExplorers.push_back(std::make_unique<CExplorer>(CPoint(m_ptBasePos.x + 1, m_ptBasePos.y + 1), m_ptBasePos, this));
	}

	for (i = 0; i < MAX_WORLD_X; i++)
		for (j = 0; j < MAX_WORLD_X; j++)
			m_arrMatrix[i][j] = 0;

	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_real_distribution<double> dist(0.0, MAX_WORLD_Y);
	
	for (i = 0; i < gl_nSamplesNumber; i++)
	{
		int XPos = (int) dist(mt);
		int YPos = (int) dist(mt);

		if ( YPos >= MAX_WORLD_Y || XPos >= MAX_WORLD_X)
			continue;

		m_arrMatrix[XPos][YPos] += 30;
	}

	m_arrMatrix[m_ptBasePos.x][m_ptBasePos.y] = 2;
}

void CWorld::CleanWorld()
{
	m_vectExplorers.clear();
}