import PCM_Python as pcmpy
f = pcmpy.PCMfilecreate()
pcmpy.PCMfileopen(f,'IM.lp')
pcmpy.PCMfilestat(f)
pcmpy.PCMfilefree(f)
