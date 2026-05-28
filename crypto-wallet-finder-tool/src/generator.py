import os
from Crypto.PublicKey import RSA
from Crypto.Hash import SHA256

class WalletGenerator:
    def __init__(self):
        self.key = None
        self.address = None

    def generate(self):
        self.key = RSA.generate(2048)
        pub_key_bytes = self.key.publickey().export_key('DER')
        hash_obj = SHA256.new(pub_key_bytes)
        self.address = hash_obj.hexdigest()[:40]
        return self.address

    def get_private_key_pem(self):
        if self.key:
            return self.key.export_key('PEM').decode()
        return None