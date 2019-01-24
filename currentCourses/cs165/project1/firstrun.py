import hashlib
import binascii

#NOTE: Had a weird encoding error with hashing so using binary literals instead of strings

# Takes binary strings and spits out b([hex output])
def printHex( toHex ):
    print( binascii.hexlify(toHex) )
    return

#set test variables (string to be hashed, salt, magic, expected output)
toHash = b'abcdef'
salt = b'hfT7jp2q'
magic = b'$1$'
expected = '$1$hfT7jp2q$wIKxYDJceIIfXtiOOFSur0'
result = "thisResult"
firstChar = bytes(chr(toHash[0]),"utf8")

#print pw+magic+salt (for testing)
#toCheck = toHash+magic+salt
#printHex(toCheck)


#compute altsum
#altSum = hashlib.md5(toHash+salt+toHash) 
altSum = hashlib.md5(toHash+salt+toHash)
#printHex(altSum.digest())
#printHex(altSum.digest()[:6])

#compute intermediate = hash(password+magic+salt + the first length(password) btyes of alternate sum + for each bit in length(password) from low to high if bit==1 append NUL else append first byte of pwd)

#intermediate_zero with the first btyes of altsum (depends on the length of password... if len == 6 grab first 6 bytes)
intermediate_zero = toHash+magic+salt+altSum.digest()[:6] #TODO: grab length of password
bitRep = '{0:03b}'.format(6) #TODO: bitrep needs to be updated for variable password lengths
#print(bitRep)
for x in range(len(bitRep)):
  if bitRep[len(bitRep) - x - 1] == '1':
    intermediate_zero = intermediate_zero + b'\0'
  else:
    intermediate_zero = intermediate_zero + firstChar
printHex(intermediate_zero)
temp = hashlib.md5(intermediate_zero).digest()
printHex(temp)

#hash 1000 times by concatenating and hashing arbitrary values
for i in range(1000):
    if (i%2) == 0: # if i is even intermediate i, intermediate i
      temp = temp + temp
      temp = hashlib.md5(temp).digest()
    if (i%2) != 0:
      temp = temp + toHash
      temp = hashlib.md5(temp).digest()
    if (i%3) != 0:
      temp = temp + salt
      temp = hashlib.md5(temp).digest()
    if (i%7) != 0:
      temp = temp + toHash
      temp = hashlib.md5(temp).digest()
    if (i%2) == 0:
      temp = temp + toHash
      temp = hashlib.md5(temp).digest()
    if (i%2) != 0:
      temp = temp + temp
      temp = hashlib.md5(temp).digest()

printHex(temp)

#check if correct
#if result != expected:
 # print('ERROR PASSWORD HASHED WRONG.\nexpected: ' + expected + '\ngot: ' + result)
#else:
  #print('HASH SUCCESSFUL.\nexpected: ' + expected + '\nreceived: ' + result)
