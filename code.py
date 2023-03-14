import board
# import digitalio
import time
import neopixel
# from rainbowio import colorwheel
# from multiprocessing import Process

class Building:
    def __init__(self, name, pattern, position):
        self.name = name
        self.pattern = pattern
        self.position = position

    def SetPattern(self, pattern):
        self.pattern = pattern

    def GetPattern(self):
        return self.pattern

    def SetPosition(self, position):
        self.position = position

    def GetPosition(self):
        return self.position

# Instantiate Buildings
R25 = Building("BlueHouse", "Fireplace", 1)
B13 = Building("MusicShoppe", "Lit", 2)
B5 = Building("CigarShoppe", "Lit", 3)
B2 = Building("BlackForestCafe", "Lit", 4)
R26 = Building("GreyHouse", "Fireplace", 5)

# Initialize Neopixel Parameters
pixelPin = board.D10
numPixels = 50
neopixel.GRB = 'RGB'
pixels = neopixel.NeoPixel(pixelPin, numPixels, brightness=0.3, auto_write=False)

RED = (255, 0, 0)
YELLOW = (255, 150, 0)
GREEN = (0, 255, 0)
CYAN = (0, 255, 255)
BLUE = (0, 0, 255)
PURPLE = (180, 0, 255)
OFF = (0, 0, 0)

def LitPattern(index):
    while 1:
        pixels[index] = (255, 255, 255)

def BlinkPattern(index):
    while True:
        print("loop")
        pixels[index] = (255, 0, 0)
        pixels.show()
        time.sleep(1)
        pixels[index] = OFF
        pixels.show()
        time.sleep(1)

# LitPattern(B2.position)
BlinkPattern(B2.position + 1)
BlinkPattern(B2.position)

# if __name__ == '__main__':
# Process(target=BlinkPattern).start()
# Process(target=BlinkPattern2).start()



