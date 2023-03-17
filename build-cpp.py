import re
import os
import shutil

if not os.path.exists('CMakeLists.txt'):
    print('CMakeLists.txt not found')
    exit(-1)

if not os.path.exists('build'):
    os.mkdir('build')

os.chdir('build')
os.system('cmake ..')
os.system('cmake --build .')

exe_path = []


def find_exe(dir_path, max_depth):
    global exe_path
    if max_depth <= 0:
        return
    sub = os.listdir(dir_path)
    for e in sub:
        sub_path = os.path.join(dir_path, e)
        if os.path.isfile(sub_path) and re.match('.*\\.(exe|dll)$', e):
            exe_path.append(sub_path)
        if os.path.isdir(sub_path):
            find_exe(sub_path, max_depth - 1)


os.chdir('../')
find_exe('./build', 2)

for ee in exe_path:
    print('executable file found at ' + ee)
    file_name = re.match('.*[/\\\\]([\\w.]+)$', ee)[1]
    shutil.copyfile(ee, './' + file_name)
