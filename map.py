import tkinter as tk
import math
import os, sys

window = tk.Tk()
window.title('map')
window.geometry('800x550')
window.configure(background='white')

header_label = tk.Label(window, text='map or map near')
header_label.pack()

fo = open("cmd.txt", "w")

def alll():
    fo.write('MAP ')
    fo.close()
    sys.exit(0)
    
def near():
    fo.write('MAPNEAR ')
    fo.close()
    sys.exit(0)

button1 = tk.Button(window, text='Random', command=alll).pack(padx=5, pady=10)
button2 = tk.Button(window, text='Map near', command=near).pack(padx=5, pady=10)

window.mainloop()
