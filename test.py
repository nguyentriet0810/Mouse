import serial
import win32api 

def save_data():
    global xcor  # Declare xcor as global
    global ycor
    global click
    
    while True:
        
        try:
            data = ser.readline().decode('utf-8').strip()
            try:
                xcor, ycor, click = data.split("/")
                xcor, ycor, click = int(xcor), int(ycor), int(click)
                win32api.SetCursorPos((xcor, ycor))
            except:
                pass
            
            print(data, xcor, ycor, click)
        except UnicodeDecodeError:
            pass

if __name__ == '__main__':
    ser = serial.Serial('COM17', 115200, timeout=0.1)   
    xcor, ycor, click = 0, 0, 0
    save_data()
