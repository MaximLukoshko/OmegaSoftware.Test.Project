#include "stdafx.h"
#include "MyAction.h"
#include "IMyButtonAction.h"
#include "OmegaSoftwareView.h"


MyAction::MyAction()
{
}

MyAction::~MyAction()
{
}

void MyAction::Serialize(CArchive& archive)
{
	IMyButtonAction::Serialize(archive);
	archive << ActionStartPoint.x << ActionStartPoint.y << ActionStopPoint.x << ActionStopPoint.y;
}