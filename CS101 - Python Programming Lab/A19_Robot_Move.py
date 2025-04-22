
def move(input_list):
  x_pos=input_list[0][0]
  y_pos=input_list[0][1]
  commands=input_list[1]
  for i in commands:
    if i=="R":
      x_pos+=1
    if i=="D":
      y_pos-=1
    if i=="L":
      x_pos-=1
    if i=="U":
      y_pos+=1
  return (x_pos,y_pos)
pass


