// PolygonFillDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GLTest001.h"
#include "PolygonFillDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PolygonFillDlg dialog


PolygonFillDlg::PolygonFillDlg(CWnd* pParent /*=NULL*/)
	: CDialog(PolygonFillDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(PolygonFillDlg)
	m_bFill = FALSE;
	//}}AFX_DATA_INIT
}


void PolygonFillDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PolygonFillDlg)
	DDX_Check(pDX, IDC_CHECK1, m_bFill);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PolygonFillDlg, CDialog)
	//{{AFX_MSG_MAP(PolygonFillDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PolygonFillDlg message handlers
