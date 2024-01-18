#  
#  Author:  Alain Coulombe - January 2024
#
#  First try at making GPIOs change - for the Node.JS interface I'm building.
#
#  I built this to cycle through 4 Raspbery Pi GPIO outputs so that they 
#  could be looped back to the Digital Input GPIO pins of a Seed reTerminal DM
#  and be used to generate a test signal for the node.js program I've been
#  working on.
#
#  https://www.youtube.com/watch?v=Ht_LdGroNZE
#
#  GPIO Output pins: BCM:  5 on hardware pin # 29
#                    BCM: 19 on hardware pin # 35
#                    BCM: 12 on hardware pin # 32
#                    BCM: 13 on hardware pin # 33
#

import time
import sys
from itertools import cycle  #  Use the itertools function "cycle" 
#   https://www.geeksforgeeks.org/python-itertools/
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

GPIO_01 = 5   #  29  ==>  Broadcom GPIO # 5 on header pin # 29
GPIO_02 = 19  #  35  ==>  Broadcom GPIO # 19 on header pin # 35
GPIO_03 = 12  #  32  ==>  Broadcom GPIO # 12 on header pin # 32
GPIO_04 = 13  #  33  ==>  Broadcom GPIO # 13 on header pin # 33

onTime = 0.75  #  GPIO Bit "ON" time - applies to all bits.

GPIO.setup(GPIO_01, GPIO.OUT)  #  Set BCM GPIO #5 as an OUTPUT
GPIO.setup(GPIO_02, GPIO.OUT)  #  Set BCM GPIO #6 as an OUTPUT
GPIO.setup(GPIO_03, GPIO.OUT)  #  Set BCM GPIO #12 as an OUTPUT
GPIO.setup(GPIO_04, GPIO.OUT)  #  Set BCM GPIO #13 as an OUTPUT

#  Initialize all 4 GPIO outputs to LOW (safe mode)...
GPIO.output(GPIO_01, GPIO.LOW)	
GPIO.output(GPIO_02, GPIO.LOW)
GPIO.output(GPIO_03, GPIO.LOW)
GPIO.output(GPIO_04, GPIO.LOW)
print ('Initialized all GPIOs to LOW')  #  Send message to the console.

output =  [
	(GPIO_01 , onTime),
	(GPIO_02 , onTime),
	(GPIO_03 , onTime),
	(GPIO_04 , onTime),
	]

output_cycle = cycle(output)  #  cycle comes from the itertools function.

while True:
	try:
	 bit, duration = next(output_cycle)  #  From "output" and "output cycle" above. 
	 # print (bit)
	 GPIO.output(bit, GPIO.HIGH)
	 print ('GPIO', (bit), 'is now On')  #  Send message to the console.
	 time.sleep(duration)

	 # print (bit)
	 GPIO.output(bit, GPIO.LOW)
	 print ('GPIO', (bit), 'is now Off')  #  Send message to the console.
	
	except KeyboardInterrupt:  # Attempt a graceful exit. Set ALL GPIOs LOW
	 print ("")
	 print ("CTRL-C detected - Shutting down.")
	 GPIO.output(5, GPIO.LOW)
	 print ("GPIO 5 Set to LOW")
	 GPIO.output(19, GPIO.LOW)
	 print ("GPIO 19 Set to LOW")
	 GPIO.output(12, GPIO.LOW)
	 print ("GPIO 12 Set to LOW")
	 GPIO.output(13, GPIO.LOW)
	 print ("GPIO 13 Set to LOW")
	 sys.exit()

sys.exit()
