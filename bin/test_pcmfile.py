import PCM_Python as pcmpy
import sys

if len(sys.argv) < 2: 
   print 'Please provide a file as input'
else:
   f = pcmpy.PCMfilecreate()
   status = pcmpy.PCMfileopen(f, sys.argv[1])
   if status == 0:  
      pcmpy.PCMfilestat(f)
      print 'Get the first line of '+ sys.argv[1] + ':'
      status, maxline, length=pcmpy.PCMfilegetline(f,256)
      print 'The line is:' + maxline
      print 'The length is ' + str(length)
      print ''
      print 'Get the max line of '+ sys.argv[1] + ':'
      status, maxline, length=pcmpy.PCMfilegetmaxline(f)
      print 'The line is:' + maxline
      print 'The length is ' + str(length)

   else:
      print 'Error code: ' + str(status)
   pcmpy.PCMfilefree(f)
