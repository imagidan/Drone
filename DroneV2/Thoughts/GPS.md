# GPS

The Global Positioning System works by satellites finding the distance between you and them, and with that value finding the sphere of possibilities you are on. This is the concept of trilateration. With 3 independently positioned satellites, those spheres of possibilities give two intersections: one on earth and one in space. The GPS adds the sphere of possibility we call earth to find its current location. To find the distance between the satellite and itself, the GPS receives the exact time, and the exact position of the satellite when a signal is sent. After that the GPS, substracts its current time. From the velocity at which the data from the satellite is sent (speed of light) and with the satellite's position, and the time difference, we can find the current position. To find, the inaccuracy delta of the GPS clock, we can use the location found with the last 3 satellites, and use a 4th satellite to calculate the time inaccuracy delta once again using the physics equation of speed. More connections to satellites gives a better estimation of time inaccuracy, and maybe position as well.

Interesting: A Clock error of microseconds can have the effect of changing the position by **kilometers**!

Even with a great gps, there are other factors that could make the use of a gps either less accurate or unusable, this includes position errors of the satellite, being indoors, individual gps bias, etc.

Because of the theory of special relativity which somehow states that faster moving clocks in space, go slower in terms of clock time. Through general relativity theory, somehow gravity makes clock time go slower. Btw Idk about these theories, although I hope I do in some time. Without these theories implemented in satellites, there would be a 10 km error per day.

There are also other GPS versions from other space fairing countries. For example, GPS is from the US, GLONASS is from Russia, Galileo is from Europe, etc. These satelittes are combined to give a bigger network to GPS devices. Some satellites are more accurate than others which makes me think why cant they just accept the better one! 

In considering a GPS for the drone, it is important to have a very accurate clock, and for the GPS to be light. Other considerations are enough memory for historical data, an efficient computing process, antenna, support for multiple satellite types, and maybe smtg else. I will need to remove GPS when in low-quality areas such as indoors.

The GPS is a great example of the use of a subject I have yet to really acquire: **physics**.

[Here](https://www.youtube.com/watch?v=8eTlI19_57g) is the video I got information from.
