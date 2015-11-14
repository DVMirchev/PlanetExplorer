// Explorer.cpp: implementation of the CExplorer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PlanerExplorer.h"
#include "Explorer.h"
#include "World.h"
#include "math.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CExplorer::CExplorer(CPoint ptPos, CPoint ptBasePos, IWorld* pWorld, BOOL bIsCarringResource)
{
	m_ptBasePos = ptBasePos;
	m_ptPos = ptPos;
	m_ptOldPos = m_ptPos;
	m_bIsCarringResource = bIsCarringResource;
	m_pWorld = pWorld;
}

CExplorer::~CExplorer()
{

}

void CExplorer::Step()
{
	if (m_bIsCarringResource && AtTheBase())
	{
		m_bIsCarringResource = FALSE;
		return;
	}

	if (m_bIsCarringResource && !AtTheBase())
	{
		MoveToBase();
		return;
	}

	if (DetectSample())
	{
		PickUpSample();
		return;
	}

	Move();

}

BOOL CExplorer::AtTheBase()
{
	if ((abs(m_ptPos.x - m_ptBasePos.x) <= 1) && 
		(abs(m_ptPos.y - m_ptBasePos.y) <= 1))
		return TRUE;
	else 
		return FALSE;
}			

int sign( int n )
{
	if( n == 0 )
		return 0;
	else
		return n / abs( n );
}

void CExplorer::MoveToBase()
{
	int nOffsetX = m_ptBasePos.x - m_ptPos.x;	
	int nOffsetY = m_ptBasePos.y - m_ptPos.y;	

	m_ptOldPos = m_ptPos;

	m_ptPos.x += sign(nOffsetX);
	m_ptPos.y += sign(nOffsetY);
}

void CExplorer::PickUpSample()
{
	if (m_pWorld->GetAt(m_ptPos.x, m_ptPos.y) != 1)
		ASSERT(FALSE);
	m_bIsCarringResource = TRUE;
	m_pWorld->GetAt(m_ptPos.x, m_ptPos.y)  = 0;
}

BOOL CExplorer::DetectSample()
{
	if (m_pWorld->GetAt(m_ptPos.x, m_ptPos.y) == 1)
		return TRUE;
	return FALSE;
}

int Get_M1_0_P1()
{
	
	TRACE(_T("To use C++ rand DMTK"));

	int ret = (int) floor( (3 * rand() - 1) / RAND_MAX ) - 1;	
	return ret;
}

void CExplorer::Move()
{
	m_ptOldPos = m_ptPos;
	int arrXPos[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	do
	{
		int XOffset = Get_M1_0_P1();
		int YOffset = Get_M1_0_P1();
		if (arrXPos[XOffset + 1][YOffset + 1] == 1)
			continue;
		else 
			arrXPos[XOffset + 1][YOffset + 1] = 1; 

		CPoint pt( m_ptPos.x + XOffset, m_ptPos.y + YOffset);
		CPoint pt2 = pt;
		MakeInWorld(pt);
		if (pt != pt2)
			continue;

		if (m_pWorld->GetAt(m_ptPos.x + XOffset, m_ptPos.y + YOffset) == 1)
		{
			m_ptPos.x += XOffset;					
			m_ptPos.y += YOffset;					
			return;
		}

	} while ((arrXPos[0][0] == 1) && (arrXPos[1][0] == 1) && (arrXPos[2][0] == 1) &&
			 (arrXPos[0][1] == 1) && (arrXPos[1][1] == 1) && (arrXPos[2][1] == 1) &&
			 (arrXPos[0][2] == 1) && (arrXPos[1][2] == 1) && (arrXPos[2][2] == 1));

	int XOffset = Get_M1_0_P1();
	int YOffset = Get_M1_0_P1();

	m_ptPos.x += XOffset;
	m_ptPos.y += YOffset;

	MakeInWorld(m_ptPos);

}

void CExplorer::MakeInWorld(CPoint& pt)
{
	if (pt.x < 0) pt.x = 0;
	if (pt.x > MAX_WORLD_X - 1) pt.x = MAX_WORLD_X - 1;
	if (pt.y < 0) pt.y = 0;
	if (pt.y > MAX_WORLD_Y - 1) pt.y = MAX_WORLD_Y - 1;

}
