// World.h: interface for the CWorld class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_WORLD_H__B168B888_ABE7_4007_BA40_721B3359D256__INCLUDED_)
#define AFX_WORLD_H__B168B888_ABE7_4007_BA40_721B3359D256__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <array>
#include <memory>

class CExplorer; 

class CWorld  
{
public:
    void CleanWorld();
    void InitWorld();
    void DrawExplorer(const std::unique_ptr<CExplorer>& pExplorer, CDC* pDC);
    void Step();
    void InitDraw(CDC* pdc);
    void Draw(CDC* pDC, BOOL bInitDraw);
    CWorld();
    virtual ~CWorld();
 
    std::array<std::array<int, MAX_WORLD_X>, MAX_WORLD_Y> m_arrMatrix;

    std::vector<std::unique_ptr<CExplorer>> m_vectExplorers;
    CPoint m_ptBasePos;
};

#endif // !defined(AFX_WORLD_H__B168B888_ABE7_4007_BA40_721B3359D256__INCLUDED_)
