# DJnner - For MacOS Users (.dmg & .app file available)

<img width="390" alt="DJnner Logo" src="https://github.com/junseok03/DJnner/assets/151435171/b591c32b-64ae-403c-981e-45ef561860dc">

## Introduction
DJnner is a JUCE framework(c++) based DJ application designed for new beginners. <br>
DJnner allows users to modify the speed and volume as the music plays. <br>
It also creates the waveform display once the music file is loaded. <br>
I also added a memo space on the screen for the users.

## How to use:

### Loading audio files
<img width="863" alt="Screenshot 2024-07-07 at 7 16 41 PM" src="https://github.com/junseok03/DJnner/assets/151435171/484b16ed-be4a-4ac0-85d1-f09966373eac">

To load audio files into the audio player, the user has to click one of the ‘load’ buttons like the image above. The users can load files for each deck. Once the ‘load’ button is clicked, the file chooser window will pop up on the screen like the image below.

<img width="810" alt="Screenshot 2024-07-07 at 7 19 21 PM" src="https://github.com/junseok03/DJnner/assets/151435171/11a0af8b-4bce-463d-8214-517cdf4b8b71">

Once the audio file is loaded, the users can see the waveform display of the loaded audio file, just like the image below.

<img width="918" alt="Screenshot 2024-07-07 at 7 20 00 PM" src="https://github.com/junseok03/DJnner/assets/151435171/9d1c5d28-4bd0-44cf-b276-d5dd0addae8e">

### Playing the track
In order to play the music after loading the file, simply press the green ‘play’ button. The music will start to play. When the music starts to play, the green playhead will appear on the screen like the image below. The playhead will automatically follow the position of the music.

<img width="660" alt="Screenshot 2024-07-07 at 7 22 00 PM" src="https://github.com/junseok03/DJnner/assets/151435171/df3a0b57-8feb-48ab-994b-9ff76c494148">

The users can play the multiple tracks at the same time like the image below.

<img width="617" alt="Screenshot 2024-07-07 at 7 23 29 PM" src="https://github.com/junseok03/DJnner/assets/151435171/36c6a03a-11f0-4e6f-9525-e2a6d38eb467">

To stop playing the music, simply press the red ‘stop’ button.<br>

The users can also adjust the position of the music by using the linear slider located
below the waveform display. It does not matter whether the music is playing or not.

<img width="864" alt="Screenshot 2024-07-07 at 7 24 12 PM" src="https://github.com/junseok03/DJnner/assets/151435171/4056c596-f734-449c-af8d-753272a76f40">

We can see that there is a ‘loop’ button on each deck. No matter whether the music is playing or not, if the user presses the ‘loop’ button, the music will restart playing the music.

<img width="662" alt="Screenshot 2024-07-07 at 7 25 19 PM" src="https://github.com/junseok03/DJnner/assets/151435171/eb34ff98-86f2-49c4-a177-4950828aaf67">

### Adjusting volumes 
There are two knobs located below the buttons of each deck. The knob on the left has the functionality to adjust the volume of the loaded music file. The users can easily increase or decrease the volume with this knob ranging from 0 to 1. The default value is set to 0.5.

<img width="741" alt="Screenshot 2024-07-07 at 7 29 17 PM" src="https://github.com/junseok03/DJnner/assets/151435171/5b9522a6-0986-4e80-be77-4cb7b65925e2">

### Adjusting the speed
The knob on the right has the functionality to adjust the speed of the loaded music file. The users can easily increase or decrease the speed with this knob ranging from 0 to 10. The default value is set to 1.0.

<img width="711" alt="Screenshot 2024-07-07 at 7 30 52 PM" src="https://github.com/junseok03/DJnner/assets/151435171/6cf047ec-b99f-4c72-a0ce-74f53e4499ec">

### Memo space
DJ producers have to handle multiple tracks at the same time, which can be very complex. Each track has different tempos and speeds, which could possibly confuse DJ producers. The memo space at the bottom of each deck can help the users.

<img width="960" alt="Screenshot 2024-07-07 at 9 18 38 PM" src="https://github.com/junseok03/DJnner/assets/151435171/7767ddd7-17c5-445f-ab99-f9766529c023">


## <i> !!!!!!!!! IMPORTANT NOTICE  !!!!!!!!!
"DJnner is damaged and can’t be opened. You should move it to the Trash" Error on Mac

To solve this: open a terminal and type: xattr -cr <path/to/application.app> </i>
