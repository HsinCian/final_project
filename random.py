import tkinter as tk
import math
import os, sys

window = tk.Tk()
window.title('random')
window.geometry('800x550')
window.configure(background='white')

header_label = tk.Label(window, text='Random,Random type or near')
header_label.pack()

fo = open("cmd.txt", "w")

def alll():
    fo.write('RANDOM ')
    fo.close()
    sys.exit(0)
    
def typee():
    fo.write('RANDOM_TYPE ')
    fo.close()
    os.system("python3 type.py")
    sys.exit(0)
    
def near():
    fo.write('RANDOM_NEAR ')
    fo.close()
    sys.exit(0)

button1 = tk.Button(window, text='Random', command=alll).pack(padx=5, pady=10)
button2 = tk.Button(window, text='Random type', command=typee).pack(padx=5, pady=10)
button3 = tk.Button(window, text='Random near', command=near).pack(padx=5, pady=10)

window.mainloop()
