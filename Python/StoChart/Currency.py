import sys
import os
from datetime import datetime, date
import csv
import requests
from math import isclose

class Currency:
    bizday_title = "BizDay"
    conversion_title = "Conversion"

    def __init__(self, bizday_str, conversion_str):
        self.bizday = datetime.strptime(bizday_str, "%Y-%m-%d").date()
        self.conversion = float(conversion_str)

    def __lt__(self, other):
        if self.bizday < other.bizday:
            return True
        elif self.bizday == other.bizday:
            return isclose(self.conversion, other.conversion, abs_tol=1e-5)
        else:
            return False
        
    def __str__(self):
        return "{0},{1:.6f}".format(self.bizday.strftime("%Y-%m-%d"), self.conversion)


# This class can be converted to a base class, with specific currency classes implementing their own
# getters and modifiers.
class NOK:
    def __init__(self, start_date, end_date = None, file_dir = ".", file_name = "USDNOK.daily.csv"):
        self.start_date = start_date
        self.file_path = os.path.join(file_dir, file_name)
        self.end_date = date.today() if end_date is None else end_date
        if self.end_date < self.start_date:
            raise Exception("End date cannot be less than start date!")
    
    def DictReaderToList(self, reader):
        l = [Currency(r[Currency.bizday_title], r[Currency.conversion_title]) for r in reader]
        l.sort()
        return l

    def GetDataFromCache(self):
        if os.path.exists(self.file_path):
            with open(self.file_path) as f:
                return self.DictReaderToList(csv.DictReader(f))
        return []
    
    def GetDataFromNorgesBank(self, start_date):
        csv_url_template = "https://data.norges-bank.no/api/data/EXR/B.USD.NOK.SP?StartPeriod={year}-{month}-{day}&format=csv-:-comma-false-y"
        csv_url = csv_url_template.format(year=start_date.year, month=start_date.month, day=start_date.day)
        with requests.Session() as s:
            download = s.get(csv_url)
            content = download.content.decode('utf-8')
            return self.DictReaderToList(csv.DictReader(content.splitlines()))
    
    def UpdateCache(self, values):
        with open(self.file_path, 'w') as f:
            f.write("{0},{1}".format(self.bizday_title, self.conversion_title))
            for v in values:
                f.write(str(v))

    def GetData(self):
        cache = self.GetDataFromCache()
        nb_start_date = self.start_date
        if len(cache) > 0:
            cache_start_date = cache[0].bizday
            cache_end_date = cache[-1].bizday
            #    ==========csd===========ced===========
            # 1:  ^nsd
            # 2:                 ^nsd
            # 3:                                ^nsd
            # Case 1: fetch all
            # Case 2, 3: fetch from ced
            if nb_start_date > cache_start_date:
                nb_start_date = cache_end_date
        from_nb = self.GetDataFromNorgesBank(nb_start_date)
        new_values = [e for e in from_nb if not (e in cache)]
        cache.extend(new_values)
        cache.sort()
        self.UpdateCache(cache)
        return [v for v in cache if v.bizday >= self.start_date and v.bizday <= self.end_date]

def Test(sd, ed):
    n = NOK(start_date = sd, end_date = ed)
    c = GetData()
    print sum([v.conversion for v in c])/float(len(c))

Test(date(2017, 6, 25), date(2018, 6, 25))