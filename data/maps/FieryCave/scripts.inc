.set LOCALID_MOLTRES, 1

FieryCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, FieryCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, FieryCave_OnTransition
	.byte 0

FieryCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, FieryCave_EventScript_TryRemoveMoltres
	end

FieryCave_EventScript_TryRemoveMoltres::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_MOLTRES
	return

FieryCave_OnTransition:
	call_if_unset FLAG_DEFEATED_MOLTRES, FieryCave_EventScript_ShowMoltres
	end

FieryCave_EventScript_ShowMoltres::
	clearflag FLAG_HIDE_MOLTRES
	setvar VAR_TEMP_1, 1
	return

FieryCave_EventScript_Moltres::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	waitse
	playmoncry SPECIES_MOLTRES, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_MOLTRES
	setwildbattle SPECIES_MOLTRES, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FieryCave_EventScript_DefeatedMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FieryCave_EventScript_RanFromMoltres
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FieryCave_EventScript_RanFromMoltres
	setflag FLAG_DEFEATED_MOLTRES
	releaseall
	end

FieryCave_EventScript_DefeatedMoltres::
	setflag FLAG_DEFEATED_MOLTRES
	goto Common_EventScript_RemoveStaticPokemon
	end

FieryCave_EventScript_RanFromMoltres::
	setvar VAR_0x8004, SPECIES_MOLTRES
	goto Common_EventScript_LegendaryFlewAway
	end
