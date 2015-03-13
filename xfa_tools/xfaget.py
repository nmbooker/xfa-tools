
from collections import OrderedDict


def acroform(doc):
    """Extract the acroform from the catalog.
    """
    return doc.catalog['AcroForm']

def xfa(form):
    """Get the XFA from am AcroForm.
    """
    return form.resolve()['XFA']

def evens(alist):
    """Get the even indexes from a list.
    """
    return alist[::2]

def odds(alist):
    """Get the odd indexes from a list.
    """
    return alist[1::2]

def xfa_alist(xfa):
    return zip(evens(xfa), odds(xfa))

def xfa_dict(xfa):
    """Convert the xfa list into a dictionary.
    """
    return OrderedDict(xfa_alist(xfa))

def stream_raw_data(stream):
    return stream.resolve().get_data()
