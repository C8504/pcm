import PCM_Python
f = PCM_Python.PCMfilecreate()
PCM_Python.PCMfileopen(f,'IM.lp')
PCM_Python.PCMfilestat(f)
PCM_Python.PCMfilefree(f)
