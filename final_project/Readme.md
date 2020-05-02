# Roomba Scheduler 

## Preamble

I bought a Roomba 620 on eBay some time ago to help me deal with the copious amounts of hair that my cat and dog leave about the house. Unfortunately due to me being cheap and also not reading about specifications. I bought a Roomba that did not have a scheduling feature meaning that I had to press a button for it to go about its Roomba business. This button pressing was unacceptable. 

So I went about trying to fix this. 

Fortunately, the iRobot Open Interface allows for easy programming. There are a bunch of ways to communicate with a Roomba. However, some time ago, a friend bought me an Arduino, so I have utilised it as a bridge between the computer and the Roomba, allowing me to send scheduling commands.


## How to

###What you will need: 

* A crap non-scheduling Roomba (Mr Roomba is a 620, yes that is his name)
* An Arduino (I have an Uno)
* A mac (I don't know how to PC, sorry)
* Four wires
* Arduino IDE which you can download or use the online version. Dealers choice. 

###Step 1

Remove your Roomba'c cover. This is undoubtedly the scariest bit. There are a lot of creaking sounds, and it feels as though the plastic will break. Push through this. You should* be okay. 

Once you have taken the cover off (just the white bit) you will see a port that kind of looks like one of those old school electrical connectors you sometimes find on musical equipment. This is your interface. 

*I take no responsibility for your crap Roomba. 

###Step 2

Get your Arduino (I have a UNO) and start connecting.: 

* Roomba port 7 (GND) <-> Arduino GND
* Roomba port 3 (RXD) <-> Arduino D4
* Roomba port 4 (TXD) <-> Arduino D3
* Roomba port 5 (BRC) <-> Arduino D5

Here is a pic:  

How did I figure out which ports? A shit ton of googling. But trust me, this is the right way to do it. I don't know why. It just is. 

###Step 3


Connect the USB cable between the Arduino and the computer.
Start the Arduino software and then paste the code in this repo.

Now, if you paste this code and do not make any changes. Then your Roomba will work according to my schedule, which might not work for you. I like mine going off in the evenings. So you will have to make adjustments. 

First to your day and time and then make changes to the Roomba schedule. You make those changes as follows:  

* Line 73 is where you set your time. Set your current time: (Day, Hour, Minute)

* Lines 152-167 you set the time you want the Roomba to go off each day. 

###Step 4

Press save and wait for your Roomba to sing. That means that all is well and you no longer have to press a button again. 