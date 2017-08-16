# redstone-repeater
A set of tools for improving the Minecraft AFK fishing experience.

Introduction
---
In Minecraft, AFK fishing is the process of setting up a redstone contraption
that will allow you to repeatedly cast and reel in your fishing pole over and
over just by continually pressing the right mouse button. This is one of the
most benefitial automations you can build at the moment because of the loot it
gives you. You can check out [this video](https://www.youtube.com/watch?v=f53js4zZ2y8) if you'd like to know more. If you are unfamiliar with the game of
Minecraft, redstone automations, and AFK fishing, there will be a lot of words
in this README that you don't understand.

The Problem
---
The major problem with all redstone AFK fisheries is that they are finickay.
They depend on the user's lag, the redstone tick delays, and getting the two
matched up just right with the each other. Even the best setups seem to produce
situations for some players where the rod will uselessly recast and reel in
over and over until it's lucky enough to settle in the water. This is because
the click repeat rate on mouse buttons in game are incredibly fast and also not
affected by your operating system's mouse repeat rate. Occasionally, the rod
will cast and reel in before the redstone device activates, causing you to reel
in the line too fast and need to recast.

Moreover, some people tape down their mouse, or put something heavy on it to
depress the right mouse botton. This can, however, be a bit hazerdoous if you
have a cat who is prone to knocking your mouse around on your desk. Even if the
right mouse button is still depressed, there's a very good chance that the
cursor is now in the wrong place, which will actually break your Mending
fishing rod.

Another solution is to rebind your 'use item' control to a keyboard key instead
of the right mouse button. This allows you to unplug your mouse to safe guard
it from cats or roommates who might slightly adjust your unattended laptop.
Then you an simply put a weigjt on the correct key. I used to use a D battery
for this and it worked fairly well. But it requires you to go into the
Minecraft configuration and rebind the controls back and forth whenever you
want to play or AFK fish.

The Solution
---
To solve these problems, I've gone outside of the game, and created a set of
very simple tools to improve the AFK fishing experience. Both the hardware and
software solutions have one major thing in common. They do not hold down the
right mouse button. They instead, continually, and more slowly, click the right
mouse button over and over again. This gives any redstone fishing contraption
plenty of time to open or close and will let the rod hit the water on the first
cast every single time. In addition, the solutions do not require you to do any
annoying control rebinding, duct taping, or balancing acts. Furthermore it does
not require you to use your normal mouse, so it can be safely unplugged to
avoid playful cats trying to "help".

Hardware solution
---
redstone-repeater.ino is an Arduino C program for use on the Trinket. It
requires the TrinketMouse library. Once loaded, you can plug the trinket into
your computer and after the 8-second programming delay, it will behave just
like a USB mouse that someone is right clicking every 400 miliseconds which is
2.5 time per second.

Adafruit Trinkets are available for $7 here: https://www.adafruit.com/product/1501

I also recommend a [USB adapter](https://www.amazon.com/gp/product/B00TAM0MZW/ref=oh_aui_detailpage_o00_s00?ie=UTF8&psc=1) to make it easier to use,
but any micro USB cable, like the one you probably use for your phoen, will
work just fine.

Software solution
---
The user experience using the Trinket as an external hardware device is nice
because you can easily unplug the device when you want to stop. If you don't
have a Trinket or don't want to use an external piece of hardware, you can do
this all in software. The downside is that you will need to turn it off when
you are done AFK fishing and it can be a bit irritating to alt-tab over to your
terminal and press control-c to kill it all while the program is constantly
right clicking over whatever you're trying to do with the mouse. But it does
work.

afk-fish-linux.sh and afk-fish-macos.sh are two simple command-line programs
that will do this for you. Both of them have a 4-second delay preceding the
right clicking so that you have some time to alt-tab over to Minecraft and make
sure that your mouse cursor is in the correct spot.

Dependencies
---
The hardware solution requires the [Adafruit-Trinket-USB](https://github.com/adafruit/Adafruit-Trinket-USB) library to work.

The Linux shell script requires
[xdotool](https://github.com/jordansissel/xdotool), which can be installed on
Ubuntu and with `apt-get install xdotool`

The MacOS shell script requires [cliclick](https://github.com/BlueM/cliclick),
which is available for install with `brew install cliclick`.

