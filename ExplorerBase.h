#pragma once

class IExplorer
{
public:
	virtual void MakeInWorld(CPoint& pt) = 0;
	virtual void Move() = 0;
	virtual bool DetectSample() = 0;
	virtual void PickUpSample() = 0;
	virtual void MoveToPoint(const CPoint& pointTarget) = 0;
	virtual void Step() = 0;
	virtual bool CarringResource() const = 0;
	virtual bool Returning() const = 0;
	virtual const CPoint& GetPossition()  const = 0;
	virtual const CPoint& GetOldPossition() const = 0;
};
