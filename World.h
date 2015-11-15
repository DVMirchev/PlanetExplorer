// World.h: interface for the CWorld class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORLD_H__B168B888_ABE7_4007_BA40_721B3359D256__INCLUDED_)
#define AFX_WORLD_H__B168B888_ABE7_4007_BA40_721B3359D256__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "WorldBase.h"

class CExplorer;

class CWorld : public IWorld
{
public:

	void CleanWorld() override;
	void InitWorld() override;
	void DrawExplorer(IExplorer* pExplorer, CDC* pDC) override;
	void Step() override;
	void InitDraw(CDC* pdc) override;
	void Draw(CDC* pDC, const bool& bInitDraw) override;
	int GetAt(const int& nX, const int& nY) const override { return m_arrMatrix[nX][nY]; }
	void SetAt(const int& nX, const int& nY, const int& nValue) override { m_arrMatrix[nX][nY] = max( 0, nValue); }

public:
	//void CleanWorld();
	//void InitWorld();
	//void DrawExplorer(CExplorer* pExplorer, CDC* pDC);
	//void Step();
	//void InitDraw(CDC* pdc);
	//void Draw(CDC* pDC, BOOL bInitDraw);
	CWorld();
	virtual ~CWorld();

	int m_arrMatrix[MAX_WORLD_X][MAX_WORLD_Y];

	std::vector<IExplorer*> m_vectExplorers;
	CPoint m_ptBasePos;
};

#endif // !defined(AFX_WORLD_H__B168B888_ABE7_4007_BA40_721B3359D256__INCLUDED_)
