// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__14D71D34_12ED_4E2A_AA22_28EA94B96603__INCLUDED_)
#define AFX_STDAFX_H__14D71D34_12ED_4E2A_AA22_28EA94B96603__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include <vector>

const int MAX_WORLD_X = 100;
const int MAX_WORLD_Y = 100;
extern int gl_nSamplesNumber;
extern int gl_nExplorerNumber;
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STDAFX_H__14D71D34_12ED_4E2A_AA22_28EA94B96603__INCLUDED_)
