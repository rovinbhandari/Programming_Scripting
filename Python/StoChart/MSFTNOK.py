import sys
import os
from datetime import datetime, date, timedelta
from bisect import bisect_left
import csv
from math import isclose
from copy import deepcopy
from Currency import Currency
from Stock import Stock
from NOK import NOK
from MSFT import MSFT
import Utils

class MSFTNOK:
    def __init__(self, start_date, end_date = None, file_dir = "C:\\temp", file_name = "MSFTNOK.csv"):
        self.start_date = start_date
        self.file_path = os.path.join(file_dir, file_name)
        self.end_date = date.today() if end_date is None else end_date
        if self.end_date < self.start_date:
            raise Exception("End date cannot be less than start date!")
    
    def CopyItemInSeries(self, series, index, bizday):
        new_val = deepcopy(series[index])
        new_val.bizday = bizday
        return new_val
    
    def AddMissingDates(self, series):
        # identify missing date,
        # copy values of date which is the closest to this date;
        # if bizday is smaller than all others, copy the first value in series,
        # else copy the next smaller neighbour
        # assumption is that series is sorted.
        check_date = deepcopy(self.start_date)
        dates = [v.bizday for v in series]
        fillers = []
        while check_date <= self.end_date:
            if not (check_date in dates):
                neighbour_index = bisect_left(dates, check_date) - 1
                if neighbour_index < 0:
                    neighbour_index = 0
                fillers.append(
                    self.CopyItemInSeries(
                        series, neighbour_index, check_date))
            check_date += timedelta(days = 1)
        series.extend(fillers)
        series.sort()
        return series
    
    def Combine(self, series_c, series_s, combiner):
        return list(map(combiner, series_c, series_s))
    
    def CurrencyConversion(self, c, s):
        assert c.bizday == s.bizday, "BizDays don't match!"
        s2 = deepcopy(s)
        s2.open       *= c.conversion 
        s2.high       *= c.conversion 
        s2.low        *= c.conversion 
        s2.close      *= c.conversion 
        s2.adjclose   *= c.conversion 
        s2.vol        *= c.conversion 
        s2.div        *= c.conversion 
        return s2

def MSFTinNOK(sd, ed = None):
    mn = MSFTNOK(start_date=sd, end_date=ed)
    nok = mn.AddMissingDates(NOK(mn.start_date, mn.end_date).GetData())
    msft = mn.AddMissingDates(MSFT(mn.start_date, mn.end_date).GetData())
    Utils.WriteToFile("C:\\temp\\USDNOK.filled.csv", Currency.Header(), nok)
    Utils.WriteToFile("C:\\temp\\MSFT.filled.csv", Stock.Header(), msft)
    nok_dates = set([v.bizday for v in nok])
    msft_dates = set([v.bizday for v in msft])
    diff1 = nok_dates - msft_dates
    diff2 = msft_dates - nok_dates
    Utils.WriteToFile("C:\\temp\\datediff1.csv", "BizDay", diff1)
    Utils.WriteToFile("C:\\temp\\datediff2.csv", "BizDay", diff2)
    msftnok = mn.Combine(nok, msft, mn.CurrencyConversion)
    Utils.WriteToFile(mn.file_path, Stock.Header(), msftnok)

MSFTinNOK(date(2017,6,1))