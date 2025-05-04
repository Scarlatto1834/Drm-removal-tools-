Fake xlive.dll for fable 3, by Timeslip
v0.11
http://timeslip.users.sourceforge.net

A fake version of xlive.dll that allows you to play fable 3 single player without having games for windows - live installed. It fairly obviously isn't compatible with any multiplayer elements, and you wont be able to download any dlc/patches in game, whether free or otherwise.

This has been tested only on versions 1.0 and 1.1, on a retail disc edition. I've no idea whether or not it'll work on a download version, and forward compatibility with any future fable 3 patches isn't guaranteed. This is not a crack, and an internet connection is still required for the initial online activation.

The benifits of not using gfwl are faster loading and saving times, an increase in fps, (albeit not the 5-30% you typically get from removing securom,) and no out-of-place looking gfwl screens popping up all over the place.

-------- Install -------------------------

If you haven't already, install fable 3 normally. Run it once and fill in your activation code. Let it perform its 0-day release check and online activation gunk, then get as far as the g4wl sign in screen, click the red x and then click quit.

Copy the fake xlive.dll to the installation directory, alongside fable3.exe.

See the importing save games section if you already have a g4wl savegame that you want to continue.

If desired, uninstall games for windows live via your systems add/remove programs menu.

-------- Uninstall -----------------------

Delete xlive.dll again. You'll get the normal games for windows live login screen the next time you launch. (Unless you uninstalled g4wl in the meantime, in which case you'll get a crash.)

-------- Configuration -------------------

Create a file called 'fakexlive.ini' in '<roaming app data>\Lionhead Studios\Fable 3\'. Type [xlive] on the first line. Options are added below that in an <option>=<value> format. The following options are available:

-- Basic options

xuidl / xuidh:
Two 8 digit hex numbers, in 0x00000000 format. These combine to make offline user id that will be used. This is what is used to segregate savegames, etc. The default is 0x10001000 for each. (xuidl is the least significant 8 bytes, and xuidh the most.)

profile:
Pick the name of the offline profile to use. This makes very little difference, it's just used at a few points in the ui. The default is 'Player', and there's a limit of 32 characters.

ShowMessages:
Valid values are 0, 1 or 2. Default is 2. If 1, any xlive messages are shown in a messagebox. If 0, they're ignored. If 2, they're rendered in game in a very crappy but fullscreen-safe way. I advise against setting this to 1 while running fullscreen.

UseDLC:
This option is experimental, and may or may not work!
Valid values are 0, 1 or 2, default 0. If 1, enables the use of the free DLC. First download a copy of the free DLC, then copy it to '<fable 3's install folder>\data\dlc\content'. After downloading from gfwl it'll be in '<local app data>\Microsoft\XLive\DLC\<3 random folder names>\content', but you can copy the files from someone else if you don't have a gfwl account. Copy across all files in the content directory; there should be 40 of them in total.
The paid for DLC (understone, etc.) is not supported.
Note that after using this option, your save will become dlc dependent, and cannot be loaded without the dlc present. Due to the experimental nature of this option, I strongly recommend backing up your save games before switching it on.

Setting this to 2 works identically to 1, except that instead of a single folder being used called 'data\dlc', you get 10 to use named from 'data\mod0' to 'data\mod9'. This is to facilitate packaging mods as dlc, which allows for easy installs. (Or at least, easier than trying to repack levels.bnk)

-- exe patch options
These require the 1.1.1.3 exe, which is 29,067,024 bytes in size.

LoaderPatch:
Valid values are 0 or 1. Default is 0. If set to 1, removes the check in fable 3 that it's been launched from the launcher, but it triggers some other securom checks, such as forcing the game into low detail mode. It's really only for me, for testing purposes to stop securom whining about the debugger; I don't recommend using it in a real game.

e.g., an ini file containing the default options looks like this:
------------------------------
[xlive]
xuidl=0x10001000
xuidh=0x10001000
profile=Player
ShowMessages=2
LoaderPatch=0
UseDLC=0
------------------------------

-------- Importing a g4wl savegame -------

Fable does a lot of checksumming and checks on save files before letting you load them, so you can't just copy/paste save files around and expect them to work. To switch a save over to the fake gfwl, open it up in the save game editor and use the option to recalculate checksums. Note that if you were previously playing online, and were using anything other than the free DLC, then the gfwl remover will not be able to load your save.

fable also has an independent xuid check, so view the save you're opening in the save editor, note down the 'remote xuid' value, and set the xuidl/xuidh values in gfwl's ini appropriately, and make sure you put the saves in a matching directory. (Alternatively, edit the save to use the default xuid of 1000100010001000, which saves you having to worry about which is the high or low part.)

And remember: If this goes wrong you'll corrupt the save games for real, and even if nothing goes wrong, you'll be unable to load the newly saved savegame using g4wl, so again, BACKUP THE WHOLE SAVE FOLDER BEFORE STARTING!!!

-------- Known issues --------------------

Any DLC downloaded with gfwl will be invisible to fable 3 while this gfwl remover is active. It will reappear and work normally when the remover is removed.

Trying to rename something (child/weapon/whatever) doesn't work.

-------- Changelog -----------------------
v0.11
Expanded the DLC support to support loading mods

v0.10
Added experimental support for the free DLC

v0.9
Fixed a potential crash after arriving in aurora

v0.8
Removed checksum patch (not required with save editor, and broken by fable 1.1 patch)
xlive message boxes are now shown by default, and are displayed in game
Fix crash on rename. (Although renaming still doesn't work)
Achievement support

v0.7
Removed the save game importer.
Documentation changes to reflect the release of the save game editor

v0.6
The save game importer helper dll no longer spawns more than one background thread

v0.5
Added an option to allow for much easier importing of save games, and save game modification

v0.4
Added an option to change your xuid
Included instructions for importing g4wl savegames
Added an option to display xlive messages in a win32 dialog
Renamed  SuppressLoaderPatch to  LoaderPatch and flipped the logic

v0.3
Fixed a crash when making promises

v0.2
Fixed a crash bug when loading a save game in certain areas
Changed SuppressLoaderPatch to default to 1, on account of the securom check 
