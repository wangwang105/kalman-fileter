Import('rtconfig')
from building import *
import os

cwd = GetCurrentDir()
src = Glob('*.c')
inc = [cwd+""]

CXXFLAGS = ''

group = DefineGroup('kalman_filter', src, depend = [''], CPPPATH = inc, CXXFLAGS = CXXFLAGS)

Return('group')
