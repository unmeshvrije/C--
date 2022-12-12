import ffmpeg
import sys

filename = sys.argv[1]
# audio_filename = sys.argv[2]


full_clip = ffmpeg.input(filename)
# bg_music = ffmpeg.input(audio_filename).audio

audio = full_clip.audio
video = full_clip.video
print(dir(audio))

video.drawtext('Ik zal voor je duimen', fontsize=64, enable='between(t,5,9)', x=10, y=10)\
.drawtext('Ik', fontsize=64, enable='between(t,15,17)', x=10, y=10)\
.drawtext('I', fontsize=48, fontcolor='Navy',enable='between(t,15,17)', x=10, y=125)\
.drawtext('zal', fontsize=64, enable='between(t,18,21)', x=10, y=10)\
.drawtext('will / shall', fontsize=48, fontcolor='Navy', enable='between(t,18,21)', x=10, y=125)\
.drawtext('voor', fontsize=64, enable='between(t,22,23.5)', x=10, y=10)\
.drawtext('for', fontsize=48, fontcolor='Navy', enable='between(t,22,23.5)', x=10, y=125)\
.drawtext('je', fontsize=64, enable='between(t,24,26)', x=10, y=10)\
.drawtext('you', fontsize=48, fontcolor='Navy', enable='between(t,24,26)', x=10, y=125)\
.drawtext('duimen', fontsize=64, enable='between(t,27,29)', x=10, y=10)\
.drawtext('to cross fingers', fontsize=48, fontcolor='Navy', enable='between(t,27,29)', x=10, y=125)\
.drawtext('duim', fontsize=64, enable='between(t,30,33)', x=10, y=10)\
.drawtext('thumb', fontsize=48, fontcolor='Navy', enable='between(t,30,33)', x=10, y=125)\
.drawtext('Ik zal', fontsize=64, enable='between(t,59,70)', x=10, y=10)\
.drawtext('[ ... ]', fontsize=64, enable='between(t,59,70)', x=280, y=10)\
.drawtext('duimen', fontsize=64, enable='between(t,65,70)', x=550, y=10)\
.drawtext('Ik zal schrijven', fontsize=64, enable='between(t,75,78)', x=10, y=10)\
.drawtext('I will write', fontsize=48, fontcolor='Navy', enable='between(t,75,78)', x=10, y=125)\
.drawtext('Ik zal voor je schrijven', fontsize=64, enable='between(t,81,84)', x=10, y=10)\
.drawtext('I will write for you', fontsize=48, fontcolor='Navy', enable='between(t,81,84)', x=10, y=125)\
.drawtext('Ik zal voor je duimen', fontsize=64, enable='between(t,117,127)', x=10, y=10)\
.drawtext('I will keep my fingers crossed', fontcolor='Navy',fontsize=48, enable='between(t,117,127)', x=10, y=125)\
.output(audio, "./out.mp4")\
# .output(audio, bg_music, "./out.mp4")\
.run(overwrite_output=True)
