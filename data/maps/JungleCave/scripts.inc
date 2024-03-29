.set LOCALID_RAIKOU, 2

JungleCave_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JungleCave_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JungleCave_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JungleCaveSetNpcX
	.byte 0

JungleCave_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, JungleCave_EventScript_TryRemoveRaikou
	end

JungleCave_EventScript_TryRemoveRaikou::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_RAIKOU
	return

JungleCave_OnTransition:
	call_if_unset FLAG_DEFEATED_RAIKOU, JungleCave_EventScript_ShowRaikou
	call_if_set FLAG_SYS_GAME_CLEAR, JungleCaveSetNpcX
	end

JungleCaveSetNpcX::
	goto_if_set FLAG_SYS_GAME_CLEAR, JungleCaveSetNpcX_1
	return

JungleCaveSetNpcX_1:
	setobjectxyperm 1, 10, 11
	return

JungleCave_EventScript_ShowRaikou::
	clearflag FLAG_HIDE_RAIKOU
	setvar VAR_TEMP_1, 1
	return

JungleCave_EventScript_Raikou::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	waitse
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_RAIKOU
	setwildbattle SPECIES_RAIKOU, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, JungleCave_EventScript_DefeatedRaikou
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, JungleCave_EventScript_RanFromRaikou
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, JungleCave_EventScript_RanFromRaikou
	releaseall
	end

JungleCave_EventScript_DefeatedRaikou::
	setflag FLAG_DEFEATED_RAIKOU
	goto Common_EventScript_RemoveStaticPokemon
	end

JungleCave_EventScript_RanFromRaikou::
	setvar VAR_0x8004, SPECIES_RAIKOU
	goto Common_EventScript_LegendaryFlewAway
	end

JungleCave_EventScript_Ranger::
	lockall
	faceplayer
	msgbox JungleCave_EventScript_Ranger_Text_0
	msgbox JungleCave_EventScript_Ranger_Text_1
	msgbox JungleCave_EventScript_Ranger_Text_2
	msgbox JungleCave_EventScript_Ranger_Text_3
	releaseall
	return


JungleCave_EventScript_Ranger_Text_0:
	.string "RANGER: A mighty creature lives here!$"

JungleCave_EventScript_Ranger_Text_1:
	.string "RANGER: I'll let you fight this Pokemon.$"

JungleCave_EventScript_Ranger_Text_2:
	.string "RANGER: But only if you\nare strong enough.$"

JungleCave_EventScript_Ranger_Text_3:
	.string "RANGER: Good Luck {PLAYER}.$"
