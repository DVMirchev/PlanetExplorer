// World.cpp: implementation of the CWorld class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PlanerExplorer.h"
#include "Explorer.h"
#include "World.h"

#include <algorithm>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWorld::CWorld() {
    InitWorld();
}

CWorld::~CWorld() {
    CleanWorld();
}

#include "MainFrm.h"
void CWorld::Draw(CDC *pDC, BOOL bInitDraw) {
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


    for (const auto& explorer : m_vectExplorers) {
        DrawExplorer(explorer, pDC);
    }

}

void CWorld::InitDraw(CDC *pDC) {
    for (int i = 0; i < MAX_WORLD_X; i++)
        for (int j = 0; j < MAX_WORLD_X; j++) {
            const auto car = m_arrMatrix[i][j];
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

    for (int i = 1; i < MAX_WORLD_X + 2; i++) {
        CPen pen(PS_SOLID, 1, RGB(210, 210, 210));
        CPen* ppenOld = pDC->SelectObject(&pen);
        pDC->MoveTo(i * 5, 5);
        pDC->LineTo(i * 5, (MAX_WORLD_X + 1) * 5);
        pDC->MoveTo(5, i * 5);
        pDC->LineTo((MAX_WORLD_Y + 1) * 5, i * 5);
        pDC->SelectObject(ppenOld);
    }


}

void CWorld::Step() {
    for (auto& explorer : m_vectExplorers) {
        explorer->Step();
    }
}

void CWorld::DrawExplorer(const std::unique_ptr<CExplorer>& pExplorer, CDC *pDC) {
    const COLORREF clrColor = [&]() {
        if (pExplorer->m_bIsCarringResource)
            return RGB(0, 0, 0);
        else
            return RGB(0, 0, 255);
    }();


    const COLORREF clrUnderColor = [&]() {
        if (m_arrMatrix[pExplorer->m_ptOldPos.x][pExplorer->m_ptOldPos.y])
            return RGB(155, 155, 155);
        else
            return RGB(255, 255, 255);
    }();

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

void CWorld::InitWorld() {
    m_ptBasePos = CPoint(MAX_WORLD_X / 2, MAX_WORLD_Y / 2);
    for (int i = 0; i < gl_nExplorerNumber; i++) {
        m_vectExplorers.push_back(std::make_unique<CExplorer>(CPoint(m_ptBasePos.x + 1, m_ptBasePos.y + 1), m_ptBasePos, *this));
    }

    for (int i = 0; i < MAX_WORLD_X; i++)
        for (int j = 0; j < MAX_WORLD_X; j++)
            m_arrMatrix[i][j] = 0;

    for (int i = 0; i < gl_nSamplesNumber; i++) {
        int XPos = std::clamp<int>(0, static_cast<int>((MAX_WORLD_X - 1)* (((float) rand()) / ((float) RAND_MAX))), MAX_WORLD_X - 1);
        int YPos = std::clamp<int>(0, static_cast<int>((MAX_WORLD_Y - 1) * (((float) rand()) / ((float) RAND_MAX))), MAX_WORLD_Y - 1);

        m_arrMatrix[XPos][YPos] = 1;

    }

    m_arrMatrix[m_ptBasePos.x][m_ptBasePos.y] = 2;
}

void CWorld::CleanWorld() {
    m_vectExplorers.clear();
}
