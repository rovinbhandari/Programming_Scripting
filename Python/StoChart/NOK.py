import sys
import os
from datetime import datetime, date
import csv
import requests
from math import isclose
from Currency import Currency
import Utils

# This class can be converted to a base class, with specific currency classes implementing their own
# getters and modifiers.
class NOK:
    def __init__(self, start_date, end_date = None, file_dir = "C:\\temp", file_name = "USDNOK.daily.csv"):
        self.start_date = start_date
        self.file_path = os.path.join(file_dir, file_name)
        self.end_date = date.today() if end_date is None else end_date
        if self.end_date < self.start_date:
            raise Exception("End date cannot be less than start date!")
    
    def GetDataFromNorgesBank(self, start_date):
        if Utils.DatesAreClose(start_date, date.today(), 0):
            return []
        csv_url_template = "https://data.norges-bank.no/api/data/EXR/B.USD.NOK.SP?StartPeriod={yyyy_mm_dd}&format=csv-:-comma-false-y"
        csv_url = csv_url_template.format(yyyy_mm_dd = start_date.strftime("%Y-%m-%d"))
        return Utils.GetDataFromWeb(csv_url, Currency.Header(), Currency.DictReaderToList)

    def GetData(self):
        cache = Utils.GetDataFromCache(self.file_path, Currency.DictReaderToList)
        nb_start_date = self.start_date
        if len(cache) > 0:
            cache_start_date = cache[0].bizday
            cache_end_date = cache[-1].bizday
            #    ==========csd===========ced===========
            # 1:  ^nsd
            # 2:                    ^nsd
            # 3:                                ^nsd
            # Case 1: fetch all
            # Case 2, 3: fetch from ced
            if Utils.DatesAreClose(nb_start_date, cache_start_date, 4):
                nb_start_date = cache_end_date
        from_nb = self.GetDataFromNorgesBank(nb_start_date)
        cache = Utils.UpdateCache(self.file_path, Currency.Header(), cache, from_nb)
        return Utils.DateFilter(cache, self.start_date, self.end_date)

def TestNOK(sd, ed):
    n = NOK(start_date = sd, end_date = ed)
    c = n.GetData()
    assert isclose(sum([v.conversion for v in c])/float(len(c)), 7.9, abs_tol=1e-1), "average came out incorrect."

# TestNOK(date(2017, 6, 25), date(2018, 6, 25))