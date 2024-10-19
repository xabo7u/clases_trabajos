from Crypto.Cipher import ChaCha20
from Crypto.Util import Counter

# PARTE 1: Cifrado
plaintext = b'Este es un mensaje secreto que quiero cifrar.'
key = b'z\xe8~"\xcayW\x14g\x18+\x1c+\xf9\x80\x06P\x9ej\x888\xb4G\xdf\xe4\xc50,\x8dY\x80\x19'
nonce = b'\xd6\x7f6\xc7\xe8i*\xa4'

chacha20 = ChaCha20.new(key=key, nonce=nonce)
ciphertext = chacha20.encrypt(plaintext)
print("Texto cifrado:", ciphertext)

# PARTE 3: Descifrado de texto cifrado conocido
texttodecrypt = b'Ehq0\x83\xcb\x8fo\xab\xed\xd0S\x06\xcc\xbb\xecw\xe9\xec(\x1f\xc5E\xdb\x88\x18`W\xc3yQn\xad3\xec.\x08\x92\x8d\x8e\xbb%\x8f\x1a\xa6\xc9=\x15\x0f5\xaa'
chaCha20 = ChaCha20.new(key=key, nonce=nonce)
decrypted_text = chaCha20.decrypt(texttodecrypt)
print("Texto descifrado:", decrypted_text.decode('utf-8', errors='ignore'))

# PARTE 4: Descifrado de texto cifrado alterado
texttorepair = b"\xad\xe2\x9a[C\xca\xa9\xadn\xf9\xaa)\x13\xc2X\x9e\x89\x19`C\xc4n\x1em\xf8?\xe7|\x0b\xd3\xdc\x8f\xacd\x85\x0c\xb8\xc3'\x1a\x12>"
initial_value = 0
counter = Counter.new(64, prefix=nonce, initial_value=initial_value)
cipher_repair = ChaCha20.new(key=key, nonce=nonce)

# Descifrar el texto alterado
textrepair = cipher_repair.decrypt(texttorepair)
print("Texto reparado:", textrepair.decode('utf-8', errors='ignore'))
