#pragma once

class IExplorer
{
public:
	virtual void MakeInWorld(CPoint& pt) = 0;
	virtual void Move() = 0;
	virtual bool DetectSample() = 0;
	virtual void PickUpSample() = 0;
	virtual void MoveToBase() = 0;
 	virtual void Step() = 0;
};
