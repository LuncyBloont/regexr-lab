
local fr = io.open('0.txt', 'r')
local text = fr:read('*a')
fr:close()

local reg = io.read()

local newStr, _ = text:gsub(reg, '\x1b[30;43m%0\x1b[0m')

print(newStr)
