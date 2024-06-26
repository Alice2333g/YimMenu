#include "views/view.hpp"
#include "services/players/player_service.hpp"

namespace big
{
	void view::player_misc()
	{ 
		ImGui::SeparatorText("DEBUG_TAB_MISC"_T.data());

		ImGui::BeginGroup();
		components::player_command_button<"joinceo">(g_player_service->get_selected());
		components::player_command_button<"enterint">(g_player_service->get_selected());
		components::player_command_button<"copyoutfit">(g_player_service->get_selected());
		components::player_command_button<"copymodel">(g_player_service->get_selected());
		components::player_command_button<"clearwanted">(g_player_service->get_selected());
		ImGui::EndGroup();

		ImGui::SameLine();

		ImGui::BeginGroup();
		components::player_command_button<"givehealth">(g_player_service->get_selected());
		components::player_command_button<"givearmor">(g_player_service->get_selected());
		components::player_command_button<"giveammo">(g_player_service->get_selected());
		components::player_command_button<"giveweaps">(g_player_service->get_selected(), {});
		ImGui::EndGroup();

		ImGui::SameLine();

		ImGui::BeginGroup();
		ImGui::Checkbox("OFF_THE_RADAR"_T.data(), &g_player_service->get_selected()->off_radar);
		ImGui::Checkbox("NEVER_WANTED"_T.data(), &g_player_service->get_selected()->never_wanted);
		ImGui::Checkbox("SEMI_GODMODE"_T.data(), &g_player_service->get_selected()->semi_godmode);
		ImGui::Checkbox("VIEW_NET_SESSION_FIX_VEHICLE"_T.data(), &g_player_service->get_selected()->fix_vehicle);
		ImGui::EndGroup();
	}
}