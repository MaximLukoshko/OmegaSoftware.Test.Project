#include "stdafx.h"
#include "IMyButtonAction.h"

IMyButtonAction::IMyButtonAction()
{
}

IMyButtonAction::~IMyButtonAction()
{
}

void IMyButtonAction::OnMouseMoveReaction(CPoint StartPoint, CPoint StopPoint)
{
	ActionStartPoint = StartPoint;
	ActionStopPoint = StopPoint;
}

void IMyButtonAction::Serialize(CArchive& archive)
{
	if (archive.IsStoring())
	{
		archive << this->getClassCode();
	}
	else
	{

	}
}

int IMyButtonAction::getClassCode()
{
	return classCode;
}