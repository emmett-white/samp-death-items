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
/// Weapon model IDs
/// </summary>
static const WeaponModelIDs[] =
{
    331, 333, 334, 335,
    336, 337, 339, 341,
    321, 323, 325, 342,
    343, 344, 346, 347,
    348, 349, 350, 351,
    352, 353, 355, 356,
    372, 357, 358, 359,
    360, 362, 366
};


/// <summary>
/// Hooks
/// </summary>
public OnPlayerPickUpPickup(playerid, pickupid)
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
	return WeaponModelIDs[GetPlayerWeapon(playerid) - 8];
}
