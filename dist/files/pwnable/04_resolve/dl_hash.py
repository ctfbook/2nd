from functools import reduce
import re

dl_new_hash = lambda s : reduce(lambda h,c: h*33+c, [5381]+list(map(ord, s))) & ((1<<32)-1)
gdb_xs = lambda name : re.findall(r'"(.*)"', gdb.execute('x/s {}'.format(name), to_string=True))[0]
gdb_p = lambda name : int(re.findall(r' ([0-9a-fx]+)', gdb.execute('p {}'.format(name), to_string=True))[0], 0)