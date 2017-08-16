# redstone-repeater

A set of tools to improve the AFK fishing experience in Minecraft.

Hardware solution
---
redstone-repeater.ino is an Arduino C program for use on the Trinket. It
requires the TrinketMouse library. Once loaded, you can plug the trinket into
your computer and after the 8-second programming delay, it will behave just
like a USB mouse that someone is right clicking every 400 miliseconds which is
2.5 time per second.

Software solution
---
The user experience using the Trinket as an external hardware device is nice
because you can easily unplug the device when you want to stop. If you don't
have a Trinket and don't want to use an external piece of hardware, you can do
this all in software. The downside is that you will need to turn it off when
you are done AFK fishing and it can be a bit irritating to alt-tab over to you
terminal and press control-c to kill it all while the program is constantly
right clicking over what you're trying to do. But it does work.

afk-fish-linux.sh and afk-fish-macos.sh are two simple command-line programs
that will do this for you. Both of them have a 4-second delay preceding the
right clicking so that you have some time to alt-tab over to Minecraft and make
sure that your mouse cursor is in the correct spot.

The MacOS version requires cliclick, which is available for install with
`brew install cliclick`. The Linux version requires xdotool, which can be
installed on Ubuntu and with `apt-get install xdotool`
