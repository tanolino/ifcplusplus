// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#include "stdafx.h"

#include <ifcpp/IFC4/include/IfcCartesianPoint.h>
#include <ifcpp/IFC4/include/IfcDirection.h>
#include <ifcpp/IFC4/include/IfcGloballyUniqueId.h>
#include <ifcpp/IFC4/include/IfcIdentifier.h>
#include <ifcpp/IFC4/include/IfcLabel.h>
#include <ifcpp/IFC4/include/IfcLengthMeasure.h>
#include <ifcpp/IFC4/include/IfcReal.h>
#include <ifcpp/IFC4/include/IfcText.h>
#include <ifcpp/model/AttributeObject.h>
#include "PropertiesWnd.h"
#include "Resource.h"
#include "MainFrame.h"
#include "IfcQueryMFC.h"
#include "BuildingUtils.h"
#include "IfcQueryDoc.h"
#include "WindowUtils.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

/////////////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP( MyPropertyGridCtrl, CMFCPropertyGridCtrl )
	ON_WM_DESTROY()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

MyPropertyGridCtrl::MyPropertyGridCtrl()
	: CMFCPropertyGridCtrl()
{
	//SetCustomColors( RGB( 228, 243, 254 ), RGB( 46, 70, 165 ), RGB( 200, 236, 209 ), RGB( 33, 102, 49 ), RGB( 255, 229, 216 ), RGB( 128, 0, 0 ), RGB( 159, 159, 255 ) );

	COLORREF clrBackground = -1;
	COLORREF clrText = -1;
	COLORREF clrGroupBackground = RGB( 250, 252, 254 );
	COLORREF clrGroupText = RGB( 28, 43, 54 );
	COLORREF clrDescriptionBackground = -1;
	COLORREF clrDescriptionText = -1;
	COLORREF clrLine = -1;

	SetCustomColors( clrBackground, clrText, clrGroupBackground, clrGroupText, clrDescriptionBackground, clrDescriptionText, clrLine );

}

void MyPropertyGridCtrl::OnLButtonDown( UINT nFlags, CPoint point )
{
	CMFCPropertyGridCtrl::OnLButtonDown( nFlags, point );

	CMFCPropertyGridProperty::ClickArea clickArea;
	CMFCPropertyGridProperty *pProp = HitTest( point, &clickArea );
	if( CMFCPropertyGridProperty::ClickExpandBox == clickArea )
	{
		// "+" indicator has been clicked, append properties of current property
		int cnt = pProp->GetSubItemsCount();
		if( pProp->GetSubItemsCount() > 0 )
		{
			return;
		}
	
		MyGridProperty * myProp = dynamic_cast<MyGridProperty*>(pProp);
		if( myProp )
		{
			if( myProp->m_buildingObject )
			{
				shared_ptr<BuildingEntity> attributeEntity = dynamic_pointer_cast<BuildingEntity>(myProp->m_buildingObject);
				if( attributeEntity )
				{
					addPropertyItems( attributeEntity, myProp, false, myProp->m_isInverse );
				}
			}
		}

		pProp->Expand();
		AdjustLayout();
	}
}
