from tkinter import *
import serial

root = Tk()
canvas = Canvas(root,width=800,height=600,background='white')
flag = True
x1,y1,x2,y2=-1,-1,0,0
n1,m1=0,0
obj = serial.Serial("COM4",9600,timeout=0.1) #set the COM on which bluetooth is connectedu

moveflag = True
yy2=0


def creategraph():
    for x in range(100,1000,100):
        canvas.create_line(x,0,x,800,width=2)
    for y in range(100,1000,100):
        canvas.create_line(0,y,800,y,width=2)
          
  
    

def callback(event):
    global flag,x1,y1,x2,y2,n1,m1
    if x1 ==-1 and y1==-1:
        x1,y1 =event.x,event.y
        print(x1,y1)
    else:
        x2,y2 = event.x,event.y
        print(x2,y2)
        canvas.create_line(x1,y1,x2,y2,width=2,fill='red')
        n1,m1=x1,y1
    
        x1,y1=x2,y2
        

def movecommand(event):
    global y2,y1,obj,n1,m1,yy2
    print('double click')
    if  yy2==y2:
        return
    else:
        yy2 = y2

    
    angle = np.rad2deg(np.arctan2(y2 - m1, x2 - n1))
    print(angle)

    distance =y2-m1
    print(distance)
    distance = str(distance)
    forward ='1'
    data =angle+','+forward+','+distance
    print(data.encode())
    obj.write(data.encode())
    
    
    d1 = obj.read()
    print(d1)
     
    
creategraph()  

canvas.bind("<Button-3>", callback)
canvas.bind('<Double-Button-1>',movecommand)
canvas.pack()

root.mainloop()
