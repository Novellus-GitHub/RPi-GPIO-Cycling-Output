# RPi-GPIO-Cycling-Output
 Test program to cycle four Raspberry Pi GPIOs ON and OFF

  

  First try at making GPIOs cylce ON and OFF - for the Node.JS interface I'm building

  I built this to cycle through 4 Raspbery Pi GPIO outputs so that they 
  could be looped back to the Digital Input GPIO pins of a Seed reTerminal DM
  and be used to generate a test signal for the node.js program I've been
  working on.

  GPIO Output pins: 
  
                    BCM: 5 on hardware pin # 29
  
                    BCM: 19 on hardware pin # 35
                    
                    BCM: 12 on hardware pin # 32
                    
                    BCM: 13 on hardware pin # 33

  The above outputs are then hard wired routed to GPIO Inputs as follows (input pins are being monitored / reported by node.js):                  

                    BCM: 5 on hardware pin # 29  ==> to ==> BCM: 16 on hardware pin # 36
  
                    BCM: 19 on hardware pin # 35  ==> to ==> BCM: 17 on hardware pin # 11
  
                    BCM: 12 on hardware pin # 32 ==> to ==> BCM: 22 on hardware pin # 15
  
                    BCM: 13 on hardware pin # 33 ==> to ==> BCM: 23 on hardware pin # 16


  View the attached video to see the "INPUT" pins being cycled by the output of the 
  GPIO_Driver_01.py script.


