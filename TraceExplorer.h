#pragma once
#include "explorer.h"

class IWorld;

class CTraceExplorer :
	public CExplorer
{
public:
	CTraceExplorer(const CPoint& ptPos, const CPoint& ptBasePos, IWorld* pWorld, const BOOL& bIsCarringResources);
public:
	virtual ~CTraceExplorer(void);
};
