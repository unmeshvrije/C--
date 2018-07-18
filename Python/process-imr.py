import sys

inputFile = sys.argv[1]

rows =  [[] for i in range(3525)]
with open(inputFile, 'r') as fin:
    lines = fin.readlines()
    del(lines[0])
    for i,line in enumerate(lines):
        fields = line.split() # split the line based on white spaces
        rows[i%3525].append(fields[2])

data = ""
for row in rows:
    numColumns = len(row)
    for i,col in enumerate(row):
        data += col
        if i != numColumns-1:
            data += ","
    data += "\n"

outFile = inputFile + ".csv"
with open(outFile, 'w') as fout:
    fout.write(data)
