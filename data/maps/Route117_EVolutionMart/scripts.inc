Route117_EVolutionMart_MapScripts::
	.byte 0


Route117_EVolutionMart_Employee::
# 6 "data/maps/Route117_EVolutionMart/scripts.pory"
	lock
# 7 "data/maps/Route117_EVolutionMart/scripts.pory"
	faceplayer
# 8 "data/maps/Route117_EVolutionMart/scripts.pory"
	message Route117_EVolutionMart_Employee_Text_0
# 9 "data/maps/Route117_EVolutionMart/scripts.pory"
	waitmessage
# 10 "data/maps/Route117_EVolutionMart/scripts.pory"
	pokemart EVolutionMart
# 11 "data/maps/Route117_EVolutionMart/scripts.pory"
	msgbox Route117_EVolutionMart_Employee_Text_1
# 12 "data/maps/Route117_EVolutionMart/scripts.pory"
	release
	end


# 16 "data/maps/Route117_EVolutionMart/scripts.pory"

# 17 "data/maps/Route117_EVolutionMart/scripts.pory"
 
# 18 "data/maps/Route117_EVolutionMart/scripts.pory"
.align 2
# 19 "data/maps/Route117_EVolutionMart/scripts.pory"
EVolutionMart::
# 20 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_HP_UP
# 21 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_PROTEIN
# 22 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_IRON
# 23 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_CARBOS
# 24 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_CALCIUM
# 25 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_ZINC
# 26 "data/maps/Route117_EVolutionMart/scripts.pory"
    .2byte ITEM_POMEG_BERRY
# 27 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_KELPSY_BERRY
# 28 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_QUALOT_BERRY
# 29 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_HONDEW_BERRY
# 30 "data/maps/Route117_EVolutionMart/scripts.pory"
    .2byte ITEM_GREPA_BERRY
# 31 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_TAMATO_BERRY
# 32 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_EVERSTONE
# 33 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_SUN_STONE
# 34 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_MOON_STONE
# 35 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_FIRE_STONE
# 36 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_THUNDER_STONE
# 37 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_WATER_STONE
# 38 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_LEAF_STONE
# 39 "data/maps/Route117_EVolutionMart/scripts.pory"
	.2byte ITEM_NONE
# 40 "data/maps/Route117_EVolutionMart/scripts.pory"
	release
# 41 "data/maps/Route117_EVolutionMart/scripts.pory"
	end

Route117_EVolutionMart_Employee_Text_0:
# 8 "data/maps/Route117_EVolutionMart/scripts.pory"
	.string "Welcome to EVolution Mart.\nHow may I serve you?$"

Route117_EVolutionMart_Employee_Text_1:
# 11 "data/maps/Route117_EVolutionMart/scripts.pory"
	.string "Please come again.$"
