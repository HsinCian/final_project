import tkinter as tk
import math
import os, sys

window = tk.Tk()
window.title('print')
window.geometry('800x550')
window.configure(background='white')

header_label = tk.Label(window, text='Print all, type or near')
header_label.pack()

fo = open("cmd.txt", "w")

def alll():
    fo.write('PRINT ')
    fo.close()
    sys.exit(0)
    
def typee():
    fo.write('PRINT_TYPE ')
    fo.close()
    os.system("python3 type.py")
    sys.exit(0)
    
def near():
    fo.write('PRINT_NEAR ')
    fo.close()
    sys.exit(0)

button1 = tk.Button(window, text='Print all', command=alll).pack(padx=5, pady=10)
button2 = tk.Button(window, text='Print type', command=typee).pack(padx=5, pady=10)
button3 = tk.Button(window, text='Print near', command=near).pack(padx=5, pady=10)

window.mainloop()


