import pyautogui

class Mouse():
    def __init__(self):
        pass

    def current_pos(self):
        x, y = pyautogui.position()
        return x, y
    
    def screen_size(self):
        screen_width, screen_height = pyautogui.size()
        return screen_width, screen_height

    def control(self, signal):
        xcor, ycor, func = signal.split("/")
        try:
            xcor, ycor, func = int(xcor), int(ycor), int(func)
        except:
            print("Data is not integer")

        if func == 0: # Do nothing
            pass
        elif func == 1: # Left click
            pyautogui.click()
        elif func == 2: # Right click
            pyautogui.rightClick()
        elif func == 3: # Voice recognition
            pass

        pyautogui.moveTo(xcor, ycor)

if __name__ == "__main__":
    mouse = Mouse()
    print("Kích thước màn hình:", mouse.screen_size())
    a, b, c = mouse.control("xcor/ycor/func")
    print(a, b, c, type(a), type(b), type(c))