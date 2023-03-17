import re

with open('0.txt', 'r', encoding='utf-8') as f:
    raw = f.read()
    rep = input()
    rei = re.compile(rep)
    post = rei.sub('\x1b[30;43m\\g<0>\x1b[0m', raw)
    print(post)
