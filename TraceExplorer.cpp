#include "stdafx.h"
#include "TraceExplorer.h"

CTraceExplorer::CTraceExplorer(const CPoint& ptPos, const CPoint& ptBasePos, IWorld* pWorld, const BOOL& bIsCarringResources)
:CExplorer(ptPos, ptBasePos, pWorld, bIsCarringResources)
{
}

CTraceExplorer::~CTraceExplorer(void)
{
}
