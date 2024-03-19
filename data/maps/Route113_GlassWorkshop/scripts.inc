Route113_GlassWorkshop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route113_GlassWorkshop_OnTransition
	.byte 0

	.set BLUE_FLUTE_PRICE,   250
	.set YELLOW_FLUTE_PRICE, 500
	.set RED_FLUTE_PRICE,    500
	.set WHITE_FLUTE_PRICE,  1000
	.set BLACK_FLUTE_PRICE,  1000
	.set PRETTY_CHAIR_PRICE, 6000
	.set PRETTY_DESK_PRICE,  8000
	.set LOWEST_ASH_PRICE, BLUE_FLUTE_PRICE
	.set RAZZ_BERRY_PRICE, 250
	.set BLUK_BERRY_PRICE, 250
	.set NANAB_BERRY_PRICE, 250
	.set WEPEAR_BERRY_PRICE, 250
	.set PINAP_BERRY_PRICE, 250
	.set CORNN_BERRY_PRICE, 250
	.set MAGOST_BERRY_PRICE, 250
	.set RABUTA_BERRY_PRICE, 250
	.set NOMEL_BERRY_PRICE, 250
	.set SPELON_BERRY_PRICE, 250
	.set PAMTRE_BERRY_PRICE, 250
	.set WATMEL_BERRY_PRICE, 250
	.set DURIN_BERRY_PRICE, 250
	.set BELUE_BERRY_PRICE, 250

Route113_GlassWorkshop_OnTransition:
	setflag FLAG_LANDMARK_GLASS_WORKSHOP
	call_if_eq VAR_GLASS_WORKSHOP_STATE, 1, Route113_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack
	end

Route113_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack::
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	return

Route113_GlassWorkshop_EventScript_GlassWorker::
	lock
	faceplayer
	goto_if_ge VAR_GLASS_WORKSHOP_STATE, 10, Route113_GlassWorkshop_EventScript_GiveItemAfterNoRoom
	goto_if_eq VAR_GLASS_WORKSHOP_STATE, 2, Route113_GlassWorkshop_EventScript_CheckCollectedAsh
	goto_if_eq VAR_GLASS_WORKSHOP_STATE, 1, Route113_GlassWorkshop_EventScript_ExplainSootSack
	msgbox Route113_GlassWorkshop_Text_GoCollectAshWithThis, MSGBOX_DEFAULT
	giveitem ITEM_SOOT_SACK
	setvar VAR_GLASS_WORKSHOP_STATE, 1
	msgbox Route113_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_ExplainSootSack::
	msgbox Route113_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_CheckCollectedAsh::
	checkitem ITEM_SOOT_SACK
	goto_if_eq VAR_RESULT, FALSE, Route113_GlassWorkshop_EventScript_SootSackNotInBag
	msgbox Route113_GlassWorkshop_Text_LetsSeeCollectedAshes, MSGBOX_DEFAULT
	goto_if_lt VAR_ASH_GATHER_COUNT, LOWEST_ASH_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAsh
	message Route113_GlassWorkshop_Text_WhichGlassItemWoudYouLike
	waitmessage
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
	end

Route113_GlassWorkshop_EventScript_SootSackNotInBag::
	msgbox Route113_GlassWorkshop_Text_HaventGotYourSootSack, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_ChooseGlassItem::
	setvar VAR_0x8009, 0
	setvar VAR_0x8004, SCROLL_MULTI_GLASS_WORKSHOP_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, Route113_GlassWorkshop_EventScript_BlueFlute
	case 1, Route113_GlassWorkshop_EventScript_YellowFlute
	case 2, Route113_GlassWorkshop_EventScript_RedFlute
	case 3, Route113_GlassWorkshop_EventScript_WhiteFlute
	case 4, Route113_GlassWorkshop_EventScript_BlackFlute
	case 5, Route113_GlassWorkshop_EventScript_PrettyChair
	case 6, Route113_GlassWorkshop_EventScript_PrettyDesk
	case 7, Route113_GlassWorkshop_EventScript_RazzBerry
	case 8, Route113_GlassWorkshop_EventScript_BlukBerry
	case 9, Route113_GlassWorkshop_EventScript_NanabBerry
	case 10, Route113_GlassWorkshop_EventScript_WepearBerry
	case 11, Route113_GlassWorkshop_EventScript_PinapBerry
	case 12, Route113_GlassWorkshop_EventScript_CornnBerry
	case 13, Route113_GlassWorkshop_EventScript_MagostBerry
	case 14, Route113_GlassWorkshop_EventScript_RabutaBerry
	case 15, Route113_GlassWorkshop_EventScript_NomelBerry
	case 16, Route113_GlassWorkshop_EventScript_SpelonBerry
	case 17, Route113_GlassWorkshop_EventScript_PamtreBerry
	case 18, Route113_GlassWorkshop_EventScript_WatmelBerry
	case 19, Route113_GlassWorkshop_EventScript_DurinBerry
	case 20, Route113_GlassWorkshop_EventScript_BelueBerry
	case 21, Route113_GlassWorkshop_EventScript_CancelGlassItemSelect
	case MULTI_B_PRESSED, Route113_GlassWorkshop_EventScript_CancelGlassItemSelect
	end

Route113_GlassWorkshop_EventScript_BlueFlute::
	setvar VAR_0x8008, ITEM_BLUE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, BLUE_FLUTE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, BLUE_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 10
	subvar VAR_ASH_GATHER_COUNT, BLUE_FLUTE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_YellowFlute::
	setvar VAR_0x8008, ITEM_YELLOW_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, YELLOW_FLUTE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, YELLOW_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 11
	subvar VAR_ASH_GATHER_COUNT, YELLOW_FLUTE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_RedFlute::
	setvar VAR_0x8008, ITEM_RED_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, RED_FLUTE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, RED_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 12
	subvar VAR_ASH_GATHER_COUNT, RED_FLUTE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_WhiteFlute::
	setvar VAR_0x8008, ITEM_WHITE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, WHITE_FLUTE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, WHITE_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 13
	subvar VAR_ASH_GATHER_COUNT, WHITE_FLUTE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_BlackFlute::
	setvar VAR_0x8008, ITEM_BLACK_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, BLACK_FLUTE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, BLACK_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 14
	subvar VAR_ASH_GATHER_COUNT, BLACK_FLUTE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_PrettyChair::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_CHAIR
	bufferdecorationname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, PRETTY_CHAIR_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, PRETTY_CHAIR_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 15
	subvar VAR_ASH_GATHER_COUNT, PRETTY_CHAIR_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_PrettyDesk::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_DESK
	bufferdecorationname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, PRETTY_DESK_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, PRETTY_DESK_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 16
	subvar VAR_ASH_GATHER_COUNT, PRETTY_DESK_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_RazzBerry::
	setvar VAR_0x8008, ITEM_RAZZ_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, RAZZ_BERRY_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, RAZZ_BERRY_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 17
	subvar VAR_ASH_GATHER_COUNT, RAZZ_BERRY_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_BlukBerry::
	setvar VAR_0x8008, ITEM_BLUK_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, BLUK_BERRY_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, BLUK_BERRY_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 18
	subvar VAR_ASH_GATHER_COUNT, BLUK_BERRY_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_NanabBerry::
	setvar VAR_0x8008, ITEM_NANAB_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, NANAB_BERRY_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, NANAB_BERRY_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 19
	subvar VAR_ASH_GATHER_COUNT, NANAB_BERRY_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

	Route113_GlassWorkshop_EventScript_WepearBerry::
	setvar VAR_0x8008, ITEM_WEPEAR_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, WEPEAR_BERRY_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, WEPEAR_BERRY_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 20
	subvar VAR_ASH_GATHER_COUNT, WEPEAR_BERRY_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_PinapBerry::
	setvar VAR_0x8008, ITEM_PINAP_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, PINAP_BERRY_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, PINAP_BERRY_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 21
	subvar VAR_ASH_GATHER_COUNT, PINAP_BERRY_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

	Route113_GlassWorkshop_EventScript_CornnBerry::
	setvar VAR_0x8008, ITEM_CORNN_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, CORNN_BERRY_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, CORNN_BERRY_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 22
	subvar VAR_ASH_GATHER_COUNT, CORNN_BERRY_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

	Route113_GlassWorkshop_EventScript_MagostBerry::
	setvar VAR_0x8008, ITEM_MAGOST_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, MAGOST_BERRY_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, MAGOST_BERRY_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 23
	subvar VAR_ASH_GATHER_COUNT, MAGOST_BERRY_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

	Route113_GlassWorkshop_EventScript_RabutaBerry::
	setvar VAR_0x8008, ITEM_RABUTA_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, RABUTA_BERRY_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, RABUTA_BERRY_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 24
	subvar VAR_ASH_GATHER_COUNT, RABUTA_BERRY_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

	Route113_GlassWorkshop_EventScript_NomelBerry::
	setvar VAR_0x8008, ITEM_NOMEL_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, NOMEL_BERRY_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, NOMEL_BERRY_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 25
	subvar VAR_ASH_GATHER_COUNT, NOMEL_BERRY_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

	Route113_GlassWorkshop_EventScript_SpelonBerry::
	setvar VAR_0x8008, ITEM_SPELON_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, SPELON_BERRY_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, SPELON_BERRY_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 26
	subvar VAR_ASH_GATHER_COUNT, SPELON_BERRY_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

	Route113_GlassWorkshop_EventScript_PamtreBerry::
	setvar VAR_0x8008, ITEM_PAMTRE_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, SPELON_BERRY_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, PAMTRE_BERRY_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 27
	subvar VAR_ASH_GATHER_COUNT, PAMTRE_BERRY_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

	Route113_GlassWorkshop_EventScript_WatmelBerry::
	setvar VAR_0x8008, ITEM_WATMEL_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, WATMEL_BERRY_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, WATMEL_BERRY_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 28
	subvar VAR_ASH_GATHER_COUNT, WATMEL_BERRY_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

	Route113_GlassWorkshop_EventScript_DurinBerry::
	setvar VAR_0x8008, ITEM_DURIN_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, DURIN_BERRY_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, DURIN_BERRY_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 29
	subvar VAR_ASH_GATHER_COUNT, DURIN_BERRY_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

	Route113_GlassWorkshop_EventScript_BelueBerry::
	setvar VAR_0x8008, ITEM_BELUE_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, BELUE_BERRY_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, BELUE_BERRY_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 30
	subvar VAR_ASH_GATHER_COUNT, BELUE_BERRY_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_CancelGlassItemSelect::
	msgbox Route113_GlassWorkshop_Text_AllThatAshButDontWantAnything, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_NotEnoughAsh::
	setvar VAR_0x800A, LOWEST_ASH_PRICE
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
	buffernumberstring STR_VAR_1, VAR_0x800A
	msgbox Route113_GlassWorkshop_Text_NotEnoughAshNeedX, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_NotEnoughAshForItem::
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
	buffernumberstring STR_VAR_2, VAR_0x800A
	message Route113_GlassWorkshop_Text_NotEnoughAshToMakeItem
	waitmessage
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
	end

Route113_GlassWorkshop_EventScript_ChooseDifferentItem::
	message Route113_GlassWorkshop_Text_WhichWouldYouLike
	waitmessage
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
	end

Route113_GlassWorkshop_EventScript_MakeGlassItem::
	msgbox Route113_GlassWorkshop_Text_IllMakeItemForYou, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_SELECT
	delay 30
	fadescreen FADE_FROM_BLACK
	msgbox Route113_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
	call_if_eq VAR_0x8009, 0, Route113_GlassWorkshop_EventScript_GiveGlassFlute
	call_if_eq VAR_0x8009, 1, Route113_GlassWorkshop_EventScript_GiveGlassDecor
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	release
	end

Route113_GlassWorkshop_EventScript_GiveGlassFlute::
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, Route113_GlassWorkshop_EventScript_NoRoomForFlute
	return

Route113_GlassWorkshop_EventScript_GiveGlassDecor::
	givedecoration VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, Route113_GlassWorkshop_EventScript_NoRoomForDecor
	return

Route113_GlassWorkshop_EventScript_NoRoomForFlute::
	call Common_EventScript_BagIsFull
	msgbox Route113_GlassWorkshop_Text_NoRoomInBag, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_NoRoomForDecor::
	call Common_EventScript_NoRoomForDecor
	msgbox Route113_GlassWorkshop_Text_NoRoomInPC, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_GiveItemAfterNoRoom::
	switch VAR_GLASS_WORKSHOP_STATE
	case 10, Route113_GlassWorkshop_EventScript_GiveBlueFlute
	case 11, Route113_GlassWorkshop_EventScript_GiveYellowFlute
	case 12, Route113_GlassWorkshop_EventScript_GiveRedFlute
	case 13, Route113_GlassWorkshop_EventScript_GiveWhiteFlute
	case 14, Route113_GlassWorkshop_EventScript_GiveBlackFlute
	case 15, Route113_GlassWorkshop_EventScript_GivePrettyChair
	case 16, Route113_GlassWorkshop_EventScript_GivePrettyDesk
	case 17, Route113_GlassWorkshop_EventScript_GiveRazzBerry
	case 18, Route113_GlassWorkshop_EventScript_GiveBlukBerry
	case 19, Route113_GlassWorkshop_EventScript_GiveNanabBerry
	case 20, Route113_GlassWorkshop_EventScript_GiveWepearBerry
	case 21, Route113_GlassWorkshop_EventScript_GivePinapBerry
	case 22, Route113_GlassWorkshop_EventScript_GiveCornnBerry
	case 23, Route113_GlassWorkshop_EventScript_GiveMagostBerry
	case 24, Route113_GlassWorkshop_EventScript_GiveRabutaBerry
	case 25, Route113_GlassWorkshop_EventScript_GiveNomelBerry
	case 26, Route113_GlassWorkshop_EventScript_GiveSpelonBerry
	case 27, Route113_GlassWorkshop_EventScript_GivePamtreBerry
	case 28, Route113_GlassWorkshop_EventScript_GiveWatmelBerry
	case 29, Route113_GlassWorkshop_EventScript_GiveDurinBerry
	case 30, Route113_GlassWorkshop_EventScript_GiveBelueBerry
	end

Route113_GlassWorkshop_EventScript_GiveBlueFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_BLUE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveYellowFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_YELLOW_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveRedFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_RED_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveWhiteFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_WHITE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveBlackFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_BLACK_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GivePrettyChair::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_CHAIR
	bufferdecorationname STR_VAR_1, DECOR_PRETTY_CHAIR
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GivePrettyDesk::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_DESK
	bufferdecorationname STR_VAR_1, DECOR_PRETTY_DESK
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

	Route113_GlassWorkshop_EventScript_GiveRazzBerry::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_RAZZ_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

	Route113_GlassWorkshop_EventScript_GiveBlukBerry::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_BLUK_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

	Route113_GlassWorkshop_EventScript_GiveNanabBerry::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_NANAB_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

	Route113_GlassWorkshop_EventScript_GiveWepearBerry::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_WEPEAR_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

	Route113_GlassWorkshop_EventScript_GivePinapBerry::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_PINAP_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

	Route113_GlassWorkshop_EventScript_GiveCornnBerry::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_CORNN_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

	Route113_GlassWorkshop_EventScript_GiveMagostBerry::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_MAGOST_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

	Route113_GlassWorkshop_EventScript_GiveRabutaBerry::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_RABUTA_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

	Route113_GlassWorkshop_EventScript_GiveNomelBerry::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_NOMEL_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

	Route113_GlassWorkshop_EventScript_GiveSpelonBerry::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_SPELON_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

	Route113_GlassWorkshop_EventScript_GivePamtreBerry::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_PAMTRE_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

	Route113_GlassWorkshop_EventScript_GiveWatmelBerry::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_WATMEL_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

	Route113_GlassWorkshop_EventScript_GiveDurinBerry::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_DURIN_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

	Route113_GlassWorkshop_EventScript_GiveBelueBerry::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_BELUE_BERRY
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_TryGiveItemAgain::
	msgbox Route113_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
	call_if_eq VAR_0x8009, 0, Route113_GlassWorkshop_EventScript_GiveGlassFlute
	call_if_eq VAR_0x8009, 1, Route113_GlassWorkshop_EventScript_GiveGlassDecor
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	release
	end

Route113_GlassWorkshop_EventScript_NinjaBoy::
	msgbox Route113_GlassWorkshop_Text_FunToBlowGlassFlute, MSGBOX_NPC
	end

Route113_GlassWorkshop_Text_GoCollectAshWithThis:
	.string "This area is covered in volcanic ash,\n"
	.string "I'm specially gifted, huff-puff.\p"
	.string "The soil here is excellent for growing!\p"
	.string "Also I make glass out of volcanic ash\n"
	.string "and make items, huff-puff.\p"
	.string "Go collect ashes with this, huff-puff.$"

Route113_GlassWorkshop_Text_ExplainSootSack:
	.string "Just take that SOOT SACK and walk\n"
	.string "through piles of ash, huff-puff.\p"
	.string "And it will fill up with the volcanic ash,\n"
	.string "huff-puff.\p"
	.string "Once you think you've collected a good\n"
	.string "amount, come see me, huff-puff.$"

Route113_GlassWorkshop_Text_LetsSeeCollectedAshes:
	.string "Have you collected ashes, huff-puff?\n"
	.string "Let me see, huff-puff.$"

Route113_GlassWorkshop_Text_NotEnoughAshNeedX:
	.string "Hmmm…\n"
	.string "There's not enough ash here, huff-puff.\l"
	.string "I can't make glass with this, huff-puff.\p"
	.string "Let's see… {STR_VAR_1} is the number of steps\n"
	.string "you'll need to walk for me to make you\l"
	.string "a BLUE FLUTE, huff-puff.$"

Route113_GlassWorkshop_Text_WhichGlassItemWoudYouLike:
	.string "Oh!\n"
	.string "You've got a lot of ashes, huff-puff!\p"
	.string "I'll trade you an item, huff-puff!\n"
	.string "Which one would you like, huff-puff?$"

Route113_GlassWorkshop_Text_IsThatTheItemForYou:
	.string "A {STR_VAR_1}, huff-puff?\n"
	.string "Is that the one for you, huff-puff?$"

Route113_GlassWorkshop_Text_WhichWouldYouLike:
	.string "Which one would you like, huff-puff?$"

Route113_GlassWorkshop_Text_IllMakeItemForYou:
	.string "A {STR_VAR_1} it is, then, huff-puff!\p"
	.string "Okay! I'll trade it with you, huff-puff.\n"
	.string "Just wait a little while, huff-puff.$"

Route113_GlassWorkshop_Text_NotEnoughAshToMakeItem:
	.string "A {STR_VAR_1}, huff-puff?\p"
	.string "There's not enough ash to trade\n"
	.string "that, though, huff-puff.\p"
	.string "Let's see… {STR_VAR_2} is the number of steps\n"
	.string "you'll need to walk through volcanic ash\l"
	.string "for me to trade that item, huff-puff.\p"
	.string "Which item would you rather have\n"
	.string "instead, huff-puff?$"

Route113_GlassWorkshop_Text_AllThatAshButDontWantAnything:
	.string "You've collected all that ash, but you\n"
	.string "don't want anything, huff-puff?$"

Route113_GlassWorkshop_Text_IveFinishedGlassItem:
	.string "Ah, I've finished your {STR_VAR_1}.\n"
	.string "Take it, huff-puff.$"

Route113_GlassWorkshop_Text_NoRoomInBag:
	.string "Oh?\n"
	.string "You've no room in your BAG, huff-puff.\p"
	.string "I'll hold on to it, so come back later,\n"
	.string "huff-puff.$"

Route113_GlassWorkshop_Text_NoRoomInPC:
	.string "Oh?\n"
	.string "You've no room in your PC, huff-puff?\p"
	.string "I'll hold on to it, so come back later,\n"
	.string "huff-puff.$"

Route113_GlassWorkshop_Text_HaventGotYourSootSack:
	.string "Hah? You haven't got your SOOT SACK\n"
	.string "with you, huff-puff.\p"
	.string "You have to keep it with you to collect\n"
	.string "volcanic ash, huff-puff.$"

Route113_GlassWorkshop_Text_FunToBlowGlassFlute:
	.string "My Boss has a lot of berries in\n"
	.string "his garden! He is exchanging\p"
	.string "volcanic ash for berries!$"
