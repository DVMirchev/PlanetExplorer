// Explorer.h: interface for the CExplorer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_EXPLORER_H__0FEC0E11_5B3F_4491_A31A_9EBDB637A8EB__INCLUDED_)
#define AFX_EXPLORER_H__0FEC0E11_5B3F_4491_A31A_9EBDB637A8EB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ExplorerBase.h"

class IWorld;

class CExplorer	 : public IExplorer
{
public:
	CExplorer(CPoint ptPos, CPoint ptBasePos, IWorld* pWorld, bool bIsCarringResource = false);
	virtual ~CExplorer();

	void MakeInWorld(CPoint& pt) override;
	void Move() override;
	bool DetectSample() override;
	void PickUpSample() override;
	void MoveToPoint(const CPoint& pointTarget) override;
	void Step() override;
	bool CarringResource() const override { return m_bIsCarringResource; }
	bool Returning() const override { return m_bIsReturningToLast; }
	const CPoint& GetPossition()  const override { return m_ptPos; }
	const CPoint& GetOldPossition() const override {return m_ptOldPos;}

private:

	IWorld* m_pWorld;

	bool m_bIsCarringResource;
	CPoint m_ptBasePos;

	bool m_bIsReturningToLast = false;
	CPoint m_ptLastResourcePos;

	CPoint m_ptPos;
	CPoint m_ptOldPos;


protected:
	bool AtThePoint(const CPoint& pointTarget);
};

#endif // !defined(AFX_EXPLORER_H__0FEC0E11_5B3F_4491_A31A_9EBDB637A8EB__INCLUDED_)
