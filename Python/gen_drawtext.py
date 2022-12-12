import sys

subs = sys.argv[1]

with open(subs, "r") as fin:
  lines = fin.readlines()
  for nr, line in enumerate(lines):
    elements = line.split(',')
    text = elements[0]
    start = elements[1]
    end = elements[2].strip()
    if nr % 2 == 0:
      print(f".drawtext('{text}', fontsize=64, enable='between(t,{start},{end})', x=10, y=10)\\")
    else:
      print(f".drawtext('{text}', fontsize=48, fontcolor='Navy', enable='between(t,{start},{end})', x=10, y=125)\\")

