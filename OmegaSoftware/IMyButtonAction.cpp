#include "stdafx.h"
#include "IMyButtonAction.h"


IMyButtonAction::IMyButtonAction(COmegaSoftwareView* v) : view(v)
{
	rectangle = new CRect(0, 0, 100, 100);
}

IMyButtonAction::IMyButtonAction()
{
}

IMyButtonAction::~IMyButtonAction()
{
}
