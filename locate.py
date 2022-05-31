import tkinter as tk
import math
import os, sys

window = tk.Tk()
window.title('Location')
window.geometry('800x550')
window.configure(background='white')

header_label = tk.Label(window, text='Choose your location')
header_label.pack()

fo = open("input.txt", "w")

def SCIENCE():
    fo.write('SCIENCE\n')
    fo.close()
    sys.exit(0)
    
def ENGINEERING():
    fo.write('ENGINEERING\n')
    fo.close()
    sys.exit(0)
    
def CENTER():
    fo.write('CENTER\n')
    fo.close()
    sys.exit(0)
    
def DORMITORY():
    fo.write('DORMITORY\n')
    fo.close()
    sys.exit(0)
    
def GATE():
    fo.write('GATE\n')
    fo.close()
    sys.exit(0)
    
def MINXIONG_STATION():
    fo.write('MINXIONG_STATION\n')
    fo.close()
    sys.exit(0)

def CHIAYI_STATION():
    fo.write('CHIAYI_STATION\n')
    fo.close()
    sys.exit(0)


button4 = tk.Button(window, text='SCIENCE', command=SCIENCE).pack(padx=5, pady=10)
button5 = tk.Button(window, text='ENGINEERING', command=ENGINEERING).pack(padx=5, pady=10)
button4 = tk.Button(window, text='CENTER', command=CENTER).pack(padx=5, pady=10)
button5 = tk.Button(window, text='DORMITORY', command=DORMITORY).pack(padx=5, pady=10)
button4 = tk.Button(window, text='GATE', command=GATE).pack(padx=5, pady=10)
button5 = tk.Button(window, text='MINXIONG_STATION', command=MINXIONG_STATION).pack(padx=5, pady=10)
button4 = tk.Button(window, text='CHIAYI_STATION', command=CHIAYI_STATION).pack(padx=5, pady=10)

window.mainloop()
