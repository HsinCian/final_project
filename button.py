import tkinter as tk
import math
import os, sys

window = tk.Tk()
window.title('')
window.geometry('300x600')
window.configure(background='white')

header_label = tk.Label(window, text='What do you want to do?')
header_label.pack()


def INSERT():
    fo.write("INSERT\n")
    fo.close()
    os.system("python3 insert.py")
    sys.exit(0)

def DELETE():
    fo.write("DELETE\n")
    fo.close()
    os.system("python3 delete.py")
    sys.exit(0)

def SEARCH():
    fo.write("SEARCH\n")
    fo.close()
    os.system("python3 search.py")
    sys.exit(0)
    
def SORT():
    fo.write("SORT\n")
    fo.close()
    os.system("python3 sort.py")
    sys.exit(0)
    
def PRINT():
    os.system("python3 print.py")
    #fo.write("PRINT\n")
    #fo.close()
    sys.exit(0)
    
def DISTANCE():
    fo.write("DISTANCE\n")
    fo.close()
    os.system("python3 distance.py")
    sys.exit(0)
    
def MY_HABBIT():
    fo.write("MY_HABIT\n")
    fo.close()
    sys.exit(0)
    
def STOP():
    fo.write("STOP\n")
    fo.close()
    sys.exit(0)

def RANDOM():
    os.system("python3 ran.py")
    #fo.write("RANDOM\n")
    #fo.close()
    sys.exit(0)

def MAP():
    os.system("python3 map_button.py")
    sys.exit(0)
    
def LOCATE():
    fo.write("LOCATE\n")
    fo.close()
    os.system("python3 locate.py")
    sys.exit(0)

fo = open("cmd.txt", "w")

tk.Button(window, text='INSERT', command = INSERT).pack(padx=5, pady=10)

delete_btn = tk.Button(window, text='DELETE', command = DELETE)
delete_btn.pack(padx=5, pady=10)
search_btn = tk.Button(window, text='SEARCH', command = SEARCH)
search_btn.pack(padx=5, pady=10)
sort_btn = tk.Button(window, text='SORT', command = SORT)
sort_btn.pack(padx=5, pady=10)
print_btn = tk.Button(window, text='PRINT', command = PRINT)
print_btn.pack(padx=5, pady=10)
random_btn = tk.Button(window, text='RANDOM', command = RANDOM)
random_btn.pack(padx=5, pady=10)
distance_btn = tk.Button(window, text='DISTANCE', command = DISTANCE)
distance_btn.pack(padx=5, pady=10)
habbit_btn = tk.Button(window, text='MY_HABIT', command = MY_HABBIT)
habbit_btn.pack(padx=5, pady=10)
map_btn = tk.Button(window, text='MAP', command = MAP)
map_btn.pack(padx=5, pady=10)
locate_btn = tk.Button(window, text='LOCATE', command = LOCATE)
locate_btn.pack(padx=5, pady=10)
stop_btn = tk.Button(window, text='STOP', command = STOP)
stop_btn.pack(padx=5, pady=10)



window.mainloop()

fo.close()
