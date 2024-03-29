.set LOCALID_SUICUNE, 1

AuroraCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AuroraCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AuroraCave_OnTransition
	.byte 0

AuroraCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AuroraCave_EventScript_TryRemoveSuicune
	end

AuroraCave_EventScript_TryRemoveSuicune::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_SUICUNE
	return

AuroraCave_OnTransition:
	call_if_unset FLAG_DEFEATED_SUICUNE, AuroraCave_EventScript_ShowSuicune
	end

AuroraCave_EventScript_ShowSuicune::
	clearflag FLAG_HIDE_SUICUNE
	setvar VAR_TEMP_1, 1
	return

AuroraCave_EventScript_Suicune::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	waitse
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_SUICUNE
	setwildbattle SPECIES_SUICUNE, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AuroraCave_EventScript_DefeatedSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AuroraCave_EventScript_RanFromSuicune
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AuroraCave_EventScript_RanFromSuicune
	setflag FLAG_DEFEATED_SUICUNE
	releaseall
	end

AuroraCave_EventScript_DefeatedSuicune::
	setflag FLAG_DEFEATED_SUICUNE
	goto Common_EventScript_RemoveStaticPokemon
	end

AuroraCave_EventScript_RanFromSuicune::
	setvar VAR_0x8004, SPECIES_SUICUNE
	goto Common_EventScript_LegendaryFlewAway
	end
