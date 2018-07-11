import sys
import os
from datetime import datetime, date
import csv
import requests
from Currency import Currency
from Stock import Stock

def DatesAreClose(a, b, tolerance = 1):
    return abs((a - b).days) <= tolerance

def ConvertAndSort(reader, converter):
    data = converter(reader)
    data.sort()
    return data

def GetDataFromCache(file_path, converter):
    if os.path.exists(file_path):
        with open(file_path) as f:
            return ConvertAndSort(csv.DictReader(f), converter)
    return []

def GetDataFromWeb(url, header, converter):
    with requests.Session() as s:
        download = s.get(url)
        content = download.content.decode('utf-8')
        content_lines = content.splitlines()
        content_lines[0] = header
        return ConvertAndSort(csv.DictReader(content_lines), converter)

def UpdateCache(file_path, header, cache, to_merge):
    if not (len(to_merge) == 0):
        new_values = [e for e in to_merge if not (e in cache)]
        cache.extend(new_values)
        cache.sort()
        cache_dir = os.path.dirname(file_path)
        if not os.path.exists(cache_dir):
            os.makedirs(cache_dir)
        with open(file_path, 'w') as f:
            f.write(header + "\n")
            for v in cache:
                f.write(str(v) + "\n")
    return cache
    
def DateFilter(collection, start_date, end_date = None):
    end_date = date.today() if end_date is None else end_date
    return [v for v in collection if v.bizday >= start_date and v.bizday <= end_date]
