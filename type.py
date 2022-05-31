import tkinter as tk
import math
import os, sys

window = tk.Tk()
window.title('type')
window.geometry('300x500')
window.configure(background='white')

header_label = tk.Label(window, text='Choose your type')
header_label.pack()

fo = open("input.txt", "w")

def chken():
    fo.write('CHICKEN_RICE ')
    fo.close()
    sys.exit(0)
    
def jap():
    fo.write('JAPANESE ')
    fo.close()
    sys.exit(0)
    
def kor():
    fo.write('KOREAN ')
    fo.close()
    sys.exit(0)
    
def amr():
    fo.write('AMERICAN ')
    fo.close()
    sys.exit(0)
    
def chi():
    fo.write('CHINESE ')
    fo.close()
    sys.exit(0)
    
def brk():
    fo.write('BREAKFAST ')
    fo.close()
    sys.exit(0)
    
def drk():
    fo.write('DRINKS ')
    fo.close()
    sys.exit(0)
    
def des():
    fo.write('DESSERT ')
    fo.close()
    sys.exit(0)

button1 = tk.Button(window, text='Chicken rice', bg='olive', command=chken).pack(padx=5, pady=10)
button2 = tk.Button(window, text='Japanese', bg='lightskyblue', command=jap).pack(padx=5, pady=10)
button3 = tk.Button(window, text='Korean',bg='slateblue', command=kor).pack(padx=5, pady=10)
button4 = tk.Button(window, text='American',bg='seagreen', command=amr).pack(padx=5, pady=10)
button5 = tk.Button(window, text='Chinese',bg='plum', command=chi).pack(padx=5, pady=10)
button6 = tk.Button(window, text='Breakfast',bg='pink', command=brk).pack(padx=5, pady=10)
button7 = tk.Button(window, text='Drinks',bg='slategrey', command=drk).pack(padx=5, pady=10)
button8 = tk.Button(window, text='Dessert',bg='lightsalmon', command=des).pack(padx=5, pady=10)

window.mainloop()
