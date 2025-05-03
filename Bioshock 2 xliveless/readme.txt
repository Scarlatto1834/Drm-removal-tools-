Fake xlive.dll for bioshock 1.03, by Timeslip
http://timeslip.users.sourceforge.net

A fake version of xlive.dll that allows you to play bioshock 2 single player without having games for windows - live installed. It should be compatible with both retail and digital distributions of the game. It fairly obviously isn't compatible with multiplayer. (Although since multiplayer is a separate exe in a different directory tree, installing this shouldn't effect it.)

XXXXXXXXXXXXX
XX Install XX
XXXXXXXXXXXXX

If you haven't already, install bioshock 2 normally, and patch to the latest version. (1.03 at the time of writing.)

Copy xlive.dll to '<bioshock's install dir>\SP\Builds\Binaries\'

If desired, uninstall games for windows live via your systems add/remove programs menu.

XXXXXXXXXXXXXXX
XX Uninstall XX
XXXXXXXXXXXXXXX

Delete xlive.dll again. You'll get the normal games for windows live login screen the next time you launch. (Unless you uninstalled g4wl in the meantime, in which case you'll get a crash.)

XXXXXXXXXXXXXXXXXXX
XX Configuration XX
XXXXXXXXXXXXXXXXXXX

Create a file called 'xlive.ini' in '<my documents>\bioshock2\'. Type [xlive] on the first line. Options are added below that in an <option>=<value> format. The following options are available:

profile: Pick the name of the offline profile to use. This makes very little difference, but even if you can't carry over offline savegames, using the same name as a real offline xlive profile will let you carry over any per-user settings.

loader: valid values are 0 or 1. If 1, and you're using the same 1.03 retail version that I am, this will let you launch bioshock2.exe directly rather than having to go through the securom launcher. If you're not using 1.03, or the retail version, it'll just crash you, so leave it at 0.

XXXXXXXXXXXXXXXXXX
XX Known issues XX
XXXXXXXXXXXXXXXXXX

The biggest one; you'll lose access to preexisting save games, whether online or off. They'll still be there, you just can't load them until you remove the fake xlive dll.

The first time you start bioshock 2 after using this it may take longer than normal to start up, or possibly crash. Subsequent launches will work normally.