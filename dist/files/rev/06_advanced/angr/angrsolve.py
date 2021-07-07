import angr
import claripy

# プロジェクトの作成
p = angr.Project("./program", load_options={"auto_load_libs": False})
# 10バイトの入力codeを作成
code = claripy.BVS("code", 8 * 10)
# 初期状態を通常実行の最初の状態とする
state = p.factory.entry_state(stdin=code) # 標準入力をcodeとする
simgr = p.factory.simulation_manager(state)

# 解を探索する
simgr.explore(find=0x4006f9, avoid=0x400707)
try:
    found = simgr.found[0]
    # 0x4006f9に到達できるような入力codeを表示
    print(found.solver.eval(code, cast_to=bytes))
except IndexError:
    print("Not Found")
