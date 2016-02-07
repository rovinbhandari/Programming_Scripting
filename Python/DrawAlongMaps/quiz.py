from gen_data import Country, GenData
import random
import time
import os
import colorama

AllContinents =  ["Africa",
                  "Asia",
                  "Europe",
                  "North America",
                  "Oceania",
                  "South America"]
PlayFor = AllContinents                  
Score = {"m": 0, "r": 0}
ExitGame = False

data = GenData()
data = [x for x in data if not x.MapFile == "" and x.Continent in PlayFor]
datasize = len(data)
playedindices = [-1]

def ShowScore():
  print("Score: Mimi={0}, Rainy={1}".format(Score["m"], Score["r"]))

def ClearScreen():
  print(chr(27) + "[2J")

def Play():
  global data
  global datasize
  global playedindices
  global ExitGame
  index = -1
  if len(playedindices) == datasize + 1:
    ExitGame = True
    print("No more unique countries left!")
    ShowWinner()
    return
  while index in playedindices:
    index = random.randint(0, datasize - 1)
  playedindices.append(index)  
  choice = data[index]
  ClearScreen()
  print("3..")
  time.sleep(1)
  print("2..")
  time.sleep(1)
  print("1..")
  time.sleep(1)
  print("Draw... ", end = " ")
  print(colorama.Fore.LIGHTYELLOW_EX + choice.Name)
  print(colorama.Style.RESET_ALL)
  return InputHandler(choice)

def InputHandler(state):
  global Score
  global ExitGame
  command = ""
  while True:
    command = input("si/sm/sl/m/r/t/x > ");
    if command in ["si", "sm", "sl", "m", "r", "t", "x"]:
      break
  if command == "si":
    print("Capital: {0}\nContinent: {1}".format(state.Capital, state.Continent))
    return InputHandler(state)
  elif command == "sm":
    os.system(state.MapFile);
    return InputHandler(state)
  elif command == "sl":
    os.system(state.LocationFile);
    return InputHandler(state)
  elif command == "x":
    ClearScreen()
    ShowWinner()
    ExitGame = True
    return
  elif command == "m":
    Score["m"] += 1
  elif command == "r":
    Score["r"] += 1
  elif command == "t":
    Score["m"] += 1
    Score["r"] += 1
  return

def ShowWinner():
  ShowScore()
  winner = ""
  if Score["m"] > Score["r"]:
    winner = "Mimi"
  elif Score["m"] < Score["r"]:
    winner = "Rainy"
  else:
    winner = "BOTH"
  winner = "\n\n{0} WON! :)\n\n".format(winner)
  print(colorama.Fore.LIGHTGREEN_EX + winner)
  print(colorama.Style.RESET_ALL)

print("A country name will appear on the screen. Draw it's map, it's location in the world, and mark it's capital correctly. 1 mark for getting it more correct than other players. Commands: \n" +
      "\tsi for Show Info\n" +
      "\tsm for Show Map\n" +
      "\tsl for Show Location\n" + 
      "\tm for +1 Mimi\n" +
      "\tr for +1 Rainy\n" + 
      "\tt for tie\n" +
      "\tx for exit and show score") 
input("Press Enter key to start the game...")
colorama.init()
while not ExitGame:
  Play()
colorama.deinit()  
