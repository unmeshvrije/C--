# importing the module
from pytube import YouTube
import sys

# where to save
# SAVE_PATH = "~/Documents/" #to_do

# link of the video to be downloaded
link=sys.argv[1] # "https://www.youtube.com/watch?v=xWOoBJUqlbI"

try:
	# object creation using YouTube
	# which was imported in the beginning
	yt = YouTube(link)
except:
	print("Connection Error") #to handle exception

try:
    yt.streams.filter(progressive=True, file_extension='mp4').order_by('resolution').desc().first().download()
except Exception as e:
  print(f"Error {e}")
print('Downloaded!')

