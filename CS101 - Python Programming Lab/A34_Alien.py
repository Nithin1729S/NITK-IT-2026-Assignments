class Alien:
    count=0
    def __init__(self,x_coordinate,y_coordinate):
        self.x_coordinate=x_coordinate
        self.y_coordinate=y_coordinate
        self.health=3
        Alien.count+=1

    def hit(self):
        if self.health>0:
            self.health-=1

    def is_alive(self):
        if self.health==0:
            return False
        else:
            return True

    def teleport(self,x_cor,y_cor):
        self.x_coordinate=x_cor
        self.y_coordinate=y_cor

    def collision_detection(self,other_object):
        pass

    @classmethod
    def total_aliens_created(cls):
        return Alien.count


def new_aliens_collection(alien_start_positions):
    lst=[]
    for i in alien_start_positions:
        lst.append(Alien(*i))
    return lst








