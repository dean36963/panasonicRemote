# panasonicRemote

Places your remote could be:

 - Behind the television
 - On the floor
 - On the sofa
 - Tucked down the side of the sofa, along with that £20 note that you lost a year or two ago

Did you find it? Worry not, try this program!

## Building from source

Ensure `qt5` is installed.

After cloning run:

```
./package.sh
```

Which will run `qmake` and `make` and also zip up a final package of the build.

A helper script (`build_windows.sh`) is provided to build for windows if you're on a Linux machine and want to build for windows.

## Running

### GUI

Launch `panasonicRemote` (or `panasonicRemote.exe` on windows) to launch the GUI. Currently, the program doesn't autodetect the TV's IP address, so you must enter it during the first run. Once a successful command has been set, this will be saved for next use. To use this program reliably, you'd probably want to setup a static IP for the TV.

Once the IP has been selected, click a button! This will send a HTTP request to that IP, which (hopefully - see disclaimer section) will be equivalent to pressing the corresponding button on your lost remote, where ever it is!

### Command Line

You can launch this in a headless mode, for example:

```
./panasonicRemote res/panasonic_viera_e_series NRC_MUTE-ONOFF
```

Which will send a single request to toggle MUTE on the TV. This uses the most recent successful IP that was used in the GUI.

## Disclaimers

The list of disclaimers is not exhaustive:

 - I only tested any windows builds through Wine, not on a real windows machine.
 - I have only tested this program on my panasonic TV and I can't be bothered to find out exactly what model this is.

#### Wait...

Ok, don't panic: I found the remote. I guess I'll just post this to GitHub anyway.
