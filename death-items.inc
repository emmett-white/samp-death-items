/*
  * Include: Death Items
  * Author: Emmett
  * Date: 10th July
  * Copyright (C) 2020
  */

#if defined _inc_death_items
	#undef _inc_death_items
#endif


#include <a_samp>
#tryinclude <YSI_Coding\y_hooks>


/// <summary>
/// Max items
/// </summary>
#if defined MAX_ITEMS
	#undef MAX_ITEMS
#else
	#define MAX_ITEMS (500)
#endif

#if defined INVALID_MONEY_VALUE
 	#undef INVALID_MONEY_VALUE
#else
  	#define INVALID_MONEY_VALUE	(-1)
#endif


/// <summary>
/// Enumerator
/// </summary>
enum e_DEATH_ITEMS_INFO
{
	Float: e_ItemX,
	Float: e_ItemY,
	Float: e_ItemZ,

	e_ItemMoney,
	e_ItemWeapon,

	e_ItemWeaponAmmo,

	e_ItemMoneyPickup,
	e_ItemWeaponPickup,
};


/// <summary>
/// Variables
/// </summary>
static
	gItemsData[MAX_ITEMS][e_DEATH_ITEMS_INFO],
	gItemsPickup[MAX_ITEMS][2];


/// <summary>
/// Hooks
/// </summary>
hook OnPlayerPickUpPickup(playerid, pickupid)
{
	for (new i = 0; i < sizeof gItemsData; ++i)
	{
		if (pickupid == gItemsPickup[i][0])
			GivePlayerWeapon(playerid, gItemsData[i][e_ItemWeapon], gItemsData[i][e_ItemWeaponAmmo]);

		else if (pickupid == gItemsPickup[i][1])
			GivePlayerMoney(playerid, gItemsData[i][e_ItemMoney]);


		DestroyPickup((pickupid == gItemsPickup[i][0]) ? (gItemsPickup[i][0]) : (gItemsPickup[i][1]));

		break;
	}

	return 1;
}


/// <summary>
/// Functions
/// </summary>
stock DItem_Create(const playerid, Float: __itemX, Float: __itemY, Float: __itemZ)
{
	for (new i = 0; i < sizeof gItemsData; ++i)
	{
		/// <summary>
		/// Assigning variables
		/// </summary>
		gItemsData[i][e_ItemX] = __itemX,
		gItemsData[i][e_ItemY] = __itemY,
		gItemsData[i][e_ItemZ] = __itemZ;

		gItemsData[i][e_ItemWeapon] = GetPlayerWeapon(playerid);
		gItemsData[i][e_ItemMoney] = (GetPlayerMoney(playerid) != 0 ? (GetPlayerMoney(playerid) / 10) : (0));

		gItemsData[i][e_ItemWeaponAmmo] = GetPlayerAmmo(playerid);

		gItemsData[i][e_ItemWeaponPickup] = ReturnWeaponPickupID(playerid);
		gItemsData[i][e_ItemMoneyPickup] = 1212;


		if (GetPlayerMoney(playerid) == 0)
		{
			gItemsPickup[i][0] = CreatePickup(gItemsData[i][e_ItemWeaponPickup], 1, gItemsData[i][e_ItemX], gItemsData[i][e_ItemY], gItemsData[i][e_ItemZ]);
			return 1;
		}


		gItemsPickup[i][0] = CreatePickup(gItemsData[i][e_ItemWeaponPickup], 1, gItemsData[i][e_ItemX], gItemsData[i][e_ItemY], gItemsData[i][e_ItemZ]);
		gItemsPickup[i][1] = CreatePickup(gItemsData[i][e_ItemMoneyPickup], 1, gItemsData[i][e_ItemX], (gItemsData[i][e_ItemY] + 4.0), gItemsData[i][e_ItemZ]);

		break;
	}

	return 1;
}


stock ReturnWeaponPickupID(const playerid)
{
	static
		__pickupid;


	switch (GetPlayerWeapon(playerid))
	{
		case 1: __pickupid = 331;
		case 2: __pickupid = 333;
		case 3: __pickupid = 334;
		case 4: __pickupid = 335;
		case 5: __pickupid = 336;
		case 6: __pickupid = 337;
		case 8: __pickupid = 339;
		case 9: __pickupid = 341;
		case 10: __pickupid = 321;
		case 12: __pickupid = 323;
		case 14: __pickupid = 325;
		case 16: __pickupid = 342;
		case 17: __pickupid = 343;
		case 18: __pickupid = 344;
		case 22: __pickupid = 346;
		case 23: __pickupid = 347;
		case 24: __pickupid = 348;
		case 25: __pickupid = 349;
		case 26: __pickupid = 350;
		case 27: __pickupid = 351;
		case 28: __pickupid = 352;
		case 29: __pickupid = 353;
		case 30: __pickupid = 355;
		case 31: __pickupid = 356;
		case 32: __pickupid = 372;
		case 33: __pickupid = 357;
		case 34: __pickupid = 358;
		case 35: __pickupid = 359;
		case 36: __pickupid = 360;
		case 38: __pickupid = 362;
		case 42: __pickupid = 366;
	}

	return __pickupid;
}
