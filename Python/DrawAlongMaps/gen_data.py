import sys
import os
from os import listdir
from os.path import isfile, join
import csv

DBG = not True

class Country:
  Name = ""
  Capital = ""
  MapFile = ""
  LocationFile = ""
  Continent = ""
  
  def AssignMapFile(self, path):
    self.MapFile = path
  
  def AssignLocationFile(self, path):
    self.LocationFile = path

  def Print(self):
    print("COUNTRY\t[{0}\n\t\t{1}\n\t\t{2}\n\t\t{3}\n\t\t{4}]".format(
            self.Continent,
            self.Name,
            self.Capital,
            self.MapFile,
            self.LocationFile))

def dbg(x):
  if not DBG:
    return
  if type(x) is Country:
    x.Print()
  else:
    print(x)

def CountryInfoFromCsv():
  with open("list-of-countries-in-the-world.csv") as csvfile:
    reader = csv.reader(csvfile, delimiter=',', quotechar='"')
    for row in reader:
      country = Country()
      country.Continent = row[0].strip()
      country.Name = row[1].strip()
      country.Capital = row[2].strip()
      yield country

def MapsFilesFromDirectory(directory, keyfunc):
  files = [join(directory, f) for f in listdir(directory) if isfile(join(directory, f))]
  filepaths = {}
  for i in files:
    key = keyfunc(os.path.basename(i))
    filepaths[key] = i
  return filepaths  

def CheckAndAssociateMapFiles(maps, country, associatefunc):
  normalizedname = country.Name.lower().replace(' ', '-')
  if normalizedname in maps:
    associatefunc(maps[normalizedname])
  else:  
    # TODO: check inexact name
    dbg("{0} not found.".format(normalizedname))

def GenData():
  countries = []
  countryinfo = CountryInfoFromCsv()
  countrymaps = MapsFilesFromDirectory(
                  "C:\\Users\\Rovin\\maps\\CountryMaps",
                  lambda s : s[:-8])
  locationmaps = MapsFilesFromDirectory(
                  "C:\\Users\\Rovin\\maps\\CountryLocationMaps",
                  lambda s : s[7:-4])
  for i in countryinfo:
     dbg(i)
     CheckAndAssociateMapFiles(countrymaps, i, i.AssignMapFile)
     CheckAndAssociateMapFiles(locationmaps, i, i.AssignLocationFile)
     countries.append(i)
  return countries
