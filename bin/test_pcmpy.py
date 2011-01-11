import PCM_Python as pcmpy
import sys

if len(sys.argv) < 2: 
   print 'Please provide a file as input'
else:
   f = pcmpy.PCMfilecreate()
   status = pcmpy.PCMfileopen(f, sys.argv[1])
   if status == 0:  
      pcmpy.PCMfilestat(f)
   else:
      print 'Error code: ' + str(status)
   pcmpy.PCMfilefree(f)
