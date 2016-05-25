
import csv
def format_csv(list):
  out = open("/home/unmesh/Downloads/out.csv", "wb")
  writer = csv.writer(out, delimiter=',')

  with open(list[1], 'rb') as csvfile:
      for row in csvfile.readlines():
        #print row
        #new_row = row
        columns = row.split(',')
        full_name = columns[2]
        names = full_name.split(' ')
        last_name = names[-1]

        last_name_first = last_name
        print last_name + ":"
        l = len(names)
        for i in range (0,l-1):
          last_name_first += " "
          last_name_first += names[i]
          print names[i]

        print last_name_first
        new_row = columns[0] + ","+ columns[1] +"," + last_name_first
        
        for i in range (3,10):
          new_row += "," + columns[i]

        print new_row
        writer.writerow([new_row])
        



if __name__ == "__main__":
	import sys
	format_csv(list(sys.argv))
