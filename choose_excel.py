import tkinter as tk
import math
import os, sys

window = tk.Tk()
window.title('choose_excel')
window.geometry('800x550')
window.configure(background='white')

header_label = tk.Label(window, text='Do you want to export to Excel?(Y/N)')
header_label.pack()

fo = open("YN.txt", "w")

def alll():
    fo.write('Y ')
    fo.close()
    sys.exit(0)
    
def near():
    fo.write('N ')
    fo.close()
    sys.exit(0)

button1 = tk.Button(window, text='Yes', command=alll).pack(padx=5, pady=10)
button3 = tk.Button(window, text='No', command=near).pack(padx=5, pady=10)

window.mainloop()


