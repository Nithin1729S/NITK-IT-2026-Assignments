
EAST = 1
NORTH = 2
WEST = 3
SOUTH = 4
class Robot:
    coordinates=()
    direction=NORTH

    def __init__(self, direction=NORTH, x_pos=0, y_pos=0):
        self.coordinates=(x_pos,y_pos)
        self.direction=direction

    def move(self, route):
        for i in route:
            if i=="L":
                if self.direction<4:
                    self.direction+=1
                else:
                    self.direction=1

            if i=="R":
                if self.direction >1:
                    self.direction -= 1
                else:
                    self.direction = 4


            x = self.coordinates[0]
            y = self.coordinates[1]


            if i=="A":
                if self.direction==1:
                    x+=1
                elif self.direction==2:
                    y+=1
                elif self.direction==3:
                    x-=1
                elif self.direction==4:
                    y-=1

            self.coordinates=(x,y)





