import pcm
import time
import random

def pcmsort(n):
    a=range(n,1,-1)
    random.shuffle(a)
    arr=pcm.Intarray('arr1')
    arr.append(a)

    for i in [0, 4]:
        arr=pcm.Intarray(str(i))
        arr.append(a)
        #arr.output()
        arr.set_sortalg(i)
        start = time.clock()
        arr.sort()
        #arr.output()
        end = time.clock()
        print 'time: '+ str(end-start) + 's'
    start = time.clock()
    a.sort()
    end = time.clock()
    print 'python build-in sort:'
    print 'time: '+ str(end-start) + 's'

#pcmsort(100)
#pcmsort(1000)
pcmsort(10000)
#pcmsort(10000000)

