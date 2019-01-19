import hashlib

#set test variables (string to be hashed, salt, magic, expected output)
toHash = 'abcdef'
salt = 'hfT7jp2q'
magic = '$1$'
expected = '$1$hfT7jp2q$wIKxYDJceIIfXtiOOFSur0'
result = "thisResult"
firstChar = toHash[0]

#compute altsum
altSum = hashlib.md5(toHash+salt+toHash) 
print('altSum value: ' + altSum.hexdigest())

#compute intermediate = hash(password+magic+salt + the first length(password) btyes of alternate sum + for each bit in length(password) from low to high if bit==1 append NUL else append first byte of pwd)
lengthAltSum = altSum.digest_size

intermediate_zero = toHash+magic+salt+str(altSum)[:6]
bitRepPwdLen = '{0:03b}'.format(6)
print(bitRepPwdLen)
for x in bitRepPwdLen:
  if x == '1':
    intermediate_zero = intermediate_zero + '\0'
  else:
    intermediate_zero = intermediate_zero + firstChar
print([intermediate_zero])
temp = hashlib.md5(intermediate_zero)
print('intermediate_zero: '+ temp.hexdigest())

#check if correct
#if result != expected:
 # print('ERROR PASSWORD HASHED WRONG.\nexpected: ' + expected + '\ngot: ' + result)
#else:
  #print('HASH SUCCESSFUL.\nexpected: ' + expected + '\nreceived: ' + result)
