# samp-death-items

[![sampctl](https://img.shields.io/badge/sampctl-samp--death--items-2f2f2f.svg?style=for-the-badge)](https://github.com/emmett-white/samp-death-items)

<!--
Short description of your library, why it's useful, some examples, pictures or
videos. Link to your forum release thread too.

Remember: You can use "forumfmt" to convert this readme to forum BBCode!

What the sections below should be used for:

`## Installation`: Leave this section un-edited unless you have some specific
additional installation procedure.

`## Testing`: Whether your library is tested with a simple `main()` and `print`,
unit-tested, or demonstrated via prompting the player to connect, you should
include some basic information for users to try out your code in some way.

And finally, maintaining your version number`:

* Follow [Semantic Versioning](https://semver.org/)
* When you release a new version, update `VERSION` and `git tag` it
* Versioning is important for sampctl to use the version control features

Happy Pawning!
-->

## Installation

Simply install to your project:

```bash
sampctl package install emmett-white/samp-death-items
```

Include in your code and begin using the library:

```pawn
#include <death-items>
```

## Usage
```pawn
// Example
hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
	if (newkeys & KEY_YES)
	{
		GivePlayerWeapon(playerid, 24, 30);
	}


	if (newkeys & KEY_CROUCH)
	{
		// You just need to kill yourself...
		SetPlayerHealth(playerid, 0.0);
	}


	if (newkeys & KEY_NO)
	{
		GivePlayerMoney(playerid, 100);
	}

	return 1;
}
```

## Testing

<!--
Depending on whether your package is tested via in-game "demo tests" or
y_testing unit-tests, you should indicate to readers what to expect below here.
-->

To test, simply run the package:

```bash
sampctl package run
```
