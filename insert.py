import tkinter as tk
import math
import os, sys

window = tk.Tk()
window.title('insert')
window.geometry('300x550')
window.configure(background='white')

fo = open("input.txt", "w")

def event():
    fo.write( name_entry.get())
    fo.write(" ")
    fo.write( type_entry.get())
    fo.write(" ")
    fo.write( phone_entry.get())
    fo.write(" ")
    fo.write( longitude_entry.get())
    fo.write(" ")
    fo.write( latitude_entry.get())
    fo.write(" ")
    fo.write( rating_entry.get())
    fo.write(" ")
    fo.write( begin_entry.get())
    fo.write(" ")
    fo.write( closed_entry.get())
    fo.write(" ")
    fo.write ( price_entry.get())

    fo.close()
    sys.exit(0)

name_frame = tk.Frame(window)
name_frame.pack(side=tk.TOP, padx=5, pady=10)
name_label = tk.Label(name_frame, text='name')
name_label.pack(side=tk.LEFT)
name_entry = tk.Entry(name_frame)
name_entry.pack(side=tk.LEFT)

type_frame = tk.Frame(window)
type_frame.pack(side=tk.TOP, padx=5, pady=10)
type_label = tk.Label(type_frame, text='type')
type_label.pack(side=tk.LEFT)
type_entry = tk.Entry(type_frame)
type_entry.pack(side=tk.LEFT)

phone_frame = tk.Frame(window)
phone_frame.pack(side=tk.TOP, padx=5, pady=10)
phone_label = tk.Label(phone_frame, text='phone')
phone_label.pack(side=tk.LEFT)
phone_entry = tk.Entry(phone_frame)
phone_entry.pack(side=tk.LEFT)

longitude_frame = tk.Frame(window)
longitude_frame.pack(side=tk.TOP, padx=5, pady=10)
longitude_label = tk.Label(longitude_frame, text='longitude')
longitude_label.pack(side=tk.LEFT)
longitude_entry = tk.Entry(longitude_frame)
longitude_entry.pack(side=tk.LEFT)

latitude_frame = tk.Frame(window)
latitude_frame.pack(side=tk.TOP, padx=5, pady=10)
latitude_label = tk.Label(latitude_frame, text='latitude')
latitude_label.pack(side=tk.LEFT)
latitude_entry = tk.Entry(latitude_frame)
latitude_entry.pack(side=tk.LEFT)

rating_frame = tk.Frame(window)
rating_frame.pack(side=tk.TOP, padx=5, pady=10)
rating_label = tk.Label(rating_frame, text='rating')
rating_label.pack(side=tk.LEFT)
rating_entry = tk.Entry(rating_frame)
rating_entry.pack(side=tk.LEFT)

begin_frame = tk.Frame(window)
begin_frame.pack(side=tk.TOP, padx=5, pady=10)
begin_label = tk.Label(begin_frame, text='business_time')
begin_label.pack(side=tk.LEFT)
begin_entry = tk.Entry(begin_frame)
begin_entry.pack(side=tk.LEFT)

closed_frame = tk.Frame(window)
closed_frame.pack(side=tk.TOP, padx=5, pady=10)
closed_label = tk.Label(closed_frame, text='closed_time')
closed_label.pack(side=tk.LEFT)
closed_entry = tk.Entry(closed_frame)
closed_entry.pack(side=tk.LEFT)

price_frame = tk.Frame(window)
price_frame.pack(side=tk.TOP, padx=5, pady=10)
price_label = tk.Label(price_frame, text='price')
price_label.pack(side=tk.LEFT)
price_entry = tk.Entry(price_frame)
price_entry.pack(side=tk.LEFT)

tk.Label(window, text='0:$0-$100  1:$100-$300').pack()
tk.Label(window, text='2:$300-$500  3:$500up').pack()

button = tk.Button(window, text='insert', command=event).pack(padx=5, pady=10)

window.mainloop()

fo.close()
