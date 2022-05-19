#include "../Hooks.h"

#include "../../Features/Camera/CameraWindow.h"

MAKE_HOOK(ViewRender_RenderView, Utils::GetVFuncPtr(g_Interfaces.ViewRender, 6), void, __fastcall,
		  void* ecx, void* edx, const CViewSetup& view, ClearFlags_t nClearFlags, RenderViewInfo_t whatToDraw)
{
	if (!g_CameraWindow.originalFn)
	{
		g_CameraWindow.originalFn = Hook.Original<FN>();
	}
	Hook.Original<FN>()(ecx, edx, view, nClearFlags, whatToDraw);
	g_CameraWindow.RenderView(ecx, edx, view);
}