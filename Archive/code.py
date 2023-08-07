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
B_BKY = Building("Bakery", "Fireplace", 1)
B_BFC = Building("BlackForestCafe", "Lit", 2)
B_CWA = Building("CaddingtonWinterAle", "Lit", 3)
B_CDS = Building("CandyShoppe", "Lit", 4)
B_CGS = Building("CigarShoppe", "Fireplace", 5)
C_BWS = Building("Berrywood School", "Lit", 6)
C_CHU = Building("Church", "Lit", 7)
C_FST = Building("FireStation", "Lit", 8)
C_GZB = Building("Gazebo", "Lit", 9)
C_LHS = Building("Lighthouse", "Lit", 10)
R_HSB = Building("HorseBarn", "Lit", 11)
R_HS1 = Building("House1", "Lit", 12)
R_HS2 = Building("House2", "Lit", 13)
R_HS3 = Building("House3", "Lit", 14)
R_HS4 = Building("House4", "Lit", 15)

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
<<<<<<< Updated upstream
BlinkPattern(B2.position + 1)
BlinkPattern(B2.position)
=======
BlinkPattern(B_BFC.position + 1)
BlinkPattern(B_BFC.position)
>>>>>>> Stashed changes

# if __name__ == '__main__':
# Process(target=BlinkPattern).start()
# Process(target=BlinkPattern2).start()



