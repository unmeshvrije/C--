'''
import speech_recognition as sr
from pydub import AudioSegment
import sys

src = sys.argv[1]
sound = AudioSegment.from_mp3(src)
sound.export("temp.wav", format="wav")

file_audio = sr.AudioFile("temp.wav")

r = sr.Recognizer()
with file_audio as source:
  audio_text = r.record(source)

print(type(audio_text))
result = r.recognize_google(audio_text)
print("*" * 80)
print(result)
'''
import sys
import pvleopard

src = sys.argv[1]
leopard = pvleopard.create(access_key="+J1xM8pbtMN1Rc0cpPnkUHGRjEBpbIX1ax0wGCR66ONYAO5y9SPGfA==")

transcript, words = leopard.process_file(src)

print(transcript)
print("*" * 80)
print(words)
