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
            key = f.read().split()[0]
        csv_url_template = "https://www.alphavantage.co/query?function=TIME_SERIES_DAILY_ADJUSTED&symbol=MSFT&apikey={avkey}&datatype=csv"
        if not last3months:
            csv_url_template += "&outputsize=full"
        csv_url = csv_url_template.format(avkey = key)
        return Utils.GetDataFromWeb(csv_url, Stock.Header(), Stock.DictReaderToList)
    
    def GetData(self):
        cache = Utils.GetDataFromCache(self.file_path, Stock.DictReaderToList)
        av_available_from = date(2000, 1, 1)
        from_av = []
        if len(cache) < 4000:
            from_av = self.GetDataFromAlphaVantage(av_available_from, False)
        else:
            cache_end_date = cache[-1].bizday
            # assuming that self.start_date will always be after av_available_from
            # also assuming that if cache is present, it will have the full history from av_available_from
            if Utils.DatesAreClose(self.end_date, cache_end_date) or self.end_date < cache_end_date:
                pass # we're good
            elif (self.end_date - cache_end_date).days <= 89:
                from_av = self.GetDataFromAlphaVantage(self.start_date)
            else:
                from_av = self.GetDataFromAlphaVantage(av_available_from, False)
        cache = Utils.UpdateCache(self.file_path, Stock.Header(), cache, from_av)
        return Utils.DateFilter(cache, self.start_date, self.end_date)

def TestMSFT(sd, ed):
    m = MSFT(start_date = sd, end_date = ed, file_name="MSFT.csv")
    s = m.GetData()
    assert isclose(sum([v.adjclose for v in s])/float(len(s)), 85.1, abs_tol=1e-1), "average came out incorrect."

TestMSFT(date(2017, 6, 25), date(2018, 6, 25))