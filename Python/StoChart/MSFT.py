import sys
import os
from datetime import datetime, date
import csv
import requests
from math import isclose
from Stock import Stock
import Utils            

# This class can be converted to a base class, with specific stock classes implementing their own
# getters and modifiers.
class MSFT:
    def __init__(self, start_date, end_date = None, file_dir = "C:\\temp", file_name = "MSFT.daily.csv", key_file = "C:\\Users\\robhanda\\OneDrive\\Documents\\AlphaVantageCoKey.txt"):
        self.start_date = start_date
        self.file_path = os.path.join(file_dir, file_name)
        self.key_file = key_file
        self.end_date = date.today() if end_date is None else end_date
        if self.end_date < self.start_date:
            raise Exception("End date cannot be less than start date!")
        if not os.path.exists(self.key_file):
            raise Exception("Key file does not exist!")
    
    def GetDataFromAlphaVantage(self, start_date, last3months = True):
        if Utils.DatesAreClose(start_date, date.today()):
            return []
        key = ""
        with open(self.key_file) as f:
            key = f.read().split()
        csv_url_template = "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY_ADJUSTED&symbol=MSFT&apikey={avkey}&datatype=csv"
        if not last3months:
            csv_url_template += "outputsize=full"
        csv_url = csv_url_template.format(avkey = key)
        return Utils.GetDataFromWeb(csv_url, Stock.header(), Stock.DictReaderToList)
    
    def GetData(self):
        cache = Utils.GetDataFromCache(self.file_path, Stock.DictReaderToList)
        av_available_from = date(2000, 1, 1)
        from_av = []
        if len(cache) == 0 
            from_av.extend(self.GetDataFromAlphaVantage(av_available_from, False))
        else:
            #TODO
            if Utils.DatesAreClose(self.start_date, date.today(), 89) and len(from_av) < 4000:
                from_av.extend(self.GetDataFromAlphaVantage(av_available_from, False))
            else:
                from_av.extend(self.GetDataFromAlphaVantage(self.start_date))
            if len(cache) > 0:
                cache_start_date = cache[0].bizday
                cache_end_date = cache[-1].bizday
                av_start_date = from_av[0].bizday
                av_end_date = from_av[-1].bizday
                if not Utils.DatesAreClose(cache_start_date, av_available_from, 500):
            
