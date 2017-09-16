from Tkinter import *
import os

# Set number of rows and columns
ROWS = 10
COLS = 10

# Create a grid of None to store the references to the tiles
tiles = [[None for _ in range(COLS)] for _ in range(ROWS)]

result = [[0 for x in range(COLS)] for y in range(ROWS)]

def callback(event):
    # Get rectangle diameters
    col_width = c.winfo_width()/COLS
    row_height = c.winfo_height()/ROWS
    # Calculate column and row number
    col = event.x//col_width
    row = event.y//row_height
    # If the tile is not filled, create a rectangle
    if not tiles[row][col]:
        tiles[row][col] = c.create_rectangle(col*col_width, row*row_height, (col+1)*col_width, (row+1)*row_height, fill="black")
    # If the tile is filled, delete the rectangle and clear the reference
    else:
        c.delete(tiles[row][col])
        tiles[row][col] = None

def save():
	text = ''
	for x in range(COLS):
		for y in range(ROWS):
			if tiles[x][y] == None:
				result[x][y] = 0
			else:
				result[x][y] = 1
			text += str(result[x][y]) + ','
	with open('output.txt', 'a') as f:
		f.truncate()
		f.write(text)
		f.seek(-1, os.SEEK_END)
		f.truncate()

# Create the window, a canvas and the mouse click event binding
root = Tk()
c = Canvas(root, width=500, height=500, borderwidth=5, background='white')
c.pack()
c.bind("<Button-1>", callback)

b = Button(root, text='Submit', command=save)
b.pack()

mainloop()