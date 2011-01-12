import PCM_Python as pcmpy

a = pcmpy.PCMarrayinit()
b = pcmpy.PCMarrayinit()
pcmpy.PCMarrayinsert(a,0,1)
pcmpy.PCMarrayinsert(a,0,5)
pcmpy.PCMarrayinsert(a,0,3)
pcmpy.PCMarrayinsert(a,0,2)
pcmpy.PCMarrayinsert(b,0,3)
pcmpy.PCMarrayinsert(b,0,2)
#pcmpy.PCMarraymerge(a,b)
pcmpy.PCMarrayoutput(a)
pcmpy.PCMarraysort(a,3,pcmpy.PCMALGSORTBUBBLE)
status, e = pcmpy.PCMarrayfind(a,4,5,pcmpy.PCMALGORIGINFIND)
print e
pcmpy.PCMarrayoutput(a)
status, e = pcmpy.PCMarraydelete(a,0)
print str(e)+' was deleted'
pcmpy.PCMarrayoutput(a)
pcmpy.PCMarraydeleteR(a)
pcmpy.PCMarrayoutput(a)
pcmpy.PCMarrayfree(a)
pcmpy.PCMarrayfree(b)
