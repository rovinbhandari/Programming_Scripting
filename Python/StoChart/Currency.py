import sys
import os
from datetime import datetime, date
import csv
import requests

class Currency:
    bizday_title = "BizDay"
    conversion_title = "Conversion"

    def __init__(self, bizday_str, conversion_str):
        self.bizday = datetime.strptime(bizday_str, "%Y-%m-%d").date()
        self.conversion = float(conversion_str)

    def __lt__(self, other):
        return self.bizday < other.bizday
        
    def __str__(self):
        return "{0},{1:.6f}".format(self.bizday.strftime("%Y-%m-%d"), self.conversion)


# This class can be converted to a base class, with specific currency classes implementing their own
# getters and modifiers.
class NOK:
    def __init__(self, start_date, file_dir = ".", file_name = "USDNOK.daily.csv"):
        self.start_date = start_date
        self.file_path = os.path.join(file_dir, file_name)
    
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
    
    def GetData(self):
        from_cache = self.GetDataFromCache()
        cache_start_date = from_cache[0].bizday
        #TODO