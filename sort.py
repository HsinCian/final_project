import tkinter as tk
import math
import os, sys

window = tk.Tk()
window.title('sort')
window.geometry('300x200')
window.configure(background='white')

header_label = tk.Label(window, text='Sort by what?')
header_label.pack()

fo = open("input.txt", "w")

def alll():
    fo.write('longitude ')
    fo.close()
    os.system("python3 choose_excel.py")
    sys.exit(0)
    
def typee():
    fo.write('latitude ')
    fo.close()
    os.system("python3 choose_excel.py")
    sys.exit(0)
    
def near():
    fo.write('rating ')
    fo.close()
    os.system("python3 choose_excel.py")
    sys.exit(0)

button1 = tk.Button(window, text='longitude', command=alll).pack(padx=5, pady=10)
button2 = tk.Button(window, text='latitude', command=typee).pack(padx=5, pady=10)
button3 = tk.Button(window, text='rating', command=near).pack(padx=5, pady=10)

window.mainloop()


