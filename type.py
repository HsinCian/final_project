import tkinter as tk
import math
import os, sys

window = tk.Tk()
window.title('type')
window.geometry('800x550')
window.configure(background='white')

header_label = tk.Label(window, text='Choose your type')
header_label.pack()

fo = open("input.txt", "w")

def chken():
#button1['bg']='olive'
    fo.write('CHICKEN_RICE ')
    fo.close()
    sys.exit(0)
    
def jap():
#  button2['bg']='lightskyblue'
    fo.write('JAPANESE ')
    fo.close()
    sys.exit(0)
    
def kor():
#    button3['bg']='navy'
    fo.write('KOREAN ')
    fo.close()
    sys.exit(0)
    
def amr():
#   button4['bg']='seagreen'
    fo.write('AMERICAN ')
    fo.close()
    sys.exit(0)
    
def chi():
#   button5['bg']='purple'
    fo.write('CHINESE ')
    fo.close()
    sys.exit(0)
    
def brk():
#   button6['bg']='pink'
    fo.write('BREAKFAST ')
    fo.close()
    sys.exit(0)
    
def drk():
#    button7['bg']='slategrey'
    fo.write('DRINKS ')
    fo.close()
    sys.exit(0)
    
def des():
#   button8['bg']='lightsalmon'
    fo.write('DESSERT ')
    fo.close()
    sys.exit(0)

button1 = tk.Button(window, text='Chicken rice', bg='yellow', command=chken).pack(padx=5, pady=10)
button2 = tk.Button(window, text='Japanese', command=jap).pack(padx=5, pady=10)
button3 = tk.Button(window, text='Korean', command=kor).pack(padx=5, pady=10)
button4 = tk.Button(window, text='American', command=amr).pack(padx=5, pady=10)
button5 = tk.Button(window, text='Chinese', command=chi).pack(padx=5, pady=10)
button6 = tk.Button(window, text='Breakfast', command=brk).pack(padx=5, pady=10)
#button7 = tk.Button(window, text='Chinese', command=drk).pack(padx=5, pady=10)
#button8 = tk.Button(window, text='Breakfast', command=des).pack(padx=5, pady=10)
button7 = tk.Button(window, text='Drinks', command=drk).pack(padx=5, pady=10)
button8 = tk.Button(window, text='Dessert', command=des).pack(padx=5, pady=10)

window.mainloop()
