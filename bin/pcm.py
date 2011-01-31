import PCM_Python as _pcm

def get_version():
        """Returns a string specifying the version of PCM."""
        return _pcm.PCMversion()


class File(object):
    def __init__(self):
        self.f = _pcm.PCMfilecreate()
        self.load = False

    def __del__(self):
        _pcm.PCMfilefree(self.f)
        self.load = False;

    def read(self, filename):
        if self.load:
            _pcm.PCMfilefree(self.f)
            self.f = _pcm.PCMfilecreate()
            self.status = _pcm.PCMfileopen(self.f, filename)
        else:
            self.status = _pcm.PCMfileopen(self.f, filename)
        self.load = True

    def stat(self):
        if self.load and self.status == 0:
            _pcm.PCMfilestat(self.f)
        else:
            print 'Please load file by load method first'


class Intarray(object):
    def __init__(self,name):
        self.intarray = _pcm.PCMarraynew(name)
        self.sortalg = _pcm.PCMALGSORTQUICK

    def __del__(self):
        _pcm.PCMarrayfree(self.intarray)

    def append(self, a):
        """Append python list a to pcm Intarray."""
        l = len(a)
        arr = _pcm.intArray(l)
        for i in range(l):
            arr[i] = a[i]
        _pcm.PCMarraycopy(self.intarray, arr, l)

    def set_sortalg(self, alg):
        """set pcm.Intarray sort algorithm."""
        if   alg == 1:
            self.sortalg = _pcm.PCMALGSORTINSERT
        elif alg == 2:
            self.sortalg = _pcm.PCMALGSORTSELECT
        elif alg == 3:
            self.sortalg = _pcm.PCMALGSORTBUBBLE
        elif alg == 4:
            self.sortalg = _pcm.PCMALGSORTSHELL
        elif alg == 0:
            self.sortalg = _pcm.PCMALGSORTQUICK

    def output(self):
        """print pcm Intarray."""
        _pcm.PCMarrayoutput(self.intarray)

    def sort(self):
        """sort pcm Intarray."""
        _pcm.PCMarraysort(self.intarray, _pcm.PCMarraylen(self.intarray), self.sortalg)
        #_pcm.PCMarrayoutput(self.intarray)
