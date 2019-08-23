// ImageModeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GLTest001.h"
#include "ImageModeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CImageModeDlg dialog


CImageModeDlg::CImageModeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImageModeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImageModeDlg)
	m_imageFlag = -1;
	//}}AFX_DATA_INIT
}


void CImageModeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImageModeDlg)
	DDX_Radio(pDX, IDC_RADIO1, m_imageFlag);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CImageModeDlg, CDialog)
	//{{AFX_MSG_MAP(CImageModeDlg)
	ON_BN_CLICKED(IDC_RADIO1, OnImageNone)
	ON_BN_CLICKED(IDC_RADIO2, OnImageScale)
	ON_BN_CLICKED(IDC_RADIO3, OnReverse)
	ON_BN_CLICKED(IDC_RADIO4, OnRed)
	ON_BN_CLICKED(IDC_RADIO5, OnGreen)
	ON_BN_CLICKED(IDC_RADIO6, OnBlue)
	ON_BN_CLICKED(IDC_RADIO7, OnGrayMap)
	ON_BN_CLICKED(IDC_RADIO8, OnInverse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageModeDlg message handlers

void CImageModeDlg::OnImageNone() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_ImageFlag=GLNULL;
	this->m_pView->Invalidate();
	UpdateData(FALSE);
}

void CImageModeDlg::OnImageScale() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_ImageFlag=IMAGEZOOM;
	this->m_pView->Invalidate();
	UpdateData(FALSE);
}

void CImageModeDlg::OnReverse() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_ImageFlag=IMAGEREVERSE;
	this->m_pView->Invalidate();
	UpdateData(FALSE);
}

void CImageModeDlg::OnRed() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_ImageFlag=IMAGERED;
	this->m_pView->Invalidate();
	UpdateData(FALSE);
}

void CImageModeDlg::OnGreen() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_ImageFlag=IMAGEGREEN;
	this->m_pView->Invalidate();
	UpdateData(FALSE);
}

void CImageModeDlg::OnBlue() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_ImageFlag=IMAGEBLUE;
	this->m_pView->Invalidate();
	UpdateData(FALSE);
}

void CImageModeDlg::OnGrayMap() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_ImageFlag=IMAGEGRAYMAP;
	this->m_pView->Invalidate();
	UpdateData(FALSE);
}

void CImageModeDlg::OnInverse() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	this->m_pView->m_ImageFlag=IMAGEINVERSE;
	this->m_pView->Invalidate();
	UpdateData(FALSE);
}
