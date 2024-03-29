.set LOCALID_CELEBI, 1

ShrineoftheBerrygod_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ShrineoftheBerrygod_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, ShrineoftheBerrygod_OnTransition
	.byte 0

ShrineoftheBerrygod_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ShrineoftheBerrygod_EventScript_TryRemoveCelebi
	end

ShrineoftheBerrygod_EventScript_TryRemoveCelebi::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_CELEBI
	return

ShrineoftheBerrygod_OnTransition:
	call_if_unset FLAG_DEFEATED_CELEBI, ShrineoftheBerrygod_EventScript_ShowCelebi
	end

ShrineoftheBerrygod_EventScript_ShowCelebi::
	clearflag FLAG_HIDE_CELEBI
	setvar VAR_TEMP_1, 1
	return

ShrineoftheBerrygod_EventScript_Celebi::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	waitse
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_CELEBI
	setwildbattle SPECIES_CELEBI, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ShrineoftheBerrygod_EventScript_DefeatedCelebi
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ShrineoftheBerrygod_EventScript_RanFromCelebi
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ShrineoftheBerrygod_EventScript_RanFromCelebi
	setflag FLAG_DEFEATED_CELEBI
	releaseall
	end

ShrineoftheBerrygod_EventScript_DefeatedCelebi::
	setflag FLAG_DEFEATED_CELEBI
	goto Common_EventScript_RemoveStaticPokemon
	end

ShrineoftheBerrygod_EventScript_RanFromCelebi::
	setvar VAR_0x8004, SPECIES_CELEBI
	goto Common_EventScript_LegendaryFlewAway
	end
