.set LOCALID_ARTICUNO, 1

SeafoamCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SeafoamCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamCave_OnTransition
	.byte 0

SeafoamCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SeafoamCave_EventScript_TryRemoveArticuno
	end

SeafoamCave_EventScript_TryRemoveArticuno::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_ARTICUNO
	return

SeafoamCave_OnTransition:
	call_if_unset FLAG_DEFEATED_ARTICUNO, SeafoamCave_EventScript_ShowArticuno
	end

SeafoamCave_EventScript_ShowArticuno::
	clearflag FLAG_HIDE_ARTICUNO
	setvar VAR_TEMP_1, 1
	return

SeafoamCave_EventScript_Articuno::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	waitse
	playmoncry SPECIES_ARTICUNO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_ARTICUNO
	setwildbattle SPECIES_ARTICUNO, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, SeafoamCave_EventScript_DefeatedArticuno
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, SeafoamCave_EventScript_RanFromArticuno
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, SeafoamCave_EventScript_RanFromArticuno
	setflag FLAG_DEFEATED_ARTICUNO
	releaseall
	end

SeafoamCave_EventScript_DefeatedArticuno::
	setflag FLAG_DEFEATED_ARTICUNO
	goto Common_EventScript_RemoveStaticPokemon
	end

SeafoamCave_EventScript_RanFromArticuno::
	setvar VAR_0x8004, SPECIES_ARTICUNO
	goto Common_EventScript_LegendaryFlewAway
	end
