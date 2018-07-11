from datetime import datetime, date
from math import isclose

class Stock:
    bizday_title = "BizDay"
    open_title = "Open"
    high_title = "High"
    low_title = "Low"
    close_title = "Close"
    adjclose_title = "AdjClose"
    vol_title = "Volume"
    div_title = "Dividend"
    split_title = "SplitCoeff"

    def __init__(self, entry):
        if entry is None:
            # Unused so far
            self.bizday     = date(1, 1, 1)
            self.open       = 0.0
            self.high       = 0.0
            self.low        = 0.0
            self.close      = 0.0
            self.adjclose   = 0.0
            self.vol        = 0
            self.div        = 0.0
            self.split      = 0.0
        else:
            self.bizday     = datetime.strptime(entry[Stock.bizday_title], "%Y-%m-%d").date()
            self.open       = float(entry[Stock.open_title])
            self.high       = float(entry[Stock.high_title])
            self.low        = float(entry[Stock.low_title])
            self.close      = float(entry[Stock.close_title])
            self.adjclose   = float(entry[Stock.adjclose_title])
            self.vol        = int(entry[Stock.vol_title])
            self.div        = float(entry[Stock.div_title])
            self.split      = float(entry[Stock.split_title])
    
    def __lt__(self, other):
        if self.bizday < other.bizday:
            return True
        elif self.bizday == other.bizday:
            return isclose(self.adjclose, other.adjclose, abs_tol=1e-5)
        else:
            return False
        
    def __str__(self):
        return "{},{:.6f},{:.6f},{:.6f},{:.6f},{:.6f},{},{:.6f},{:.6f}".format(
            self.bizday.strftime("%Y-%m-%d"),
            self.open,
            self.high,
            self.low,
            self.close,
            self.adjclose,
            self.vol,
            self.div,
            self.split)
    
    def __eq__(self, other):
        return str(self) == str(other)
    
    @staticmethod
    def Header():
        return "{},{},{},{},{},{},{},{},{}".format(
            Stock.bizday_title,
            Stock.open_title,
            Stock.high_title,
            Stock.low_title,
            Stock.close_title,
            Stock.adjclose_title,
            Stock.vol_title,
            Stock.div_title,
            Stock.split_title)

    @staticmethod
    def DictReaderToList(reader):
        return [Stock(r) for r in reader]
