#include "stdafx.h"
#include "IMyButtonAction.h"


IMyButtonAction::IMyButtonAction(COmegaSoftwareView* v) : view(v)
{

}

IMyButtonAction::IMyButtonAction()
{
}

IMyButtonAction::~IMyButtonAction()
{
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

