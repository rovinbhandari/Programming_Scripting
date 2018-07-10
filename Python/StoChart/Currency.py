from datetime import datetime, date
from math import isclose

class Currency:
    bizday_title = "BizDay"
    conversion_title = "Conversion"

    def __init__(self, entry):
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
    
    @staticmethod
    def header():
        return "{0},{1}".format(Currency.bizday_title, Currency.conversion_title)

    @staticmethod
    def DictReaderToList(reader):
        return [Currency(r) for r in reader]