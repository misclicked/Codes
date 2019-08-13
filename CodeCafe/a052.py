import atexit
import io
import sys

_I_B = sys.stdin.read().splitlines()
input = iter(_I_B).__next__
_O_B = io.StringIO()
sys.stdout = _O_B

@atexit.register
def write():
    sys.__stdout__.write(_O_B.getvalue())

s=input()
