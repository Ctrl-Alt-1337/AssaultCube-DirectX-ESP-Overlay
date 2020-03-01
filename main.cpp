#include <thread>
#include <string>
#include <windows.h>
#include "dx_overlay.h"
#include "dx_renderer.h"
#include <iostream>
#include "WinFunctions.h"
#include "Player.h"
#include "Entities.h"
#include "Mathematics.h"
#include <sstream>

#pragma warning(disable : 4244) // disable loss of data conversion


int main() {

	// C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\Tools\spy to find target_class name
	forceinline::dx_overlay overlay(L"SDL_app", L"AssaultCube", true /*Read comments regarding this*/);

	if (!overlay.is_initialized())
		return -1;

	MSG m;
	ZeroMemory(&m, sizeof(m));

	forceinline::dx_renderer renderer = overlay.create_renderer();

	WinFunc win;
	win.GetInfo("AssaultCube");
	win.Print();

	Player player(win);

	Entities entities(win);

	Mathematics math(win);

	player.GetInfo();
	player.Print();

	while (m.message != WM_QUIT) {
		if (PeekMessage(&m, overlay.get_overlay_wnd(), NULL, NULL, PM_REMOVE)) {
			TranslateMessage(&m);
			DispatchMessage(&m);
		}

		renderer.begin_rendering();

		player.GetInfo();
		entities.GetInfo();

		for (int i = 0; i < entities.amount; i++)
		{
			if (math.WorldToScreen(entities.list[i].position_feet, math.screen, player.matrix, 800, 600) && entities.list[i].health > 0)
			{
				if (entities.list[i].team != player.team)
				{
					float distance = math.GetDistance3D(player.position_feet, entities.list[i].position_feet);
					renderer.draw_text(std::to_wstring((int)distance), math.screen.x, math.screen.y + 15, 0xFFFFFFFF, false);
				}
			}
		}
		
		renderer.end_rendering();

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}
