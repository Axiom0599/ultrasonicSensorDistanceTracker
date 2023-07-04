import serial
from tkinter import *
import tkinter as tk

window = tk.Tk()
window.geometry("500x500")


ser = serial.Serial('/dev/cu.usbserial-1420',9600)

data =[]                       # empty list to store the data
for i in range(5):
    b = ser.readline()         # read a byte string
    string_n = b.decode()  # decode byte string into Unicode
    string = string_n.rstrip() # remove \n and \r
    flt = float(string)        # convert string to float
    print(flt)
    data.append(string)


for line in data:
    print(line)
    greeting = tk.Label(text=str(line))
    greeting.pack()


button1 = tk.Button(window, text="Quit", command=window.destroy)
ser.close()


window.mainloop()