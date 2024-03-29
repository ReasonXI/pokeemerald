.set LOCALID_MEWTWO, 1

ForgottenCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ForgottenCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, ForgottenCave_OnTransition
	.byte 0

ForgottenCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ForgottenCave_EventScript_TryRemoveMewtwo
	end

ForgottenCave_EventScript_TryRemoveMewtwo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_MEWTWO
	return

ForgottenCave_OnTransition:
	call_if_unset FLAG_DEFEATED_MEWTWO, ForgottenCave_EventScript_ShowMewtwo
	end

ForgottenCave_EventScript_ShowMewtwo::
	clearflag FLAG_HIDE_MEWTWO
	setvar VAR_TEMP_1, 1
	return

ForgottenCave_EventScript_Mewtwo::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	waitse
	playmoncry SPECIES_MEWTWO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_MEWTWO
	setwildbattle SPECIES_MEWTWO, 85
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ForgottenCave_EventScript_DefeatedMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ForgottenCave_EventScript_RanFromMewtwo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ForgottenCave_EventScript_RanFromMewtwo
	setflag FLAG_DEFEATED_MEWTWO
	releaseall
	end

ForgottenCave_EventScript_DefeatedMewtwo::
	setflag FLAG_DEFEATED_MEWTWO
	goto Common_EventScript_RemoveStaticPokemon
	end

ForgottenCave_EventScript_RanFromMewtwo::
	setvar VAR_0x8004, SPECIES_MEWTWO
	goto Common_EventScript_LegendaryFlewAway
	end
