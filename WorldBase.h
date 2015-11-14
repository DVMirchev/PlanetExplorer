#pragma once

class IExplorer;

class IWorld
{
public:
	virtual void CleanWorld() = 0;
	virtual void InitWorld() = 0;
	virtual void DrawExplorer(IExplorer* pExplorer, CDC* pDC) = 0;
	virtual void Step() = 0;
	virtual void InitDraw(CDC* pdc) = 0;
	virtual void Draw(CDC* pDC, const bool& bInitDraw) = 0;
	virtual int GetAt(const int& nX, const int& nY) const = 0;
	virtual void SetAt(const int& nX, const int& nY, const int& nValue) = 0;
};
