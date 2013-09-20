#! /usr/bin/env/python2

# Program Description:  A script that passes information to an ftdi chip that is 
#			attached to an arduino.  This way, a computer can send
#			information to an arduino and do cool stuff like make a
#			light blink.  (Based on code from Randy)

import pylibftdi as ft
import sys
import pygame as pg

TX  = 0b00000001
RX  = 0b00000010
RTS = 0b00000100
CTS = 0b00001000
DTR = 0b00010000
DSR = 0b00100000
DCD = 0b01000000
RI  = 0b10000000

LED = DCD
BCK = DSR
FWD = DTR 

def blink(bb):
    bb.port ^= LED

def fwd(bb):
    bb.port ^= FWD

def bck(bb):
    bb.port ^= BCK

pg.init()

screen = pg.display.set_mode((640, 480))

with ft.BitBangDevice(direction = ft.ALL_OUTPUTS) as bb:
    while True:

        for event in pg.event.get():
            # User pressed down on a key
            if event.type == pg.KEYDOWN:
     	    	# Controls for the car
                if event.key == pg.K_q:
                    sys.exit()
                elif event.key == pg.K_a:
                    blink(bb)
                elif event.key == pg.K_UP:
                    fwd(bb)
                elif event.key == pg.K_DOWN:
                    bck(bb)

            elif event.type == pg.KEYUP:
                if event.key == pg.K_a:
                    blink(bb)
                elif event.key == pg.K_UP:
                    fwd(bb)
                elif event.key == pg.K_DOWN:
                    bck(bb)


