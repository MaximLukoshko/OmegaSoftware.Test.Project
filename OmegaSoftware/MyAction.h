#pragma once
#include "IMyButtonAction.h"
#include "OmegaSoftwareView.h"
#include "atltypes.h"
class MyAction :
	public IMyButtonAction
{
public:
	MyAction();
	virtual ~MyAction();
	virtual void Serialize(CArchive& archive);
};

