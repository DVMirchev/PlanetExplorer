// Explorer.h: interface for the CExplorer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPLORER_H__0FEC0E11_5B3F_4491_A31A_9EBDB637A8EB__INCLUDED_)
#define AFX_EXPLORER_H__0FEC0E11_5B3F_4491_A31A_9EBDB637A8EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class IWorld;

class CExplorer
{
public:
	CExplorer(CPoint ptPos, CPoint ptBasePos, IWorld* pWorld, BOOL bIsCarringResource = FALSE);

	void MakeInWorld(CPoint& pt);
	IWorld* m_pWorld;
	void Move();
	BOOL DetectSample();
	void PickUpSample();
	void MoveToBase();
	void Step();

	BOOL m_bIsCarringResource;
	CPoint m_ptBasePos;
	CPoint m_ptPos;
	CPoint m_ptOldPos;

	virtual ~CExplorer();

protected:
	BOOL AtTheBase();
};

#endif // !defined(AFX_EXPLORER_H__0FEC0E11_5B3F_4491_A31A_9EBDB637A8EB__INCLUDED_)
