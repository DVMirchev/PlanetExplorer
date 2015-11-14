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
	void MoveToBase() override;
	void Step() override;
	bool CarringResource() const override { return m_bIsCarringResource; }
	const CPoint& GetPossition()  const override { return m_ptPos; }
	const CPoint& GetOldPossition() const override {return m_ptOldPos;}

private:

	IWorld* m_pWorld;
	bool m_bIsCarringResource;
	CPoint m_ptBasePos;
	CPoint m_ptPos;
	CPoint m_ptOldPos;


protected:
	BOOL AtTheBase();
};

#endif // !defined(AFX_EXPLORER_H__0FEC0E11_5B3F_4491_A31A_9EBDB637A8EB__INCLUDED_)
