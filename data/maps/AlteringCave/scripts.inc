.set LOCALID_JIRACHI, 4

AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AlteringCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AlteringCave_OnTransition
    map_script MAP_SCRIPT_ON_LOAD, AlteringCaveSetNpcX
	.byte 0

    AlteringCave_OnTransition:
	setflag FLAG_LANDMARK_ALTERING_CAVE
    call_if_set FLAG_DEFEATED_CELEBI, AlteringCaveSetNpcX
	call_if_unset FLAG_DEFEATED_JIRACHI, AlteringCave_EventScript_ShowJirachi
	end

AlteringCaveSetNpcX::
	goto_if_set FLAG_DEFEATED_CELEBI, AlteringCaveSetNpcX_1
	return

AlteringCaveSetNpcX_1:
	setobjectxyperm 5, 28, 13
	return

AlteringCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AlteringCave_EventScript_TryRemoveJirachi
	end

AlteringCave_EventScript_TryRemoveJirachi::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_JIRACHI
	return

AlteringCave_EventScript_ShowJirachi::
	clearflag FLAG_HIDE_JIRACHI
	setvar VAR_TEMP_1, 1
	return

AlteringCave_EventScript_Jirachi::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_JIRACHI
	setwildbattle SPECIES_JIRACHI, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AlteringCave_EventScript_DefeatedJirachi
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AlteringCave_EventScript_RanFromJirachi
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AlteringCave_EventScript_RanFromJirachi
	setflag FLAG_DEFEATED_JIRACHI
	releaseall
	end

AlteringCave_EventScript_DefeatedJirachi::
	setflag FLAG_DEFEATED_JIRACHI
	goto Common_EventScript_RemoveStaticPokemon
	end

AlteringCave_EventScript_RanFromJirachi::
	setvar VAR_0x8004, SPECIES_JIRACHI
	goto Common_EventScript_LegendaryFlewAway
	end

AlteringCave_EventScript_OldMan::
	lockall
	faceplayer
	msgbox AlteringCave_EventScript_OldMan_Text_0
	msgbox AlteringCave_EventScript_OldMan_Text_1
	msgbox AlteringCave_EventScript_OldMan_Text_2
	msgbox AlteringCave_EventScript_OldMan_Text_3
	msgbox AlteringCave_EventScript_OldMan_Text_4
	releaseall
	return


AlteringCave_EventScript_OldMan_Text_0:
	.string "OLD MAN: If you have proven yourself\nstrong enough...$"

AlteringCave_EventScript_OldMan_Text_1:
	.string "OLD MAN: I'll let you fight this Pokemon.$"

AlteringCave_EventScript_OldMan_Text_2:
	.string "OLD MAN: Go and find the legendary Celebi.$"

AlteringCave_EventScript_OldMan_Text_3:
	.string "OLD MAN: If you manage to defeat it,\n you may pass.$"

AlteringCave_EventScript_OldMan_Text_4:
	.string "OLD MAN: Good Luck {PLAYER}.$"
