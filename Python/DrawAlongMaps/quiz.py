from gen_data import Country, GenData
import random
import time
import os

AllContinents = [ "Africa",
                  "Asia",
                  "Europe",
                  "North America",
                  "Oceania",
                  "South America"]
PlayFor = AllContinents                  

Score = {"m": 0, "r": 0}

data = GenData()
data = [x for x in data if not x.MapFile == ""]
datasize = len(data)

def ShowScore():
  print("Score: Mimi={0}, Rainy={1}".format(Score["m"], Score["r"]))

def Play():
  index = random.randint(0, datasize)
  choice = data[index]
  print("3..")
  time.sleep(1)
  print("2..")
  time.sleep(1)
  print("1..")
  time.sleep(1)
  print("Draw... {0}".format(choice.Name))
  command = ""
  while True:
    command = input("sm/sl/m/r/t/x > ");
    if command in ["sm", "sl", "m", "r", "t", "x"]:
      break
  if command == "sm":
    os.system(choice.MapFile);
  elif command == "sl":
    os.system(choice.LocationFile);
  elif command == "m":
    Score["m"] += 1
    ShowScore()
  elif command == "r":
    Score["r"] += 1
    ShowScore()
  elif command == "t":
    Score["m"] += 1
    Score["r"] += 1
    ShowScore()
  else:
    ShowScore()
    winner = ""
    if Score["m"] > Score["r"]:
      winner = "Mimi"
    elif Score["m"] < Score["r"]:
      winner = "Rainy"
    else:
      winner = "BOTH"
    print("\n\n{0} WON! :)".format(winner))

print("A country name will appear on the screen. Draw it's map, it's location in the world, and mark it's capital correctly. 1 mark for getting it more correct than other players. Commands: \n" +
      "\tsm for Show Map\n" +
      "\tsl for Show Location\n" + 
      "\tm for +1 Mimi\n" +
      "\tr for +1 Rainy\n" + 
      "\tt for tie\n" +
      "\tx for exit and show score") 
Play()
