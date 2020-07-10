# samp-death-items
```pawn
hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (newkeys & KEY_YES)
	{
		GivePlayerWeapon(playerid, 24, 30);
	}


	if (newkeys & KEY_CROUCH)
	{
		SetPlayerHealth(playerid, 0.0);
	}


	if (newkeys & KEY_NO)
	{
		GivePlayerMoney(playerid, 100);
	}

	return 1;
}
```
