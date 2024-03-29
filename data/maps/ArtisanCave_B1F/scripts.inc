.set LOCALID_ENTEI, 2

ArtisanCave_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ArtisanCave_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, ArtisanCave_B1F_OnTransition

	.byte 0

ArtisanCave_B1F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ArtisanCave_B1F_EventScript_TryRemoveEntei

ArtisanCave_B1F_EventScript_TryRemoveEntei::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_ENTEI
	return

ArtisanCave_B1F_OnTransition:
	call_if_unset FLAG_DEFEATED_ENTEI, ArtisanCave_B1F_EventScript_ShowEntei
	setflag FLAG_LANDMARK_ARTISAN_CAVE
	end

ArtisanCave_B1F_EventScript_ShowEntei::
	clearflag FLAG_HIDE_ENTEI
	setvar VAR_TEMP_1, 1
	return

ArtisanCave_B1F_EventScript_Entei::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	waitse
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_ENTEI
	setwildbattle SPECIES_ENTEI, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ArtisanCave_B1F_EventScript_DefeatedEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ArtisanCave_B1F_EventScript_RanFromEntei
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ArtisanCave_B1F_EventScript_RanFromEntei
	setflag FLAG_DEFEATED_ENTEI
	releaseall
	end

ArtisanCave_B1F_EventScript_DefeatedEntei::
	setflag FLAG_DEFEATED_ENTEI
	goto Common_EventScript_RemoveStaticPokemon
	end

ArtisanCave_B1F_EventScript_RanFromEntei::
	setvar VAR_0x8004, SPECIES_ENTEI
	goto Common_EventScript_LegendaryFlewAway
	end
