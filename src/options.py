from enum import Enum
from typing import Any
from thefuzz import fuzz

class Option():
    
    def __init__(self, opt: str= None, defaults=[]):
        self.defaults = defaults
        
        if not opt:
            self.opt = ""
            return
        
        opt = opt.strip()
        assert len(opt) > 0 and opt[0] == "-", f"Option {opt} not valid"
        self.opt = opt
        
        
    

    def eval(self, args):
        if not isinstance(args, list):
            args = [args]
        return self.opt.format(*(val for val in args))
    
    
    def __add__(self, o):
        return Option(self.opt + " " + o.opt, self.defaults + o.defaults)
    
    
    def __str__(self):
        return self.opt.format(*(val for val in self.defaults))
    
    
class OptionEnum(Enum):
    
    HARDENED=Option("-fhardened")
    STACK_PROTECTOR_STRONG=Option("-fstack-protector-strong")
    STACK_PROTECTOR_ALL=Option("-fstack-protector-all")
    D_FORTIFY_SOURCE_1=Option("-D_FORTIFY_SOURCE=1")
    D_FORTIFY_SOURCE_2=Option("-D_FORTIFY_SOURCE=2")
    D_FORTIFY_SOURCE_3=Option("-D_FORTIFY_SOURCE=3")
    
    def find(ids: str) -> "Option":
        """
        Finds and returns an OptionEnum based on the given string of IDs.
        
        Args:
            ids (str): A string containing space-separated IDs.
        Returns:
            OptionEnum: The corresponding OptionEnum for the given IDs.
        """
        matched_opt = Option("")
        
        opts = ids.split(" ")
        if not isinstance(opts, list):
            opts = [opts]
        
        for opt in OptionEnum:
            if any(str(opt.value) == o for o in opts):
                matched_opt += opt.value
        
        return matched_opt
        
        
        
        
    