LETTERS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

def isKeyValid(key):
    if sorted(key) != sorted(LETTERS):
        return False
    return True

def encryptMessage(key, message):
    return translateMessage(key, message, 'encrypt')

def translateMessage(key, message, mode):
    translated = ''
    charsA = LETTERS
    charsB = key
    if mode == 'decrypt':
        charsA, charsB = charsB, charsA

    for symbol in message:
        if symbol.upper() in charsA:
            symIdx = charsA.find(symbol.upper())
            if symbol.isupper():
                translated += charsB[symIdx].upper()
            else:
                translated += charsB[symIdx].lower()
        else:
            translated += symbol
    return translated

def printString(S):
	plaintext = [None] * 5
	freq = [0] * 26
	freqSorted = [None] * 26
	used = [0] * 26
	for i in range(len(S)):
		if S[i] != ' ':
			freq[ord(S[i]) - 65] += 1	
	for i in range(26):
		freqSorted[i] = freq[i]
	T = "ETAOINSHRDLCUMWFGYPBVKJXQZ"
	freqSorted.sort(reverse = True)
	for i in range(5):
		ch = -1
		for j in range(26):
			if freqSorted[i] == freq[j] and used[j] == 0:
				used[j] = 1
				ch = j
				break
			
		if ch == -1:
			break
		x = ord(T[i]) - 65
		x = x - ch
		curr = ""
		for k in range(len(S)):
			if S[k] == ' ':
				curr += " "
				continue
			y = ord(S[k]) - 65
			y += x
			
			if y < 0:
				y += 26
			if y > 25:
				y -= 26	
			curr += chr(y + 65)			
		plaintext[i] = curr
	return plaintext

myMessage = input("Enter the message: ")
myKey = input("Enter the key: ")
if not isKeyValid(myKey):
    print('There is an error in the key.')
else:
    ct = encryptMessage(myKey, myMessage)
    print("Cipher text:", ct)
    print("Plain texts after breaking the cipher:", printString(ct))