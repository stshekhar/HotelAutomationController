Hotel Automation Controller Problem Statement A very prestigious chain of Hotels is facing a problem managing their electronic equipments. Their equipments, like lights, ACs, etc are currently controlled manually, by the hotel staff, using switches. They want to optimise the usage of Power and also ensure that there is no inconvenience caused to the guests and staff. So the Hotel Management has installed sensors, like Motion Sensors, etc at appropriate places and have approached you to program a Controller which takes inputs from these sensors and controls the various equipments. The way the hotel equipments are organised and the requirements for the Controller is below:

● A Hotel can have multiple floors

● Each floor can have multiple main corridors and sub corridors

● Both main corridor and sub corridor have one light each

● Both main and sub corridor lights consume 5 units of power when ON

● Both main and sub corridor have independently controllable ACs

● Both main and sub corridor ACs consume 10 units of power when ON

● All the lights in all the main corridors need to be switched ON between 6PM to 6AM, which is the Night time slot

● When a motion is detected in one of the sub corridors the corresponding lights need to be switched ON between 6PM to 6AM (Night time slot)

● When there is no motion for more than a minute the sub corridor lights should beswitched OFF

● The total power consumption of all the ACs and lights combined should not exceed (Number of Main corridors * 15) + (Number of sub corridors * 10) units of per floor. Sub corridor AC could be switched OFF to ensure that the power consumption is not more than the specified maximum value

● When the power consumption goes below the specified maximum value the ACs that were switched OFF previously must be switched ON

Motion in sub corridors is input to the controller. Controller need to keep track and optimise the power consumption.

Write a program that takes input values for Floors, Main corridors, Sub corridors and takes different external inputs for motion in sub corridors and for each input prints out the state of all the lights and ACs in the hotel. For simplicity, assume that the controller is operating at the night time. Sample input and output below.

Initial input to the controller: Number of floors: 2 Main corridors per floor: 1 Sub corridors per floor: 2

Subsequent Inputs from Sensors

Output from controller for corresponding sensor input

Default state (when the program is first run) Floor 1 Main corridor 1 Light 1 : ON AC : ON Sub corridor 1 Light 1 : OFF AC : ON Sub corridor 2 Light 2 : OFF AC : ON Floor 2 Main corridor 1 Light 1 : ON AC : ON Sub corridor 1 Light 1 : OFF AC : ON Sub corridor 2 Light 2 : OFF AC : ON

Movement in Floor 1, Sub corridor 2

Floor 1 Main corridor 1 Light 1 : ON AC : ON Sub corridor 1 Light 1 : OFF AC : OFF Sub corridor 2 Light 2 : ON AC : ON Floor 2 Main corridor 1 Light 1 : ON AC : ON Sub corridor 1 Light 1 : OFF AC : ON Sub corridor 2 Light 2 : OFF AC : ON

No movement in Floor 1, Sub corridor 2 for a minute

Floor 1 Main corridor 1 Light 1 : ON AC : ON Sub corridor 1 Light 1 : OFF A C : O N Sub corridor 2 Light 2 : OFF AC : ON Floor 2 Main corridor 1 Light 1 : ON AC : ON Sub corridor 1 Light 1 : OFF AC : ON Sub corridor 2 Light 2 : OFF AC : ON

Since the hotel management is trying this for the first time, they would be changing the requirements around which electronic equipments are controlled and the criteria based on which they are controlled, so the solution design should be flexible enough to absorb these requirement changes without significant change to the system.
