#!/usr/bin/env python3
import sys
import re

def patch(target, diff, rollback=False):
    for line in diff.split('\n'):
        r = re.findall(r'([0-9A-Fa-f]+): ([0-9A-Fa-f]{2}) ([0-9A-Fa-f]{2})',
                       line)
        if len(r) == 1:
            offset, before, after = map(
                lambda x: int(x, 16), r[0]
            )
            if rollback:
                assert target[offset] == after
                target = target[:offset] + bytes([before]) + target[offset+1:]
            else:
                assert target[offset] == before
                target = target[:offset] + bytes([after]) + target[offset+1:]

    return target

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print("Usage: {} binary diff [restore]".format(sys.argv[0]))
        sys.exit(1)

    else:
        # 変更対象のファイルを開く
        try:
            with open(sys.argv[1], "rb") as f:
                target = f.read()
        except:
            print("[-] {}: No such file".format(sys.argv[1]))
            sys.exit(1)
        # DIFファイルを開く
        try:
            with open(sys.argv[2], "r") as f:
                diff = f.read()
        except:
            print("[-] {}: No such file".format(sys.argv[1]))
            sys.exit(1)

        try:
            if len(sys.argv) >= 4 and sys.argv[3] == "restore":
                # 変更を元に戻す
                target = patch(target, diff, True)
                print("[+] patch: Successfully restored")
            else:
                # 変更を適用する
                target = patch(target, diff, False)
                print("[+] patch: Successfully modified")
        except AssertionError:
            print("[-] Patch is not written for this binary")
            sys.exit(1)

        with open(sys.argv[1], "wb") as f:
            f.write(target)
