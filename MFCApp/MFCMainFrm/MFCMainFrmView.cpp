
// MFCMainFrmView.cpp : implementation of the CMFCMainFrmView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCMainFrm.h"
#endif

#include "MFCMainFrmDoc.h"
#include "MFCMainFrmView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCMainFrmView

IMPLEMENT_DYNCREATE(CMFCMainFrmView, CView)

BEGIN_MESSAGE_MAP(CMFCMainFrmView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCMainFrmView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCMainFrmView construction/destruction

CMFCMainFrmView::CMFCMainFrmView() noexcept
{
	// TODO: add construction code here

}

CMFCMainFrmView::~CMFCMainFrmView()
{
}

BOOL CMFCMainFrmView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCMainFrmView drawing

void CMFCMainFrmView::OnDraw(CDC* /*pDC*/)
{
	CMFCMainFrmDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CMFCMainFrmView printing


void CMFCMainFrmView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCMainFrmView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCMainFrmView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCMainFrmView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCMainFrmView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCMainFrmView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCMainFrmView diagnostics

#ifdef _DEBUG
void CMFCMainFrmView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCMainFrmView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCMainFrmDoc* CMFCMainFrmView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCMainFrmDoc)));
	return (CMFCMainFrmDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCMainFrmView message handlers
