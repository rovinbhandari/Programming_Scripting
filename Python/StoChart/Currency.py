from datetime import datetime, date
from math import isclose

class Currency:
    bizday_title = "BizDay"
    conversion_title = "Conversion"

    def __init__(self, entry = None):
        if entry is None:
            # Unused so far
            self.bizday = date(1, 1, 1)
            self.conversion = 1.0
        else:
            self.bizday = datetime.strptime(entry[Currency.bizday_title], "%Y-%m-%d").date()
            self.conversion = float(entry[Currency.conversion_title])

    def __lt__(self, other):
        if self.bizday < other.bizday:
            return True
        elif self.bizday == other.bizday:
            return isclose(self.conversion, other.conversion, abs_tol=1e-5)
        else:
            return False
        
    def __str__(self):
        return "{0},{1:.6f}".format(self.bizday.strftime("%Y-%m-%d"), self.conversion)

    def __eq__(self, other):
        return str(self) == str(other)
    
    @staticmethod
    def Header():
        return "{0},{1}".format(Currency.bizday_title, Currency.conversion_title)

    @staticmethod
    def DictReaderToList(reader):
        return [Currency(r) for r in reader]