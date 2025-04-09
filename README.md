A small Arduinosketch to run a electronic dice. I build this with students in mathlessons, using ESP32-S2. 
You need to connect 7 LED to the ESP. Use the GPIO 2,3,4,5,6,8,9 for that. Connect a Button with standard 0V on GPIO 13.
The sketch has an error in line 98, which causes the random-function to generate numbers from 0 to 6.
This leads to an further error in line 75, which shows a "5" pattern on the dice. It is obfuscated as an errormessage "Do a x, if default"
the students had to find out, whats going wron, so it is not a mistake, but the learninggoal.
