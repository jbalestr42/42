import sys
import os
i = 5
if len(sys.argv) != 1:i=i-1
f = open('Sully_' + str(i) + '.py', 'w+')
s = r"import sys%cimport os%ci = %d%cif len(sys.argv) != 1:i=i-1%cf = open('Sully_' + str(i) + '.py', 'w+')%cs = r%c%s%c%cf.write(s %% (10, 10, i, 10, 10, 10, 34, s, 34, 10, 10, 10, 10))%cf.close()%cif i > 0:os.system('python Sully_' + str(i) + '.py 4')%c"
f.write(s % (10, 10, i, 10, 10, 10, 34, s, 34, 10, 10, 10, 10))
f.close()
if i > 0:os.system('python Sully_' + str(i) + '.py 4')
