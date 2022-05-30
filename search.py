import tkinter as tk
import math
import os, sys

window = tk.Tk()
window.title('search')
window.geometry('800x550')
window.configure(background='white')


fo = open("input.txt", "w")

def event():
    fo.write( name_entry.get())
    fo.close()
    sys.exit(0)

name_frame = tk.Frame(window)
name_frame.pack(side=tk.TOP, padx=5, pady=10)
name_label = tk.Label(name_frame, text='name')
name_label.pack(side=tk.LEFT)
name_entry = tk.Entry(name_frame)
name_entry.pack(side=tk.LEFT)


button = tk.Button(window, text='search', command=event).pack(padx=5, pady=10)

window.mainloop()

fo.close()
