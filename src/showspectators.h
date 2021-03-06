#ifndef __SHOWSPECTATORS_H
#define __SHOWSPECTATORS_H

#include "settings.h"
#include "SDK/SDK.h"
#include "interfaces.h"
#include "entity.h"

namespace ShowSpectators
{
	void PaintTraverse(VPANEL vgui_panel, bool force_repaint, bool allow_force);
}

#endif