

Thrust Feedback Controller
--------------------------

Measure Altitide -> Compare with Altitude Reference () -> 

-> Feed Resulting Error into Altitide Controller (Uses info to determine how to increase or decrease thrust) [A Thrust PID Controller] ->

-> Send Thrust Data to Motor Mixing Algorithm


If drone is below Altitude Reference. It is too low, Error is positive, so the thrust will increase
If the drone is above the Altitude Reference. The inverse occurs




Pitch Feedback Controller
--------------------------

Measure Pitch Angle -> Compare with Pitch Angle Reference () -> 

-> Feed Resulting Error into Pitch Angle Controller (Uses info to determine how to increase or decrease pitch) [A Pitch PID Controller] ->

-> Send Pitch Data to Motor Mixing Algorithm





Roll Feedback Controller
--------------------------

Measure Roll Angle -> Compare with Roll Angle Reference () -> 

-> Feed Resulting Error into Roll Angle Controller (Uses info to determine how to increase or decrease roll) [A Roll PID Controller] ->

-> Send Roll Data to Motor Mixing Algorithm




Yaw Feedback Controller
--------------------------

Measure Yaw Angle -> Compare with Yaw Angle Reference () -> 

-> Feed Resulting Error into Yaw Angle Controller (Uses info to determine how to increase or decrease yaw) [A Yaw PID Controller] ->

-> Send Yaw Data to Motor Mixing Algorithm